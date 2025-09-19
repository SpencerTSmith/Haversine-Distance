#include "common.h"
#include "json_parse.c"

#define DESIRED_ARG_COUNT 2 + 1

int main(int args_count, char **args)
{
  if (args_count != DESIRED_ARG_COUNT)
  {
    printf("Usage: %s [haversine_json] [solution_dump]\n", args[0]);
  }

  u8 buffer[KB(8)] = {0};
  usize read_bytes = read_file_to_memory(args[1], buffer, KB(8));

  String in_json =
  {
    .data  = buffer,
    .count = read_bytes,
  };

  printf("%s")
}
