#define LOG_TITLE "REPETITION_TESTER"
#define COMMON_IMPLEMENTATION
#include "common.h"

#include "benchmark/benchmark_inc.h"
#include "benchmark/benchmark_inc.c"

typedef void Assmebly_Function(u64 count, u64 *data);

typedef struct Assmebly_Entry Assembly_Entry;
struct Assmebly_Entry
{
  String name;
  Assmebly_Function *function;
};

extern void write1_asm(u64 count, u64 *data);
extern void write2_asm(u64 count, u64 *data);
extern void write3_asm(u64 count, u64 *data);
extern void write4_asm(u64 count, u64 *data);

Assembly_Entry test_entries[] =
{
  {String("write1"), write1_asm},
  {String("write2"), write2_asm},
  {String("write3"), write3_asm},
  {String("write4"), write4_asm},
};

int main(int arg_count, char **args)
{
  if (arg_count != 2)
  {
    printf("Usage: %s [seconds_to_try_for_min]\n", args[0]);
  }

  u64 count = GB(1);

  u64 cpu_timer_frequency = estimate_cpu_timer_freq();

  u32 seconds_to_try_for_min = atoi(args[1]);

  u64 data = 10;

  while (true)
  {
    Repetition_Tester testers[STATIC_ARRAY_COUNT(test_entries)] = {0};

    for (usize func_idx = 0; func_idx < STATIC_ARRAY_COUNT(test_entries); func_idx++)
    {
      Repetition_Tester *tester = &testers[func_idx];

      Assembly_Entry *entry = &test_entries[func_idx];

      printf("\n--- %.*s ---\n", String_Format(entry->name));
      printf("                                                          \r");

      repetition_tester_new_wave(tester, count, cpu_timer_frequency, seconds_to_try_for_min);
      while (repetition_tester_is_testing(tester))
      {
        repetition_tester_begin_time(tester);
        entry->function(count, &data);
        repetition_tester_close_time(tester);

        repetition_tester_count_bytes(tester, count);
      }
    }
  }
}
