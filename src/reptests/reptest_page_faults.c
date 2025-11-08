#define LOG_TITLE "REPETITION_TESTER"
#define COMMON_IMPLEMENTATION
#include "../common.h"

#include "../benchmark/benchmark_inc.h"
#include "../benchmark/benchmark_inc.c"

typedef struct Operation_Parameters Operation_Parameters;
struct Operation_Parameters
{
  String buffer;
};

static
void write_all_bytes_no_malloc(Repetition_Tester *tester, Operation_Parameters *params)
{
  params->buffer.v = os_allocate(params->buffer.count, OS_ALLOCATION_COMMIT);

  while (repetition_tester_is_testing(tester))
  {
    String buffer = params->buffer;

    repetition_tester_begin_time(tester);
    for (usize i = 0; i < buffer.count; i++)
    {
      buffer.v[i] = (u8)i;
    }
    repetition_tester_close_time(tester);

    repetition_tester_count_bytes(tester, buffer.count);
  }

  os_deallocate(params->buffer.v, params->buffer.count);
}

static
void write_all_bytes_malloc(Repetition_Tester *tester, Operation_Parameters *params)
{
  while (repetition_tester_is_testing(tester))
  {
    params->buffer.v = os_allocate(params->buffer.count, OS_ALLOCATION_COMMIT);

    String buffer = params->buffer;

    repetition_tester_begin_time(tester);
    for (usize i = 0; i < buffer.count; i++)
    {
      buffer.v[i] = (u8)i;
    }
    repetition_tester_close_time(tester);

    repetition_tester_count_bytes(tester, buffer.count);

    os_deallocate(params->buffer.v, params->buffer.count);
  }
}

Operation_Entry test_entries[] =
{
  {String("alloc"),    write_all_bytes_malloc},
  {String("no alloc"), write_all_bytes_no_malloc},
};

int main(int arg_count, char **args)
{
  if (arg_count != 2)
  {
    printf("Usage: %s [seconds_to_try_for_min]\n", args[0]);
  }

  usize size = GB(1);
  String buffer =
  {
    .v = malloc(size),
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
