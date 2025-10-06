#define COMMON_IMPLEMENTATION
#include "common.h"

#include "json_parse.c"
#include "haversine_impl.c"

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
      f64 x0 = json_object_to_f64(lookup_json_object(cursor, String("x0")));
      f64 y0 = json_object_to_f64(lookup_json_object(cursor, String("y0")));
      f64 x1 = json_object_to_f64(lookup_json_object(cursor, String("x1")));
      f64 y1 = json_object_to_f64(lookup_json_object(cursor, String("y1")));

      f64 sphere_radius = 1.0;

      reference_haversine(x0, y0, x1, y1, sphere_radius);

      printf("%f, %f, %f, %f\n", x0, y0, x1, y1);
    }
  }

  arena_free(&arena);
}
