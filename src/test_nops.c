#define LOG_TITLE "REPETITION_TESTER"
#define COMMON_IMPLEMENTATION
#include "common.h"

#include "benchmark/benchmark_inc.h"
#include "benchmark/benchmark_inc.c"

typedef struct Operation_Parameters Operation_Parameters;
struct Operation_Parameters
{
  String buffer;
};

extern void nop1x3_all_bytes_asm(u64 count);
extern void nop3x1_all_bytes_asm(u64 count);
extern void nop9x1_all_bytes_asm(u64 count);
extern void nop32x1_all_bytes_asm(u64 count);

static
void nop1x3_all_bytes(Repetition_Tester *tester, Operation_Parameters *params)
{
  params->buffer.data = os_allocate(params->buffer.count, OS_ALLOCATION_COMMIT);

  while (repetition_tester_is_testing(tester))
  {
    String buffer = params->buffer;

    repetition_tester_begin_time(tester);
    nop1x3_all_bytes_asm(buffer.count);
    repetition_tester_close_time(tester);

    repetition_tester_count_bytes(tester, buffer.count);
  }

  os_deallocate(params->buffer.data, params->buffer.count);
}

static
void nop3x1_all_bytes(Repetition_Tester *tester, Operation_Parameters *params)
{
  params->buffer.data = os_allocate(params->buffer.count, OS_ALLOCATION_COMMIT);

  while (repetition_tester_is_testing(tester))
  {
    String buffer = params->buffer;

    repetition_tester_begin_time(tester);
    nop3x1_all_bytes_asm(buffer.count);
    repetition_tester_close_time(tester);

    repetition_tester_count_bytes(tester, buffer.count);
  }

  os_deallocate(params->buffer.data, params->buffer.count);
}

static
void nop9x1_all_bytes(Repetition_Tester *tester, Operation_Parameters *params)
{
  params->buffer.data = os_allocate(params->buffer.count, OS_ALLOCATION_COMMIT);

  while (repetition_tester_is_testing(tester))
  {
    String buffer = params->buffer;

    repetition_tester_begin_time(tester);
    nop3x1_all_bytes_asm(buffer.count);
    repetition_tester_close_time(tester);

    repetition_tester_count_bytes(tester, buffer.count);
  }

  os_deallocate(params->buffer.data, params->buffer.count);
}

static
void nop32x1_all_bytes(Repetition_Tester *tester, Operation_Parameters *params)
{
  params->buffer.data = os_allocate(params->buffer.count, OS_ALLOCATION_COMMIT);

  while (repetition_tester_is_testing(tester))
  {
    String buffer = params->buffer;

    repetition_tester_begin_time(tester);
    nop32x1_all_bytes_asm(buffer.count);
    repetition_tester_close_time(tester);

    repetition_tester_count_bytes(tester, buffer.count);
  }

  os_deallocate(params->buffer.data, params->buffer.count);
}

Operation_Entry test_entries[] =
{
  {String("1x3"),  nop1x3_all_bytes},
  {String("3x1"),  nop3x1_all_bytes},
  {String("9x1"),  nop9x1_all_bytes},
  {String("32x1"), nop32x1_all_bytes},
};

int main(int arg_count, char **args)
{
  if (arg_count != 2)
  {
    printf("Usage: %s [seconds_to_try_for_min]\n", args[0]);
  }

  isize size = GB(1);
  String buffer =
  {
    .data  = os_allocate(size, OS_ALLOCATION_COMMIT),
    .count = size,
  };

  Operation_Parameters params =
  {
    .buffer = buffer,
  };

  u64 cpu_timer_frequency = estimate_cpu_timer_freq();

  u32 seconds_to_try_for_min = atoi(args[1]);

  while (true)
  {
    Repetition_Tester testers[STATIC_ARRAY_COUNT(test_entries)] = {0};

    for (usize i = 0; i < STATIC_ARRAY_COUNT(test_entries); i++)
    {
      Repetition_Tester *tester = &testers[i];
      Operation_Entry *entry = &test_entries[i];

      printf("\n--- %.*s ---\n", String_Format(entry->name));
      printf("                                                          \r");
      repetition_tester_new_wave(tester, size, cpu_timer_frequency, seconds_to_try_for_min);

      entry->function(tester, &params);
    }
  }
}
