#define COMMON_IMPLEMENTATION
#include "../common.h"

int main(int argc, char **argv)
{
  Arena arena = arena_make();
  Args arguments = parse_args(&arena, argc, argv);

  // printf("\nVisual Check -----\n");
  // {
  //   printf("Program Name: %.*s\n", String_Format(arguments.program_name));
  //
  //   for (usize i = 0; i < arguments.positionals_count; i++)
  //   {
  //     printf("Positional %td: %.*s\n", i, String_Format(arguments.positionals[i]));
  //   }
  //
  //   for (usize slot = 0; slot < arguments.option_table_count; slot++)
  //   {
  //     Arg_Option *first = arguments.option_table + slot;
  //
  //     // Filled bucket
  //     if (first->name.data)
  //     {
  //       for (Arg_Option *node = first; node; node = node->hash_next)
  //       {
  //         printf("Option: %.*s\n", String_Format(node->name));
  //         for (usize i = 0; i < node->values.count; i++)
  //         {
  //           printf("  Value: %.*s\n", String_Format(node->values.data[i]));
  //         }
  //       }
  //     }
  //   }
  // }

  // Test and such
  {
    const char *label = "args_has_flag";
    PRINT_EVAL(label, args_has_flag(&arguments, String("foo")));
  }

  {
    const char *label = "args_get_option_values";
    String_Array values = args_get_option_values(&arguments, String("baz"));
    PRINT_EVAL(label, string_match(values.data[0], String("foo")));
    PRINT_EVAL(label, string_match(values.data[1], String("bar")));
    PRINT_EVAL(label, string_match(values.data[2], String("boo")));
  }

  {
    const char *label = "args_get_option_values";
    String_Array values = args_get_option_values(&arguments, String("bunk"));
    PRINT_EVAL(label, string_match(values.data[0], String("bip")));
    PRINT_EVAL(label, string_match(values.data[1], String("bop")));
    PRINT_EVAL(label, string_match(values.data[2], String("bam")));
  }

  {
    const char *label = "args_positionals";
    String *positionals = arguments.positionals;
    PRINT_EVAL(label, arguments.positionals_count == 2);
    PRINT_EVAL(label, string_match(positionals[0], String("positional")));
    PRINT_EVAL(label, string_match(positionals[1], String("positional2")));
  }
}
