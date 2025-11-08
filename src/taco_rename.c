#define COMMON_IMPLEMENTATION
#include "common.h"

int main(int argc, char **argv)
{
  Arena arena = arena_make();
  Args args = parse_args(&arena, argc, argv);

  if (args.positionals_count)
  {
    String file = args.positionals[0];

    printf("Renaming in %.*s\n", String_Format(file));
    char *_file = string_to_c_string(&arena, file); // Ugh
    String code = read_file_to_arena(&arena, _file);

    String_Array lines = string_split(&arena, code, String("\n"));
    String_List result = {0};
    for (usize line_idx = 0; line_idx < lines.count; line_idx++)
    {
      String line = lines.v[line_idx];
      String_Array tokens = string_split_whitepace(&arena, line);

      for (usize tok_idx = 0; tok_idx < lines.count; tok_idx++)
      {

      }
    }
  }
  else
  {
    LOG_ERROR("No file passed.");
  }
}
