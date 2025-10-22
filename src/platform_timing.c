#include "common.h"

#include <x86intrin.h>
#include <sys/time.h>
#include <sys/resource.h>

// NOTE(ss): Will need to be defined per OS
static
u64 get_os_timer_freq(void)
{
  // Posix gettimeofday is in microseconds
  return 1000000;
}

// NOTE(ss): Will need to be defined per OS
static
u64 read_os_timer(void)
{
  struct timeval value;
  gettimeofday(&value, 0);
  u64 result = get_os_timer_freq() * value.tv_sec + value.tv_usec;

  return result;
}

// NOTE(ss): Will need to be defined per ISA
static
u64 read_cpu_timer(void)
{
  return __rdtsc();
}

// Just an estimation, in microseconds
static
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

static
f64 cpu_time_in_seconds(u64 cpu_time, u64 cpu_timer_frequency)
{
  f64 result = 0.0;
  if (cpu_timer_frequency)
  {
    result = (f64)cpu_time / (f64)cpu_timer_frequency;
  }

  return result;
}

static
u64 read_os_page_faults()
{
  struct rusage usage = {0};
  getrusage(RUSAGE_SELF, &usage);

  u64 hard_faults = usage.ru_majflt;
  u64 soft_faults = usage.ru_minflt;

  // For now just count both, maybe we get more specific later
  return hard_faults + soft_faults;
}
