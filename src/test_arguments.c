#define COMMON_IMPLEMENTATION
#include "common.h"
#include "args.c"

int main(int argc, char **argv)
{
  Arena arena = arena_make();
  Args arguments = parse_args(&arena, argc, argv);

  printf("\nProgram Name: %.*s\n", String_Format(arguments.program_name));

  if (args_has_flag(&arguments, String("foo")))
  {
    printf("Has foo flag!\n");
  }

  for (isize slot = 0; slot < arguments.option_table_count; slot++)
  {
    Arg_Option *first = arguments.option_table + slot;

    // Filled bucket
    if (first->name.data)
    {
      for (Arg_Option *node = first; node; node = node->hash_next)
      {
        printf("Option: %.*s\n", String_Format(node->name));
        for (isize i = 0; i < node->values.count; i++)
        {
          printf("  Value: %.*s\n", String_Format(node->values.data[i]));
        }
      }
    }
  }

  for (isize i = 0; i < arguments.positionals_count; i++)
  {
    printf("Positional %td: %.*s\n", i, String_Format(arguments.positionals[i]));
  }
}
