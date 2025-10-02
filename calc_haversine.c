#define COMMON_IMPLEMENTATION
#include "common.h"
#include "json_parse.c"

#define DESIRED_ARG_COUNT 2 + 1

int main(int args_count, char **args)
{
  if (args_count != DESIRED_ARG_COUNT)
  {
    printf("Usage: %s [haversine_json] [solution_dump]\n", args[0]);
    return 1;
  }

  Arena arena = arena_make(KB(8));
  parse_json(&arena, args[1]);

  arena_free(&arena);
}
