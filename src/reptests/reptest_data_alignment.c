#define LOG_TITLE "REPETITION_TESTER"
#define COMMON_IMPLEMENTATION
#include "../common.h"

#include "../benchmark/benchmark_inc.h"
#include "../benchmark/benchmark_inc.c"

extern void read_mask_asm(u64 count, u8 *data, u64 mask);
extern void read_region_asm(u64 outer_count, u8 *data, u64 inner_count);

int main(int arg_count, char **args)
{
  if (arg_count != 2)
  {
    printf("Usage: %s [seconds_to_try_for_min]\n", args[0]);
    return -1;
  }

  u64 count = GB(1);
  u8 *data = os_allocate(count, OS_ALLOCATION_COMMIT|OS_ALLOCATION_PREFAULT);

  u64 cpu_timer_frequency = estimate_cpu_timer_freq();

  u32 seconds_to_try_for_min = atoi(args[1]);

  u64 region_sizes[] = {4 * 1024, 256 * 1024, 8 * 1024 * 1024, 64 * 1024 * 1024};
  u64 alignments[] = {0, 1, 2, 3, 4, 16, 31, 32, 33, 45, 63, 64, 65};
  Repetition_Tester testers[STATIC_COUNT(alignments)][STATIC_COUNT(region_sizes)] = {0};

  for (usize alignment_idx = 0; alignment_idx < STATIC_COUNT(alignments); alignment_idx++)
  {
    u64 alignment = alignments[alignment_idx];

    for (usize region_idx = 0; region_idx < STATIC_COUNT(region_sizes); region_idx++)
    {
      Repetition_Tester *tester = &testers[alignment_idx][region_idx];

      u64 region_size = region_sizes[region_idx];

      u64 inner_size = 512;
      u64 inner_count = region_size / inner_size; // How many times to do inner to cover region

      u64 outer_count = count / region_size; // How many time need to do region to cover outer
      u64 total_size = outer_count * region_size; // Remultiply to get the real size if not evenly divisible

      printf("\n--- Reading outer %lu * inner %lu * %lu bytes = %fMB within %luKB region, aligned: %lu ---\n",
             outer_count, inner_count, inner_size, total_size/1024.0/1024.0, region_size/1024, alignment);

      repetition_tester_new_wave(tester, total_size, cpu_timer_frequency, seconds_to_try_for_min);
      while (repetition_tester_is_testing(tester))
      {
        repetition_tester_begin_time(tester);
        read_region_asm(outer_count, data + alignment, inner_count);
        repetition_tester_close_time(tester);

        repetition_tester_count_bytes(tester, total_size);
      }
    }
  }

  printf("alignment");
  for (usize region_idx = 0; region_idx < STATIC_COUNT(region_sizes); region_idx++)
  {
    u64 region_size = region_sizes[region_idx];
    printf(",%lu byte region", region_size);
  }
  printf("\n");

  for (usize alignment_idx = 0; alignment_idx < STATIC_COUNT(alignments); alignment_idx++)
  {
    u64 alignment = alignments[alignment_idx];
    printf("%lu", alignment);

    for (usize region_idx = 0; region_idx < STATIC_COUNT(region_sizes); region_idx++)
    {
      Repetition_Test_Values min = testers[alignment_idx][region_idx].results.min;

      f64 seconds = cpu_time_in_seconds(min.v[REPTEST_VALUE_TIME], cpu_timer_frequency);
      f64 gb_per_s = min.v[REPTEST_VALUE_BYTE_COUNT]  / (f64)GB(1) / seconds;

      printf(",%f", gb_per_s);
    }

    printf("\n");
  }

  os_deallocate(data, count);
}
