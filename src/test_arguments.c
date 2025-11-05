#define COMMON_IMPLEMENTATION
#include "common.h"
#include "args.c"

int main(int argc, char **argv)
{
  Arena arena = arena_make();
  Args arguments = parse_args(&arena, argc, argv);

  // // Visual check
  //
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
  //
  // printf("\nTests ---------\n");

  // Test and such
  {
    const char *label = "args_has_flag";
    PRINT_EVAL(label, args_has_flag(&arguments, String("foo")), true);
  }

  {
    const char* label = "args_get_option_values";
    String_Array values = args_get_option_values(&arguments, String("bunk"));
    PRINT_EVAL(label, string_match(values.data[0], String("bip")), true);
    PRINT_EVAL(label, string_match(values.data[1], String("bop")), true);
    PRINT_EVAL(label, string_match(values.data[2], String("bam")), true);
  }
}
