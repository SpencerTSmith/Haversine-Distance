#define LOG_TITLE "REPETITION_TESTER"
#define COMMON_IMPLEMENTATION
#include "../common.h"

#include "../benchmark/benchmark_inc.h"
#include "../benchmark/benchmark_inc.c"

extern void read_pathologic_asm(u64 outer_count, u8 *data, u64 inner_count, u64 read_spacing);

int main(int arg_count, char **args)
{
  if (arg_count != 2)
  {
    printf("Usage: %s [seconds_to_try_for_min]\n", args[0]);
    return -1;
  }


  u64 cpu_timer_frequency = estimate_cpu_timer_freq();

  u32 seconds_to_try_for_min = atoi(args[1]);

  u64 cacheline_size = 64;
  u64 inner_count = 256; // how many cache lines to read
  u64 outer_count = 64;  // how many times to repeat the above

  Repetition_Tester testers[128] = {0};

  u64 count = inner_count * cacheline_size * STATIC_COUNT(testers);
  u8 *data = os_allocate(count, OS_ALLOCATION_COMMIT|OS_ALLOCATION_PREFAULT);

  for (usize spacing_idx = 0; spacing_idx < STATIC_COUNT(testers); spacing_idx++)
  {
    Repetition_Tester *tester = testers + spacing_idx;

    u64 read_spacing = spacing_idx * cacheline_size;

    u64 total_size  = outer_count * inner_count * cacheline_size;

    printf("\n--- Reading %lu 64 byte cache lines, spacing: %lu bytes (%lu line%s) ---\n",
           inner_count, read_spacing, spacing_idx, spacing_idx > 1 ? "s" : "");

    repetition_tester_new_wave(tester, total_size, cpu_timer_frequency, seconds_to_try_for_min);
    while (repetition_tester_is_testing(tester))
    {
      repetition_tester_begin_time(tester);
      read_pathologic_asm(outer_count, data, inner_count, read_spacing);
      repetition_tester_close_time(tester);

      repetition_tester_count_bytes(tester, total_size);
    }
  }

  printf("spacing,gb_per_s\n");
  for (usize spacing_idx = 0; spacing_idx < STATIC_COUNT(testers); spacing_idx++)
  {
    Repetition_Test_Values min = testers[spacing_idx].results.min;

    f64 seconds = cpu_time_in_seconds(min.v[REPTEST_VALUE_TIME], cpu_timer_frequency);
    f64 gb_per_s = min.v[REPTEST_VALUE_BYTE_COUNT]  / (f64)GB(1) / seconds;

    printf("%lu,%f\n", spacing_idx, gb_per_s);
  }

  os_deallocate(data, count);
}
