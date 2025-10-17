#ifndef PLATFORM_TIMING_H
#define PLATFORM_TIMING_H

#include "common.h"

static
u64 get_os_timer_freq(void);

static
u64 read_os_timer(void);

static
u64 read_cpu_timer(void);

static
u64 estimate_cpu_freq(void);

static
f64 cpu_time_in_seconds(u64 cpu_time, u64 cpu_timer_frequency);

#endif // PLATFORM_TIMING_H
