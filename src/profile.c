#include "common.h"

#include <x86intrin.h>
#include <sys/time.h>

// NOTE(ss): Will need to be defined per OS
u64 get_os_timer_freq(void)
{
  // Posix gettimeofday is in microseconds
  return 1000000;
}

// NOTE(ss): Will need to be defined per OS
u64 read_os_timer(void)
{
  struct timeval value;
  gettimeofday(&value, 0);
  u64 result = get_os_timer_freq() * value.tv_sec + value.tv_usec;

  return result;
}

// NOTE(ss): Will need to be defined per ISA
u64 read_cpu_timer(void)
{
  return __rdtsc();
}

// Just an estimation, in microseconds
u64 estimate_cpu_freq(void)
{
  u64 wait_milliseconds = 100;
  u64 os_frequency = get_os_timer_freq();

  u64 cpu_start = read_cpu_timer();
  u64 os_start  = read_os_timer();

  u64 os_end   = 0;
  u64 os_delta = 0;

  // In microseconds
  u64 os_wait_time = (os_frequency * wait_milliseconds) / 1000;
  while (os_delta < os_wait_time)
  {
    os_end   = read_os_timer();
    os_delta = os_end - os_start;
  }

  u64 cpu_end   = read_cpu_timer();
  u64 cpu_delta = cpu_end - cpu_start;

  u64 cpu_frequency = 0;

  assert(os_delta != 0 && "OS Time delta for cpu frequency estimation was somehow 0!");

  // CPU time in OS ticks, divide by OS delta gives estimate of cpu frequency
  cpu_frequency = os_frequency * cpu_delta / os_delta;

  return cpu_frequency;
}

typedef struct Profile_Block Profile_Block;
struct Profile_Block
{
  String name;
  u64    start;
  u64    end;
};

#define MAX_PROFILE_BLOCKS 4096


typedef struct Profiler Profiler;
struct Profiler
{
  // For the whole profiler duration
  u64 start;
  u64 end;

  Profile_Block blocks[MAX_PROFILE_BLOCKS];
};

static Profiler g_profiler;

void begin_profiling()
{
  g_profiler = (Profiler)
  {
    .start = read_cpu_timer(),
  };
}

void end_profiling()
{
  g_profiler.end = read_cpu_timer();

  u64 total_delta = g_profiler.end - g_profiler.start;

  if (total_delta)
  {
    for (usize i = 0; i < MAX_PROFILE_BLOCKS; i++)
    {
      Profile_Block *block = &g_profiler.blocks[i];

      u64 delta = block->end - block->start;
      if (delta)
      {
        f64 percent = ((f64)delta / (f64)total_delta) * 100.0;
        printf("Profile %.*s: %lu (%.4f%%)\n", String_Format(block->name), delta, percent);
      }
    }

    u64 freq = estimate_cpu_freq();
    printf("Total duration: %lu (%fms)\n", total_delta, (f64)total_delta / (f64)freq * 1000.0);
  }
}

void __begin_profile_block(String name, usize index)
{
  Profile_Block *block = &g_profiler.blocks[index];
  block->start = read_cpu_timer();
  block->name  = name;
}

void __end_profile_block(usize index)
{
  Profile_Block *block = &g_profiler.blocks[index];
  block->end = read_cpu_timer();
}

#define begin_profile_block(name) __begin_profile_block(String(name), __COUNTER__)
#define end_profile_block()       __end_profile_block(__COUNTER__ - 1)
#define PROFILE_SCOPE(name)       DEFER_SCOPE(begin_profile_block(name), end_profile_block())
