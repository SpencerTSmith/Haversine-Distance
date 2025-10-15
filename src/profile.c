#include "common.h"

#include <math.h>
#include <x86intrin.h>
#include <sys/time.h>

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

// Just for storing actual timing info and where we need to save that to
typedef struct Profile_Pass Profile_Pass;
struct Profile_Pass
{
  String name;
  u64    start;
  u64    old_elapsed_inclusive;
  usize  zone_index;
  usize  parent_index;
};

// Here we collect info on 'zones' which is all the times a 'pass' hits it
typedef struct Profile_Zone Profile_Zone;
struct Profile_Zone
{
  String name;
  u64    elapsed_exclusive; // Not including child zones
  u64    elapsed_inclusive; // Incuding child zones
  u64    hit_count;
};

#define MAX_PROFILE_ZONES 4096

typedef struct Profiler Profiler;
struct Profiler
{
  // For the whole profiler duration
  u64 start;

  // DANGER! Needs to be a per thread profiler
  usize current_parent_zone;

  Profile_Zone zones[MAX_PROFILE_ZONES];
};

static Profiler g_profiler;

static
void begin_profiling()
{
  g_profiler = (Profiler)
  {
    .start = read_cpu_timer(),
  };
}

static
void end_profiling()
{
  u64 total_delta = read_cpu_timer() - g_profiler.start;

  if (total_delta)
  {
    u64 freq = estimate_cpu_freq();
    printf("[PROFILE] Total duration: %lu (%fms @ CPU Frequency: %u)\n", total_delta, (f64)total_delta / (f64)freq * 1000.0, freq);

    f64 exclusive_percent = 0.0;

    for (usize i = 0; i < STATIC_ARRAY_COUNT(g_profiler.zones); i++)
    {
      Profile_Zone *zone = &g_profiler.zones[i];

      if (zone->elapsed_inclusive)
      {
        f64 percent = ((f64)zone->elapsed_exclusive / (f64)total_delta) * 100.0;

        printf("[PROFILE] Zone '%.*s':\n"
               "  Hit Count: %lu\n"
               "  Exclusive Timestamp Cycles: %lu (%.4f%%)\n"
               , String_Format(zone->name), zone->hit_count, zone->elapsed_exclusive, percent);
        if (zone->elapsed_exclusive != zone->elapsed_inclusive)
        {
          f64 with_children_percent = ((f64)zone->elapsed_inclusive / (f64)total_delta) * 100.0;
          printf("  Inclusive Timestamp Cycles: %lu (%.4f%%)\n", zone->elapsed_inclusive, with_children_percent);
        }

        exclusive_percent += percent;
      }
    }

  }
}

static
Profile_Pass __profile_begin_pass(String name, usize zone_index)
{
  Profile_Pass pass =
  {
    .parent_index = g_profiler.current_parent_zone,
    .name         = name,
    .zone_index   = zone_index,
    .old_elapsed_inclusive = g_profiler.zones[zone_index].elapsed_inclusive, // Save the original so it get overwritten in the case of children
  };

  // Push parent
  g_profiler.current_parent_zone = zone_index;

  // Make sure this is the last thing to run
  pass.start = read_cpu_timer();

  return pass;
}

static
void __profile_end_pass(Profile_Pass pass)
{
  // First!
  u64 elapsed = read_cpu_timer() - pass.start;

  // Pop parent
  g_profiler.current_parent_zone = pass.parent_index;

  Profile_Zone *current = &g_profiler.zones[pass.zone_index];
  current->elapsed_exclusive += elapsed;
  current->hit_count += 1;
  current->name = pass.name; // Stupid...
  current->elapsed_inclusive = pass.old_elapsed_inclusive + elapsed; // So that only the final out of potential recursive calls writes inclusive time

  // Accumulate to parent time
  Profile_Zone *parent = &g_profiler.zones[pass.parent_index];
  parent->elapsed_exclusive -= elapsed;
}

#ifdef PROFILE
  // Only works for unity builds, but I do those anyways
  #define profile_begin_pass(name) __profile_begin_pass(String(name), __COUNTER__ + 1) // First zone is never used, so the default parent 0 doesn't get junk info
  #define profile_end_pass(block)  __profile_end_pass(block)

  // Helpful, and ok to hardcode name since should only use these once per function scope
  #define profile_begin_func() Profile_Pass __func_pass__ = profile_begin_pass(__func__)
  #define profile_end_func()   profile_end_pass(__func_pass__)

  #define PROFILE_SCOPE(name)                                              \
    Profile_Pass MACRO_CONCAT(pass, __LINE__) = profile_begin_pass(name); DEFER_SCOPE(VOID_PROC, profile_end_pass(MACRO_CONCAT(pass, __LINE__)))
#else
  #define profile_begin_pass(name) VOID_PROC
  #define profile_end_pass(block)  VOID_PROC
  #define profile_begin_func()     VOID_PROC
  #define profile_end_func()       VOID_PROC
  #define PROFILE_SCOPE(name)
#endif
