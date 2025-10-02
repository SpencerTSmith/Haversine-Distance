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

  Arena arena = arena_make(MB(8));

  JSON_Object *outer = parse_json(&arena, args[1]);

  JSON_Object *pairs = lookup_json_object(outer, String("pairs"));
  if (pairs)
  {
    for (JSON_Object *cursor = pairs->first_child; cursor; cursor = cursor->next_sibling)
    {
      JSON_Object *x0 = lookup_json_object(cursor, String("x0"));
      JSON_Object *y0 = lookup_json_object(cursor, String("y0"));
      JSON_Object *x1 = lookup_json_object(cursor, String("x1"));
      JSON_Object *y1 = lookup_json_object(cursor, String("y1"));

      printf("x0 : %.*s\n", String_Format(x0->value));
      printf("y0 : %.*s\n", String_Format(y0->value));
      printf("x1 : %.*s\n", String_Format(x1->value));
      printf("y1 : %.*s\n", String_Format(y1->value));
    }
  }

  arena_free(&arena);
}
