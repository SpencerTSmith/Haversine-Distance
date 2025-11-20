#define LOG_TITLE "REPETITION_TESTER"
#define COMMON_IMPLEMENTATION
#include "../common.h"

#include "../benchmark/benchmark_inc.h"
#include "../benchmark/benchmark_inc.c"

extern void read_mask_asm(u64 count, u8 *data, u64 mask);
extern void read_region_asm(u64 outer_count, u8 *data, u64 inner_count);

int main(int arg_count, char **args)
{
  if (arg_count != 3)
  {
    printf("Usage: %s [seconds_to_try_for_min] [power-2/granular]\n", args[0]);
    return -1;
  }

  u64 count = GB(1);
  u8 *data = os_allocate(count, OS_ALLOCATION_COMMIT|OS_ALLOCATION_PREFAULT);

  u64 cpu_timer_frequency = estimate_cpu_timer_freq();

  u32 seconds_to_try_for_min = atoi(args[1]);

  if (strcmp(args[2], "power-2") == 0)
  {
    Repetition_Tester testers[30] = {0}; // 1 GB max 2^30 = 1G

    // Start at 1KB
    for (usize region_shift = 10; region_shift < STATIC_COUNT(testers); region_shift++)
    {
      Repetition_Tester *tester = testers + region_shift;

      u64 region_size = (1L << region_shift);
      u64 mask   = region_size - 1;

      printf("\n--- Reading within %luKB ---\n", region_size/1024);
      printf("                                                          \r");


      repetition_tester_new_wave(tester, count, cpu_timer_frequency, seconds_to_try_for_min);
      while (repetition_tester_is_testing(tester))
      {
        repetition_tester_begin_time(tester);
        read_mask_asm(count, data, mask);
        repetition_tester_close_time(tester);

        repetition_tester_count_bytes(tester, count);
      }
    }

    // Dump csv
    printf("region(kb),gb_per_s\n");
    for (usize region_shift = 10; region_shift < STATIC_COUNT(testers); region_shift++)
    {
      Repetition_Test_Values min = testers[region_shift].results.min;

      u64 region_size = (1L << region_shift);

      f64 seconds = cpu_time_in_seconds(min.v[REPTEST_VALUE_TIME], cpu_timer_frequency);
      f64 gb_per_s = min.v[REPTEST_VALUE_BYTE_COUNT]  / (f64)GB(1) / seconds;

      printf("%lu,%f\n", region_size/1024, gb_per_s);
    }
  }
  else // Granular by default
  {
    u64 region_sizes[96] = {0};
    Repetition_Tester testers[96] = {0};

    // TODO: Would be cool to newton's method it, basically go until you see
    // a big drop in throughput, backtrack more granularly until the difference
    // is small again, should be more exact
    u64 delta_size = 512;
    u64 accum_size = KB(8);
    for (usize region_idx = 0; region_idx < STATIC_COUNT(testers); region_idx++)
    {
      Repetition_Tester *tester = testers + region_idx;

      u64 region_size = accum_size;
      region_sizes[region_idx] = region_size;

      if (IS_POW2(accum_size))
      {
        delta_size *= 2;
      }
      accum_size += delta_size;

      u64 inner_size = 512;
      u64 inner_count = region_size / inner_size; // How many times to do inner to cover region

      u64 outer_count = count / region_size; // How many time need to do region to cover outer
      u64 total_size = outer_count * region_size; // Remultiply to get the real size if not evenly divisible

      printf("\n--- Reading outer %lu * inner %lu * %lu bytes = %fMB within %luKB region ---\n", outer_count, inner_count, inner_size, total_size/1024.0/1024.0, region_size/1024);

      repetition_tester_new_wave(tester, total_size, cpu_timer_frequency, seconds_to_try_for_min);
      while (repetition_tester_is_testing(tester))
      {
        repetition_tester_begin_time(tester);
        read_region_asm(outer_count, data, inner_count);
        repetition_tester_close_time(tester);

        repetition_tester_count_bytes(tester, total_size);
      }
    }

    printf("region(kb),gb_per_s\n");
    for (usize region_idx = 0; region_idx < STATIC_COUNT(testers); region_idx++)
    {
      Repetition_Test_Values min = testers[region_idx].results.min;

      u64 region_size = region_sizes[region_idx];

      f64 seconds = cpu_time_in_seconds(min.v[REPTEST_VALUE_TIME], cpu_timer_frequency);
      f64 gb_per_s = min.v[REPTEST_VALUE_BYTE_COUNT]  / (f64)GB(1) / seconds;

      printf("%lu,%f\n", region_size/1024, gb_per_s);
    }
  }

  os_deallocate(data, count);
}
