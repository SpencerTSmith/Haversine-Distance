#ifndef PLATFORM_TIMING_H
#define PLATFORM_TIMING_H

#include "../common.h"

// Per OS...
static
u64 get_os_timer_freq(void);

// Per OS...
static
u64 read_os_timer(void);

// Per ISA...
static
u64 read_cpu_timer(void);

static
u64 estimate_cpu_freq(void);

static
f64 cpu_time_in_seconds(u64 cpu_time, u64 cpu_timer_frequency);

typedef struct Virtual_Address_Bits Virtual_Address_Bits;
struct Virtual_Address_Bits
{
  u16 level4_index;            // 9 bits
  u16 directory_pointer_index; // 9 bits
  u16 directory_index;         // 9 bits
  u16 table_index;             // 9 bits
  u32 page_offset;             // 12, 21, or 30 bits depending on page size
};

// Per ISA...
Virtual_Address_Bits get_virtual_address_bits_4KB(void *pointer);
Virtual_Address_Bits get_virtual_address_bits_2MB(void *pointer);
Virtual_Address_Bits get_virtual_address_bits_1GB(void *pointer);

#endif // PLATFORM_TIMING_H
