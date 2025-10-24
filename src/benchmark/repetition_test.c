#include "platform_timing.c"

#include <fcntl.h>
#include <unistd.h>

typedef enum Repetition_Tester_Mode
{
  REPTEST_MODE_UNINITIALIZED,

  REPTEST_MODE_TESTING,
  REPTEST_MODE_COMPLETE,
  REPTEST_MODE_ERROR,

  REPTEST_MODE_COUNT,
} Repetition_Tester_Mode;

typedef enum Repetition_Test_Value
{
  REPTEST_VALUE_NONE,

  REPTEST_VALUE_TIME,
  REPTEST_VALUE_PAGE_FAULTS,
  REPTEST_VALUE_BYTE_COUNT,

  REPTEST_VALUE_COUNT,
} Repetition_Test_Value;

typedef struct Repetition_Test_Values Repetition_Test_Values;
struct Repetition_Test_Values
{
  u64 v[REPTEST_VALUE_COUNT];
};

typedef struct Repetition_Test Repetition_Test;
struct Repetition_Test
{
  Repetition_Test_Values accum;
  u32 begin_block_count;
  u32 close_block_count;
};

typedef struct Repetition_Tester_Results Repetition_Tester_Results;
struct Repetition_Tester_Results
{
  u64 test_count;
  Repetition_Test_Values min;
  Repetition_Test_Values max;
  Repetition_Test_Values total;
};

typedef struct Repetition_Tester Repetition_Tester;
struct Repetition_Tester
{
  u64 target_processed_byte_count;
  u64 cpu_timer_frequency;
  u64 try_for_min_time;
  u64 tests_start_time;

  Repetition_Tester_Mode mode;

  Repetition_Test current_test;
  Repetition_Tester_Results results;
};

static
void repetition_tester_begin_time(Repetition_Tester *tester)
{
  Repetition_Test *curr = &tester->current_test;
  curr->begin_block_count += 1;
  curr->accum.v[REPTEST_VALUE_TIME] -= read_cpu_timer();
  curr->accum.v[REPTEST_VALUE_PAGE_FAULTS]  -= read_os_page_faults();
}

static
void repetition_tester_close_time(Repetition_Tester *tester)
{
  Repetition_Test *curr = &tester->current_test;
  curr->accum.v[REPTEST_VALUE_TIME] += read_cpu_timer();
  curr->accum.v[REPTEST_VALUE_PAGE_FAULTS] += read_os_page_faults();
  curr->close_block_count += 1;
}

static
void repetition_tester_count_bytes(Repetition_Tester *tester, u64 bytes)
{
  Repetition_Test *curr = &tester->current_test;
  curr->accum.v[REPTEST_VALUE_BYTE_COUNT] += bytes;
}

static
void repetition_tester_error(Repetition_Tester *tester, const char *message)
{
  LOG_ERROR("%s", message);
  tester->mode = REPTEST_MODE_ERROR;
}

static
void print_repetition_test_values(const char *label, Repetition_Test_Values values, u64 cpu_timer_frequency, u64 test_count)
{
  u64 divisor = test_count ? test_count : 1;

  u64 time = values.v[REPTEST_VALUE_TIME] / divisor;
  printf("%s: %lu", label, time);
  if (cpu_timer_frequency)
  {
    f64 seconds = cpu_time_in_seconds(time, cpu_timer_frequency);
    printf(" (%.4fms)", 1000.0 * seconds);

    u64 byte_count = values.v[REPTEST_VALUE_BYTE_COUNT] / divisor;
    if (byte_count)
    {
      f64 gb_per_s = (f64)byte_count / (f64)GB(1) / seconds;

      printf(" %.4f GB/s", gb_per_s);
    }

    u64 page_faults = values.v[REPTEST_VALUE_PAGE_FAULTS] / divisor;
    if (page_faults)
    {
      f64 kb_per_fault = ((f64)byte_count / KB(1)) / (f64)page_faults;

      printf(", %lu faults (%.4f kb/fault)", page_faults, kb_per_fault);
    }
  }
}

static
void repetition_tester_new_wave(Repetition_Tester *tester, u64 target_processed_byte_count, u64 cpu_timer_frequency, u32 seconds_to_try_for_min)
{
  if (tester->mode == REPTEST_MODE_UNINITIALIZED)
  {
    tester->mode = REPTEST_MODE_TESTING;
    tester->target_processed_byte_count = target_processed_byte_count;
    tester->cpu_timer_frequency = cpu_timer_frequency;
    tester->results.min.v[REPTEST_VALUE_TIME] = (u64)-1;
  }
  else if (tester->mode == REPTEST_MODE_COMPLETE)
  {
    tester->mode = REPTEST_MODE_TESTING;

    if (cpu_timer_frequency != tester->cpu_timer_frequency)
    {
      repetition_tester_error(tester, "Repetition Tester CPU frequency has changed from previous wave");
    }

    if (target_processed_byte_count != tester->target_processed_byte_count)
    {
      repetition_tester_error(tester, "Repetition Tester target byte count has changed from previous wave");
    }
  }

  tester->try_for_min_time = seconds_to_try_for_min * cpu_timer_frequency;
  tester->tests_start_time = read_cpu_timer();
}

static
b32 repetition_tester_is_testing(Repetition_Tester *tester)
{
  if (tester->mode == REPTEST_MODE_TESTING)
  {
    u64 current_time = read_cpu_timer();

    Repetition_Test curr = tester->current_test;

    // Only tests that have timing blocks get counted
    if (curr.begin_block_count)
    {
      if (curr.close_block_count != curr.begin_block_count)
      {
        repetition_tester_error(tester, "Tester has uneven timing blocks");
      }
      if (curr.accum.v[REPTEST_VALUE_BYTE_COUNT] != tester->target_processed_byte_count)
      {
        repetition_tester_error(tester, "Tester has mismatched target and actual bytes processed");
      }

      if (tester->mode == REPTEST_MODE_TESTING) // We are all good no errors from previous checks
      {
        Repetition_Tester_Results *results = &tester->results;
        results->test_count += 1;

        for (usize i = 0; i < STATIC_ARRAY_COUNT(results->total.v); i++)
        {
          results->total.v[i] += curr.accum.v[i];
        }

        if (curr.accum.v[REPTEST_VALUE_TIME] > results->max.v[REPTEST_VALUE_TIME])
        {
          results->max = curr.accum;
        }

        // Have some special stuff to do if we find a new min
        if (curr.accum.v[REPTEST_VALUE_TIME] < results->min.v[REPTEST_VALUE_TIME])
        {
          results->min = curr.accum;

          // Restart time to find new min
          tester->tests_start_time = current_time;

          printf("                                                                                        \r");
          print_repetition_test_values("MIN", results->min, tester->cpu_timer_frequency, 1);
          printf("\r");
          fflush(stdout);
        }

        // Reset
        tester->current_test = (Repetition_Test){0};

        // Now check if long enough time has passed without finding a new min
        if ((current_time - tester->tests_start_time) > tester->try_for_min_time)
        {
          tester->mode = REPTEST_MODE_COMPLETE;

          Repetition_Tester_Results *results = &tester->results;

          print_repetition_test_values("MIN", results->min, tester->cpu_timer_frequency, 1);
          printf("\n");

          print_repetition_test_values("MAX", results->max, tester->cpu_timer_frequency, 1);
          printf("\n");

          if (results->test_count)
          {
            printf("                                                          \r");
            fflush(stdout);
            print_repetition_test_values("AVG", results->total, tester->cpu_timer_frequency, results->test_count);
            printf("\n");
          }
        }
      }
    }
  }

  return tester->mode == REPTEST_MODE_TESTING;
}

// You provide the definitions for these
typedef struct Operation_Parameters Operation_Parameters;
typedef void Operation_Function(Repetition_Tester *tester, Operation_Parameters *params);

typedef struct Operation_Entry Operation_Entry;
struct Operation_Entry
{
  String name;
  Operation_Function *function;
};
