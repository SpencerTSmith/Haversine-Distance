#define COMMON_IMPLEMENTATION
#include "common.h"
#include "args.c"

int main(int argc, char **argv)
{
  Arena arena = arena_make();
  Args arguments = parse_args(&arena, argc, argv);

  for (isize i = 0; i < arguments.raw_strings.count; i++)
  {
    printf("Raw %td: %.*s\n", i, String_Format(arguments.raw_strings.data[i]));
  }

  if (args_has_flag(&arguments, String("foo")))
  {
    printf("Has foo flag!\n");
  }

  String_Array baz_vals = args_get_option_values(&arguments, String("baz"));
  for (isize i = 0; i < baz_vals.count; i++)
  {
    printf("Value: %.*s\n", String_Format(baz_vals.data[i]));
  }

  for (isize i = 0; i < arguments.positionals_count; i++)
  {
    printf("Positional %td: %.*s\n", i, String_Format(arguments.positionals[i]));
  }
}
