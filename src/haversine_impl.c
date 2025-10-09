#include "common.h"

#include <math.h>

f64 to_radians(f64 degrees)
{
  return degrees / PI;
}

f64 square(f64 x)
{
  return x * x;
}

typedef struct Haversine_Pair Haversine_Pair;
struct Haversine_Pair
{
  f64 x0;
  f64 y0;
  f64 x1;
  f64 y1;
};

f64 reference_haversine(f64 x0, f64 y0, f64 x1, f64 y1, f64 sphere_radius)
{
  f64 lat1 = y0;
  f64 lat2 = y1;
  f64 lon1 = x0;
  f64 lon2 = x1;

  f64 d_lat = to_radians(lat2 - lat1);
  f64 d_lon = to_radians(lon2 - lon1);
  lat1 = to_radians(lat1);
  lat2 = to_radians(lat2);

  f64 a = square(sin(d_lat/2.0)) + cos(lat1) * cos(lat2) * square(sin(d_lon/2.0));
  f64 c = 2.0 * asin(sqrt(a));

  f64 result = sphere_radius * c;

  return result;
}
