#include "common.h"
#include "haversine_impl.c"

#include <stdlib.h>
#include <math.h>

#define DESIRED_ARG_COUNT 3 + 1

int main(int arg_count, char **args)
{
  if (arg_count != DESIRED_ARG_COUNT)
  {
    printf("Usage: %s [uniform/cluster] [seed] [pair count]\n", args[0]);
    return 1;
  }

  FILE *json_file = fopen("haversine_pairs.json", "w");
  if (!json_file)
  {
    printf("Unable to open json file for writing.\n");
    return 1;
  }

  u32 seed = atoi(args[2]);
  srand(seed);

  i32 pair_count = atoi(args[3]);

  f64 *haversines = (f64 *)calloc(pair_count, sizeof(f64));
  if (!haversines)
  {
    printf("Unable to allocate buffer for haversine values.\n");
    return 1;
  }

  f64 haversine_sum = 0.0;

  fprintf(json_file, "{\"pairs\" : [\n");
  char delimiter[2] = ""; // Nothing to begin with
  for (isize i = 0; i < pair_count; i++)
  {
    f64 inv_range_max = 1 / (f64)RAND_MAX;

    f64 x0 = ((f64)rand() * inv_range_max * 360) - 180;
    f64 y0 = ((f64)rand() * inv_range_max * 180) - 90;
    f64 x1 = ((f64)rand() * inv_range_max * 360) - 180;
    f64 y1 = ((f64)rand() * inv_range_max * 180) - 90;

    fprintf(json_file, "%s  ", delimiter);
    delimiter[0] = ','; // After first it is a comma
    delimiter[1] = '\n';

    fprintf(json_file, "{\"x0\":%f, \"y0\":%f, \"x1\":%f, \"y1\":%f}", x0, y0, x1, y1);

    // Do reference haversine
    f64 earth_radius = 6372.8;
    haversines[i] = reference_haversine(x0, y0, x1, y1, earth_radius);
    haversine_sum += haversines[i];
  }
  fprintf(json_file, "\n]}\n");
  fclose(json_file);

  haversine_sum /= pair_count;
  printf("%f\n", haversine_sum);

  free(haversines);
}
