#define LOG_TITLE "REPETITION_TESTER"
#define COMMON_IMPLEMENTATION
#include "common.h"

#include "platform_timing.c"

#include <fcntl.h>
#include <unistd.h>

typedef struct Operation_Parameters Operation_Parameters;
struct Operation_Parameters
{
  String buffer;
  const char *file_name;
};

typedef enum Repetition_Tester_Mode
{
  REPTEST_MODE_UNINITIALIZED,
  REPTEST_MODE_TESTING,
  REPTEST_MODE_COMPLETE,
  REPTEST_MODE_ERROR,

} Repetition_Tester_Mode;

typedef struct Repetition_Tester_Results Repetition_Tester_Results;
struct Repetition_Tester_Results
{
  u64 test_count;
  u64 total_time;
  u64 max_time;
  u64 min_time;
};

typedef struct Repetition_Tester Repetition_Tester;
struct Repetition_Tester
{
  u64 target_processed_byte_count;
  u64 cpu_timer_frequency;
  u64 try_for_min_time;
  u64 tests_start_time;

  Repetition_Tester_Mode mode;
  u32 begin_block_count;
  u32 close_block_count;
  u64 curr_test_bytes_processed;
  u64 curr_test_time_elapsed;

  Repetition_Tester_Results results;
};

typedef void Operation_Function(Repetition_Tester *tester, Operation_Parameters *params);

static
void repetition_tester_begin_time(Repetition_Tester *tester)
{
  tester->begin_block_count += 1;
  tester->curr_test_time_elapsed -= read_cpu_timer();
}

static
void repetition_tester_close_time(Repetition_Tester *tester)
{
  tester->close_block_count += 1;
  tester->curr_test_time_elapsed += read_cpu_timer();
}

static
void repetition_tester_count_bytes(Repetition_Tester *tester, u64 bytes)
{
  tester->curr_test_bytes_processed += bytes;
}

static
void repetition_tester_error(Repetition_Tester *tester, const char *message)
{
  LOG_ERROR("%s", message);
  tester->mode = REPTEST_MODE_ERROR;
}

static
void print_repetition_test_time(const char *label, u64 cpu_time, u64 cpu_timer_frequency, u64 byte_count)
{
  printf("%s: %lu", label, cpu_time);
  if (cpu_timer_frequency)
  {
    f64 seconds = cpu_time_in_seconds(cpu_time, cpu_timer_frequency);
    printf(" (%fms)", 1000.0 * seconds);

    if (byte_count)
    {
      f64 gb_per_s = (f64)byte_count / (f64)GB(1) / seconds;

      printf(" %f GB/s", gb_per_s);
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
    tester->results.min_time = (u64)-1;
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
      repetition_tester_error(tester, "Repetition Tester CPU frequency has changed from previous wave");
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

    // Only tests that have timing blocks get counted
    if (tester->begin_block_count)
    {
      if (tester->close_block_count != tester->begin_block_count)
      {
        repetition_tester_error(tester, "Tester has uneven timing blocks");
      }
      if (tester->curr_test_bytes_processed != tester->target_processed_byte_count)
      {
        repetition_tester_error(tester, "Tester has mismatched target and actual bytes processed");
      }

      if (tester->mode == REPTEST_MODE_TESTING) // We are all good no errors from previous checks
      {
        Repetition_Tester_Results *results = &tester->results;
        results->test_count += 1;
        results->total_time += tester->curr_test_time_elapsed;

        results->max_time = MAX(tester->curr_test_time_elapsed, results->max_time);

        // Have some special stuff to do if we find a new min
        if (tester->curr_test_time_elapsed < results->min_time)
        {
          results->min_time = tester->curr_test_time_elapsed;

          // Restart time to find new min
          tester->tests_start_time = current_time;

          print_repetition_test_time("MIN", results->min_time, tester->cpu_timer_frequency,
                                      tester->curr_test_bytes_processed);
          printf("                                                          \r");
        }

        tester->begin_block_count = 0;
        tester->close_block_count = 0;
        tester->curr_test_time_elapsed    = 0;
        tester->curr_test_bytes_processed = 0;

        // Now check if long enough time has passed without finding a new min
        if ((current_time - tester->tests_start_time) > tester->try_for_min_time)
        {
          tester->mode = REPTEST_MODE_COMPLETE;

          Repetition_Tester_Results *results = &tester->results;

          print_repetition_test_time("MIN", results->min_time, tester->cpu_timer_frequency,
                                     tester->target_processed_byte_count);
          printf("\n");

          print_repetition_test_time("MAX", results->max_time, tester->cpu_timer_frequency,
                                     tester->target_processed_byte_count);
          printf("\n");

          if (results->test_count)
          {
            print_repetition_test_time("AVG", results->total_time / results->test_count,
                                       tester->cpu_timer_frequency,
                                       tester->target_processed_byte_count);
            printf("\n");
          }
        }
      }
    }
  }

  return tester->mode == REPTEST_MODE_TESTING;
}

static
void read_with_fread(Repetition_Tester *tester, Operation_Parameters *params)
{
  while (repetition_tester_is_testing(tester))
  {
    FILE *file = fopen(params->file_name, "rb");
    if (file)
    {
      repetition_tester_begin_time(tester);
      usize result = fread(params->buffer.data, params->buffer.count, 1, file);
      repetition_tester_close_time(tester);

      if (result == 1)
      {
        repetition_tester_count_bytes(tester, params->buffer.count);
      }
      else
      {
        repetition_tester_error(tester, "Unable to read file");
      }

      fclose(file);
    }
    else
    {
      repetition_tester_error(tester, "Unable to open file");
    }
  }
}

static
void read_with_read(Repetition_Tester *tester, Operation_Parameters *params)
{
  while (repetition_tester_is_testing(tester))
  {
    int fd = open(params->file_name, O_RDONLY);

    if (fd != -1)
    {
      repetition_tester_begin_time(tester);
      isize result = read(fd, params->buffer.data, params->buffer.count);
      repetition_tester_close_time(tester);

      if (result == params->buffer.count)
      {
        repetition_tester_count_bytes(tester, params->buffer.count);
      }
      else
      {
        repetition_tester_error(tester, "Unable to read file");
      }

      close(fd);
    }
    else
    {
      repetition_tester_error(tester, "Unable to open file");
    }
  }
}

typedef struct Operation_Entry Operation_Entry;
struct Operation_Entry
{
  String name;
  Operation_Function *function;
};

Operation_Entry test_entries[] =
{
  {String("fread"), read_with_fread},
  {String("read"),  read_with_read},
};

int main(int arg_count, char **args)
{
  if (arg_count != 3)
  {
    printf("Usage: %s [test_file] [seconds_to_try_for_min]\n", args[0]);
    return 1;
  }

  usize size = file_size(args[1]);
  String buffer =
  {
    .data  = malloc(size),
    .count = size,
  };

  Operation_Parameters params =
  {
    .buffer    = buffer,
    .file_name = args[1],
  };

  u64 cpu_timer_frequency = estimate_cpu_freq();

  u32 seconds_to_try_for_min = atoi(args[2]);

  while (true)
  {
    Repetition_Tester testers[STATIC_ARRAY_COUNT(test_entries)] = {0};

    for (isize i = 0; i < STATIC_ARRAY_COUNT(test_entries); i++)
    {
      Repetition_Tester *tester = &testers[i];
      Operation_Entry *entry = &test_entries[i];

      printf("\n--- %.*s ---\n", String_Format(entry->name));
      printf("                                                          \r");
      repetition_tester_new_wave(tester, size, cpu_timer_frequency, seconds_to_try_for_min);
      entry->function(tester, &params);
    }
  }

  free(buffer.data);
}
