#include "common.h"

typedef struct Arg_Option Arg_Option;
struct Arg_Option
{
  Arg_Option *hash_next;
  u32        hash;
  String     name;
  String     *values;
  isize      value_count;
};

typedef struct Argument_Table Argument_Table;
struct Argument_Table
{
  String *raw_strings;
  isize  raw_strings_count;

  Arg_Option *option_table;
  isize      option_table_count;

  isize *positional_indices; // Array of indices into raw string array
  isize positional_count;
};

static
Arg_Option *get_arg_option_bucket(Argument_Table *table, String name)
{
  Arg_Option *bucket = NULL;

  if (table->option_table_count)
  {
    u32 hash = string_hash_u32(name);

    isize index = hash % table->option_table_count;

    bucket = table->option_table + index;
  }

  return bucket;
}

static
Arg_Option *get_arg_option_from_bucket(Arg_Option *bucket, String name)
{
  Arg_Option *result = NULL;

  for (Arg_Option *cursor = bucket; cursor; cursor = cursor->hash_next)
  {
    if (strings_equal(cursor->name, name))
    {
      result = cursor;
      break;
    }
  }

  return result;
}

static
Arg_Option *find_arg_option(Argument_Table *table, String name)
{
  return get_arg_option_from_bucket(get_arg_option_bucket(table, name), name);
}

static
Arg_Option *insert_arg_option(Arena *arena, Argument_Table *table, String name)
{
  Arg_Option *result = NULL;

  Arg_Option *bucket = get_arg_option_bucket(table, name);
  Arg_Option *exists = get_arg_option_from_bucket(bucket, name);

  // We already inserted it
  if (exists)
  {
    result = exists;
  }
  else
  {
    // Collision
    if (bucket->hash) // HACK: not safe... hash can be 0
    {
      result = arena_new(arena, Arg_Option);
      // Insert at head
      result->hash_next = bucket->hash_next;
      bucket->hash_next = result;
    }
    else
    {
      result = bucket;
    }

    result->hash = string_hash_u32(name);
    result->name = name;
  }

  return result;
}

// Start inclusive, end exclusive
String string_substring(String string, isize start, isize end)
{
  String result = {0};

  if (start >= 0 && end <= string.count && start < end)
  {
    result.data  = string.data + start;
    result.count = end - start;
  }

  return result;
}

isize string_find_substring(String to_check, isize start, String substring)
{
  isize result = -1;
  isize comparison_count = to_check.count - substring.count + 1;

  for (isize i = start; i < comparison_count; i++)
  {
    String to_compare = string_substring(to_check, i, i + substring.count);

    if (strings_equal(to_compare, substring))
    {
      result = i;
      break;
    }
  }

  return result;
}

static
Argument_Table parse_arguments(Arena *arena, i32 count, char **arguments)
{
  Argument_Table result = {0};

  result.raw_strings_count = count;
  result.raw_strings = arena_calloc(arena, result.raw_strings_count, String);
  for (i32 i = 1; i < count; i++)
  {
    char *c_string = arguments[i];

    String string = string_from_c_string(c_string);

    result.raw_strings[i] = string;
  }

  result.option_table_count = 64;
  result.option_table = arena_calloc(arena, result.option_table_count, Arg_Option);

  Arg_Option *current_argument = NULL;
  for (isize i = 0; i < result.raw_strings_count; i++)
  {
    String string = result.raw_strings[i];
    b32 is_option = true;

    // Option
    if (string_starts_with(String("--"), string))
    {
      string = string_advance(string, 2);
    }
    else if (string_starts_with(String("-"), string))
    {
      string = string_advance(string, 1);
    }
    // Positional
    else
    {
      is_option = false;
    }

    if (is_option)
    {
      isize values_delimeter_index = string_find_substring(string, 0, String("="));

      Arg_Option *argument = insert_arg_option(arena, &result, string);
    }

    // Its a positional
    else
    {
    }
  }

  return result;
}

b32 argument_table_has_flag(Argument_Table *table, String flag)
{
  return find_arg_option(table, flag) != NULL;
}
