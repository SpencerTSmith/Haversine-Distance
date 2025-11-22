#include <stdlib.h>

int main()
{
  int *test = malloc(4 * 1024);
  free(test);
  // test[0] = 10;
  // test[1] = 10;
  // test[1000] = 10;
}
