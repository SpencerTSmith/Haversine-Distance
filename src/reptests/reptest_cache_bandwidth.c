#define LOG_TITLE "REPETITION_TESTER"
#define COMMON_IMPLEMENTATION
#include "../common.h"

#include "../benchmark/benchmark_inc.h"
#include "../benchmark/benchmark_inc.c"

extern void read_mask_asm(u64 count, u8 *data, u64 mask);

int main(int arg_count, char **args)
{
  if (arg_count != 2)
  {
    printf("Usage: %s [seconds_to_try_for_min]\n", args[0]);
  }

  u64 count = GB(1);
  u8 *data = os_allocate(count, OS_ALLOCATION_COMMIT|OS_ALLOCATION_PREFAULT);
  // for (usize i = 0; i < count; i++)
  // {
  //   data[i] = (u8)i;
  // }

  u64 cpu_timer_frequency = estimate_cpu_timer_freq();

  u32 seconds_to_try_for_min = atoi(args[1]);

  Repetition_Tester testers[30] = {0}; // 1 GB max 2^30 = 1G

  // Start at 1KB
  for (usize region_shift = 10; region_shift < STATIC_COUNT(testers); region_shift++)
  {
    Repetition_Tester *tester = testers + region_shift;

    u64 region = (1L << region_shift);
    u64 mask   = region - 1;

    printf("\n--- Reading within %lu kb ---\n", region/1024);
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

    u64 region = (1L << region_shift);

    f64 seconds = cpu_time_in_seconds(min.v[REPTEST_VALUE_TIME], cpu_timer_frequency);
    f64 gb_per_s = min.v[REPTEST_VALUE_BYTE_COUNT]  / (f64)GB(1) / seconds;

    printf("%lu,%f\n", region/1024, gb_per_s);
  }

  os_deallocate(data, count);
}
