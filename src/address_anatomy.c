#define LOG_TITLE "REPETITION_TESTER"
#define COMMON_IMPLEMENTATION
#include "common.h"

#include "benchmark/platform_timing.h"
#include "benchmark/platform_timing.c"

// Start counting towards the least significant bit
static
void print_binary(u64 bits, usize start, usize count)
{
  for (usize i = 0; i < count; i++)
  {
    u64 shift = 64 - start - 1 - i;
    u64 bit = (bits >> shift) & 1;
    printf("%c", bit ? '1' : '0');
  }
}

static
void print_virtual_address(Virtual_Address_Bits bits)
{
  printf("|%3u|%3u|%3u|%3u|%10u|",
          bits.level4_index, bits.directory_pointer_index,
          bits.directory_index, bits.table_index,
          bits.page_offset);
}

int main(int arg_count, char **args)
{
  for (usize i = 0; i < 16; i++)
  {
    void *address = os_allocate(1024 * 1024, OS_ALLOCATION_COMMIT);


    print_binary((u64)address, 48, 9);
    printf("|");
    print_binary((u64)address, 39, 9);
    printf("|");
    print_binary((u64)address, 30, 9);
    printf("|");
    print_binary((u64)address, 21, 9);
    printf("|");
    print_binary((u64)address, 12, 12);
    printf("\n");

    Virtual_Address_Bits bits_4KB = get_virtual_address_bits_4KB(address);
    Virtual_Address_Bits bits_2MB = get_virtual_address_bits_2MB(address);
    Virtual_Address_Bits bits_1GB = get_virtual_address_bits_1GB(address);

    print_virtual_address(bits_4KB);
    printf("\n");
    print_virtual_address(bits_2MB);
    printf("\n");
    print_virtual_address(bits_1GB);
    printf("\n");
  }
}
