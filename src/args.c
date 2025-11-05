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
  String program_name;

  Arg_Option *option_table;
  usize      option_table_count;

  usize  positionals_count;
  String positionals[32];
};

static
Arg_Option *get_arg_option_bucket(Args *args, String name)
{
  Arg_Option *bucket = NULL;

  if (args->option_table_count)
  {
    u32 hash = string_hash_u32(name);

    usize index = hash % args->option_table_count;

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
    if (string_match(cursor->name, name))
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
    if (bucket->name.data)
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
Args parse_args(Arena *arena, usize count, char **arguments)
{
  Args result = {0};
  result.program_name = string_from_c_string(arguments[0]);

  result.option_table_count = 64;
  result.option_table = arena_calloc(arena, result.option_table_count, Arg_Option);

  for (usize i = 1; i < count; i++)
  {
    String string = string_from_c_string(arguments[i]);

    b32 is_option = true;

    // Option
    if (string_starts_with(string, String("--")))
    {
      string = string_skip(string, 2);
    }
    else if (string_starts_with(string, String("-")))
    {
      string = string_skip(string, 1);
    }
    // Positional
    else
    {
      is_option = false;
    }

    if (is_option)
    {
      usize values_delimeter_idx = string_find_substring(string, 0, String("="));

      String name = string_substring(string, 0, values_delimeter_idx);

      String values_substring = string_substring(string, values_delimeter_idx, string.count);
      values_substring = string_skip(values_substring, 1); // Skip the delimiter

      // Add any values
      String_Array values = string_split(arena, values_substring, String(","));

      insert_arg_option(arena, &result, name, values);
    }

    // Its a positional
    else
    {
      ASSERT(result.positionals_count < STATIC_COUNT(result.positionals), "Too many positional arguments for parsing");
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
