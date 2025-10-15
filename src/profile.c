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

// Just for storing actual timing info and where we need to save that to
typedef struct Profile_Block Profile_Block;
struct Profile_Block
{
  String name;
  u64    start;
  u64    zone_index;
};

// Here we collect info on 'zones' which is all the times a 'block' is hit
typedef struct Profile_Zone Profile_Zone;
struct Profile_Zone
{
  String name;
  u64    elapsed; // Total time here.
  u64    hit_count;
};

#define MAX_PROFILE_ZONES 4096

typedef struct Profiler Profiler;
struct Profiler
{
  // For the whole profiler duration
  u64 start;

  Profile_Zone zones[MAX_PROFILE_ZONES];
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
  u64 total_delta = read_cpu_timer() - g_profiler.start;

  if (total_delta)
  {
    for (usize i = 0; i < MAX_PROFILE_ZONES; i++)
    {
      Profile_Zone *zone = &g_profiler.zones[i];

      if (zone->elapsed)
      {
        f64 percent = ((f64)zone->elapsed / (f64)total_delta) * 100.0;
        printf("Profile %.*s: %lu (%.4f%%)\n", String_Format(zone->name), zone->elapsed, percent);
      }
    }

    u64 freq = estimate_cpu_freq();
    printf("Total duration: %lu (%fms)\n", total_delta, (f64)total_delta / (f64)freq * 1000.0);
  }
}

static inline
Profile_Block __profile_begin_block(String name, usize zone_index)
{
  Profile_Block block =
  {
    .name       = name,
    .zone_index = zone_index,
    .start      = read_cpu_timer(),
  };

  return block;
}
// Only works for unity builds
#define profile_begin_block(name) __profile_begin_block(String(name), __COUNTER__)

#define PROFILE_BLOCK_DIRTY_BIT (1L << 63) // For marking the index when we have finished for the macro bullshittery
static inline
void profile_end_block(Profile_Block block)
{
  Profile_Zone *zone = &g_profiler.zones[block.zone_index];
  zone->name = block.name; // Stupid...

  zone->elapsed   += read_cpu_timer() - block.start;
  zone->hit_count += 1;
}

#define PROFILE_SCOPE(name) \
  for (Profile_Block __block = profile_begin_block(name); !(__block.zone_index == PROFILE_BLOCK_DIRTY_BIT); profile_end_block(__block), __block.zone_index = PROFILE_BLOCK_DIRTY_BIT)
