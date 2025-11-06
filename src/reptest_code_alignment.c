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

extern void nop_aligned64_asm(u64 count);
extern void nop_aligned1_asm(u64 count);
extern void nop_aligned15_asm(u64 count);
extern void nop_aligned31_asm(u64 count);
extern void nop_aligned63_asm(u64 count);

static
void nop_aligned64(Repetition_Tester *tester, Operation_Parameters *params)
{
  params->buffer.v = os_allocate(params->buffer.count, OS_ALLOCATION_COMMIT);

  while (repetition_tester_is_testing(tester))
  {
    String buffer = params->buffer;

    repetition_tester_begin_time(tester);
    nop_aligned64_asm(buffer.count);
    repetition_tester_close_time(tester);

    repetition_tester_count_bytes(tester, buffer.count);
  }

  os_deallocate(params->buffer.v, params->buffer.count);
}

static
void nop_aligned1(Repetition_Tester *tester, Operation_Parameters *params)
{
  params->buffer.v = os_allocate(params->buffer.count, OS_ALLOCATION_COMMIT);

  while (repetition_tester_is_testing(tester))
  {
    String buffer = params->buffer;

    repetition_tester_begin_time(tester);
    nop_aligned1_asm(buffer.count);
    repetition_tester_close_time(tester);

    repetition_tester_count_bytes(tester, buffer.count);
  }

  os_deallocate(params->buffer.v, params->buffer.count);
}

static
void nop_aligned15(Repetition_Tester *tester, Operation_Parameters *params)
{
  params->buffer.v = os_allocate(params->buffer.count, OS_ALLOCATION_COMMIT);

  while (repetition_tester_is_testing(tester))
  {
    String buffer = params->buffer;

    repetition_tester_begin_time(tester);
    nop_aligned15_asm(buffer.count);
    repetition_tester_close_time(tester);

    repetition_tester_count_bytes(tester, buffer.count);
  }

  os_deallocate(params->buffer.v, params->buffer.count);
}

static
void nop_aligned31(Repetition_Tester *tester, Operation_Parameters *params)
{
  params->buffer.v = os_allocate(params->buffer.count, OS_ALLOCATION_COMMIT);

  while (repetition_tester_is_testing(tester))
  {
    String buffer = params->buffer;

    repetition_tester_begin_time(tester);
    nop_aligned31_asm(buffer.count);
    repetition_tester_close_time(tester);

    repetition_tester_count_bytes(tester, buffer.count);
  }

  os_deallocate(params->buffer.v, params->buffer.count);
}

static
void nop_aligned63(Repetition_Tester *tester, Operation_Parameters *params)
{
  params->buffer.v = os_allocate(params->buffer.count, OS_ALLOCATION_COMMIT);

  while (repetition_tester_is_testing(tester))
  {
    String buffer = params->buffer;

    repetition_tester_begin_time(tester);
    nop_aligned63_asm(buffer.count);
    repetition_tester_close_time(tester);

    repetition_tester_count_bytes(tester, buffer.count);
  }

  os_deallocate(params->buffer.v, params->buffer.count);
}

Operation_Entry test_entries[] =
{
  {String("aligned 64"), nop_aligned64},
  {String("aligned 1"),  nop_aligned1},
  {String("aligned 15"), nop_aligned15},
  {String("aligned 31"), nop_aligned31},
  {String("aligned 63"), nop_aligned63},
};

int main(int arg_count, char **args)
{
  if (arg_count != 2)
  {
    printf("Usage: %s [seconds_to_try_for_min]\n", args[0]);
  }

  String buffer =
  {
    .v = os_allocate(GB(1), OS_ALLOCATION_COMMIT),
    .count = GB(1),
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
      repetition_tester_new_wave(tester, buffer.count, cpu_timer_frequency, seconds_to_try_for_min);

      entry->function(tester, &params);
    }
  }
}
