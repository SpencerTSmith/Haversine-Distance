#define COMMON_IMPLEMENTATION
#include "common.h"
#include "args.c"

int main(int argc, char **argv)
{
  Arena arena = arena_make();
  Argument_Table arguments = parse_arguments(&arena, argc, argv);

  for (isize i = 0; i < arguments.raw_strings.count; i++)
  {
    printf("Raw %td: %.*s\n", i, String_Format(arguments.raw_strings.data[i]));
  }

  if (argument_table_has_flag(&arguments, String("foo")))
  {
    printf("Yay!\n");
  }

  Arg_Option *arg = find_arg_option(&arguments, String("baz"));
  if (arg)
  {
    for (isize i = 0; i < arg->values.count; i++)
    {
      printf("Value of %.*s: %.*s\n", String_Format(arg->name), String_Format(arg->values.data[i]));
    }
  }

  for (isize i = 0; i < arguments.positionals_count; i++)
  {
    printf("Positional %td: %.*s\n", i, String_Format(arguments.positionals[i]));
  }
}
