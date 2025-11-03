#define COMMON_IMPLEMENTATION
#include "common.h"
#include "args.c"

int main(int argc, char **argv)
{
  Arena arena = arena_make();
  Argument_Table arguments = parse_arguments(&arena, argc, argv);

  if (argument_table_has_flag(&arguments, String("bloop")))
  {
    printf("Yay!\n");
  }

  printf("%td", string_find_substring(String("Arkham"), 0, String("ham")));
}
