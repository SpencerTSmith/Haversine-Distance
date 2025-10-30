#define LOG_TITLE "REPETITION_TESTER"
#define COMMON_IMPLEMENTATION
#include "common.h"

#include "benchmark/platform_timing.h"
#include "benchmark/platform_timing.c"

typedef struct Virtual_Address_Bits Virtual_Address_Bits;
struct Virtual_Address_Bits
{
  u16 level4_index;            // 9 bits
  u16 directory_pointer_index; // 9 bits
  u16 directory_index;         // 9 bits
  u16 table_index;             // 9 bits
  u32 page_offset;             // 12, 21, or 30 bits depending on page size
};

static
Virtual_Address_Bits get_virtual_address_bits_4KB(void *pointer)
{
  u64 address = (u64)pointer;
  Virtual_Address_Bits bits =
  {
    .level4_index            = (u16)((address >> 39) & 0x1FF),
    .directory_pointer_index = (u16)((address >> 30) & 0x1FF),
    .directory_index         = (u16)((address >> 21) & 0x1FF),
    .table_index             = (u16)((address >> 12) & 0x1FF),
    .page_offset             = (u32)(address & 0xFFF),
  };

  return bits;
}

static
Virtual_Address_Bits get_virtual_address_bits_2MB(void *pointer)
{
  u64 address = (u64)pointer;
  Virtual_Address_Bits bits =
  {
    .level4_index            = (u16)((address >> 39) & 0x1FF),
    .directory_pointer_index = (u16)((address >> 30) & 0x1FF),
    .directory_index         = (u16)((address >> 21) & 0x1FF),
    .page_offset             = (u32)(address & 0x1FFFFF),
  };

  return bits;
}

static
Virtual_Address_Bits get_virtual_address_bits_1GB(void *pointer)
{
  u64 address = (u64)pointer;
  Virtual_Address_Bits bits =
  {
    .level4_index            = (u16)((address >> 39) & 0x1FF),
    .directory_pointer_index = (u16)((address >> 30) & 0x1FF),
    .page_offset             = (u32)(address & 0x3FFFFFFF),
  };

  return bits;
}

// Start counting towards the least significant bit
static
void print_binary(u64 bits, usize start, usize count)
{
  for (usize i = 0; i < count; i++)
  {
    u64 shift = start - 1 - i;
    u64 bit = (bits >> shift) & 1;
    printf("%c", bit ? '1' : '0');
  }
}

static
void print_virtual_address(const char *label, Virtual_Address_Bits bits)
{
  printf("%s|%3u|%3u|%3u|%3u|%10u\n", label,
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

    print_virtual_address("4KB", bits_4KB);
    print_virtual_address("2MB", bits_2MB);
    print_virtual_address("1GB", bits_1GB);
  }

  void *address = os_allocate(1024 * 1024, OS_ALLOCATION_COMMIT);
  print_binary((u64)address, 64, 64);
  printf("\n");
}
