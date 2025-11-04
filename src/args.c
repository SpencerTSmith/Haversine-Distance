#include "common.h"

typedef struct Arg_Option Arg_Option;
struct Arg_Option
{
  Arg_Option   *hash_next;
  u32          hash;
  String       name;
  String_Array values;
};

typedef struct Argument_Table Args;
struct Argument_Table
{
  String_Array raw_strings;

  Arg_Option *option_table;
  isize      option_table_count;

  isize  positionals_count;
  String positionals[32];
};

static
Arg_Option *get_arg_option_bucket(Args *args, String name)
{
  Arg_Option *bucket = NULL;

  if (args->option_table_count)
  {
    u32 hash = string_hash_u32(name);

    isize index = hash % args->option_table_count;

    bucket = args->option_table + index;
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
Arg_Option *find_arg_option(Args *args, String name)
{
  return get_arg_option_from_bucket(get_arg_option_bucket(args, name), name);
}

static
Arg_Option *insert_arg_option(Arena *arena, Args *args, String name, String_Array values)
{
  Arg_Option *result = NULL;

  Arg_Option *bucket = get_arg_option_bucket(args, name);
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
    result->values = values;
  }

  return result;
}

static
Args parse_args(Arena *arena, i32 count, char **arguments)
{
  Args result = {0};

  result.raw_strings = arena_array(arena, count, String);
  for (i32 i = 1; i < count; i++)
  {
    char *c_string = arguments[i];

    String string = string_from_c_string(c_string);

    result.raw_strings.data[i] = string;
  }

  result.option_table_count = 64;
  result.option_table = arena_calloc(arena, result.option_table_count, Arg_Option);

  for (isize i = 0; i < result.raw_strings.count; i++)
  {
    String string = result.raw_strings.data[i];
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

      String name_substring = string_substring(string, 0, values_delimeter_index);

      String values_substring = string_substring(string, values_delimeter_index, string.count);
      values_substring = string_advance(values_substring, 1); // Skip the delimiter

      // Add any values
      String_Array values = {0};

      isize last_comma_idx = -1;
      for (isize char_idx = 0; char_idx < values_substring.count; char_idx++)
      {
        u8 c = values_substring.data[char_idx];

        // Start is always the last comma + 1, and since we start that as -1 the first value to extract starts at 0 index
        isize start = last_comma_idx + 1;;
        isize end   = 0;
        if (c == ',')
        {
          end   = char_idx;
          last_comma_idx = char_idx;
        }
        else if (char_idx == values_substring.count - 1)
        {
          end = values_substring.count;
        }

        // If we actually do have a value to extract
        if (end)
        {
          array_add(arena, values,
                    string_substring(values_substring, start, end));
        }
      }

      insert_arg_option(arena, &result, name_substring, values);
    }

    // Its a positional
    else
    {
      result.positionals[result.positionals_count] = string;
      result.positionals_count += 1;
    }
  }

  return result;
}

static
b32 args_has_flag(Args *table, String flag)
{
  return find_arg_option(table, flag) != NULL;
}

static
String_Array args_get_option_values(Args *table, String option)
{
  return find_arg_option(table, option)->values;
}
