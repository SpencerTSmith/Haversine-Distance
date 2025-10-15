#define COMMON_IMPLEMENTATION
#include "common.h"

#include "profile.c"
#include "json_parse.c"
#include "haversine_impl.c"

#define DESIRED_ARG_COUNT 2 + 1

static
b32 epsilon_equal(f64 a, f64 b)
{
  f64 epsilon = 0.00001;

  return (fabs(a) - fabs(b)) <= epsilon;
}

int main(int args_count, char **args)
{
  if (args_count != DESIRED_ARG_COUNT)
  {
    printf("Usage: %s [haversine_json] [solution_dump]\n", args[0]);
    return 1;
  }

  begin_profiling();

  Arena arena = {0};
  arena = arena_make(GB(4));

  String source = {0};
  PROFILE_SCOPE("read")
  {
    source = read_file_to_arena(&arena, args[1]);
  }

  Haversine_Pair *pairs = NULL;
  i32 pair_count = 0;
  usize max_pairs = 0;
  PROFILE_SCOPE("haversine alloc")
  {
    usize min_pair_bytes = 6 * 4; // 6 chars for something like "x0:0" (at least) and 4 of those
    max_pairs = source.count / min_pair_bytes; // Roughly, overestimate at least

    pairs = arena_calloc(&arena, max_pairs, Haversine_Pair);
    pair_count = 0;
  }

  JSON_Object *root = NULL;
  root = parse_json(&arena, source);

  f64 haversine_sum = 0.0;

  JSON_Object *pairs_object = lookup_json_object(root, String("pairs"));
  if (pairs)
  {
    for (JSON_Object *cursor = pairs_object->first_child; cursor && pair_count < max_pairs; cursor = cursor->next_sibling)
    {
      PROFILE_SCOPE("child convert")
      {
        Haversine_Pair pair =
        {
          .x0 = json_object_to_f64(lookup_json_object(cursor, String("x0"))),
          .y0 = json_object_to_f64(lookup_json_object(cursor, String("y0"))),
          .x1 = json_object_to_f64(lookup_json_object(cursor, String("x1"))),
          .y1 = json_object_to_f64(lookup_json_object(cursor, String("y1"))),
        };

        pairs[pair_count] = pair;
        pair_count += 1;
      }
    }
  }

  f64 sum = 0.0;
  PROFILE_SCOPE("sum")
  {
    for (usize i = 0; i < pair_count; i++)
    {
      f64 earth_radius = 6372.8;
      f64 result = reference_haversine(pairs[i].x0,pairs[i].y0,pairs[i].x1,pairs[i].y1, earth_radius);
      sum += result;
    }
    sum /= pair_count;
  }

  PROFILE_SCOPE("check")
  {
    // Get solutions out of binary dump and verify
    String solution_dump = read_file_to_arena(&arena, args[2]);
    if (solution_dump.count >= sizeof(f64) + sizeof(i32))
    {
      f64 solution_sum   = *(f64 *)solution_dump.data;
      i32 solution_pairs = *(i32 *)(solution_dump.data + sizeof(f64));

      if (solution_pairs == pair_count)
      {
        if (epsilon_equal(solution_sum, sum))
        {
          LOG_INFO("Solutions (solution: %f, calculated: %f) match! :)", solution_sum, sum);
        }
        else
        {
          LOG_ERROR("Solution sum (%f) does not match calculated sum (%f)", solution_sum, sum);
        }
      }
      else
      {
        LOG_ERROR("Solution pair counts (%d) and parsed pair count (%d) do not match", solution_pairs, pair_count);
      }
    }
    else
    {
      LOG_ERROR("Solution dump is not large enough to hold actual solutions");
    }
  }

  PROFILE_SCOPE("free")
  {
    arena_free(&arena);
  }

  end_profiling();
}
