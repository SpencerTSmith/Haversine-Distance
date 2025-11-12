#define COMMON_IMPLEMENTATION
#include "common.h"

struct
{
  String name;
  String rename;
}
rename_pairs[] =
{
  {str("int"), str("i32")},
  {str("int32_t"), str("i32")},
};

int main(int argc, char **argv)
{
  Arena arena = arena_make();
  Args args = parse_args(&arena, argc, argv);

  if (args.positionals_count)
  {
    String file = args.positionals[0];

    printf("Renaming in %.*s\n", strf(file));

    String code = read_file_to_arena(&arena, file);

    String_List result_lines = {0};

    String_Array lines = string_split(&arena, code, String("\n"));
    for (usize line_idx = 0; line_idx < lines.count; line_idx++)
    {
      String line = lines.v[line_idx];
      String_Array words = string_split_whitepace(&arena, line);

      String_Array renamed_words = {0};
      for (usize word_idx = 0; word_idx < words.count; word_idx++)
      {
        String word = words.v[word_idx];

        for (usize rename_idx = 0; rename_idx < STATIC_COUNT(rename_pairs); rename_idx++)
        {
          if (string_match(word, rename_pairs[rename_idx].name))
          {
            word = rename_pairs[rename_idx].rename;
            break;
          }
        }

        array_add(&arena, renamed_words, word);
      }

      String_Node *renamed_line = arena_new(&arena, String_Node);
      renamed_line->value = string_join_array(&arena, renamed_words, str(" "));
      list_push_last(result_lines, renamed_line);
    }

    String result = string_join_list(&arena, result_lines, str("\n"));
    printf("%.*s\n", strf(result));

  }
  else
  {
    LOG_ERROR("No file passed.");
  }

  arena_print_stats(&arena);
}
