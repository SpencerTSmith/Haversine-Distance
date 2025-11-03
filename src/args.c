#include "common.h"

typedef struct Argument Argument;
struct Argument
{
  u32      hash;
  Argument *hash_next;
  String   name;
  String   *values;
  isize    value_count;
};

typedef struct Argument_Table Argument_Table;
struct Argument_Table
{
  String   *raw_strings;
  isize    raw_strings_count;
  Argument *table_array;
  isize    table_array_count;
};

static
Argument *get_argument_bucket(Argument_Table *table, String name)
{
  Argument *bucket = NULL;

  if (table->table_array_count)
  {
    u32 hash = u32_hash_string(name);
    isize index = hash % table->table_array_count;

    bucket = table->table_array + index;
    printf("%.*s (%lu) = %u = %td\n", String_Format(name), name.count, hash, index);
  }

  return bucket;
}

static
Argument *get_argument_from_bucket(Argument *bucket, String name)
{
  Argument *result = NULL;

  for (Argument *cursor = bucket; cursor; cursor = cursor->hash_next)
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
Argument *find_argument(Argument_Table *table, String name)
{
  return get_argument_from_bucket(get_argument_bucket(table, name), name);
}

static
Argument *insert_argument_into_table(Arena *arena, Argument_Table *table, String name)
{
  Argument *result = NULL;

  Argument *bucket = get_argument_bucket(table, name);
  Argument *exists = get_argument_from_bucket(bucket, name);

  // We already inserted it
  if (exists)
  {
    result = exists;
  }
  else
  {
    // Collision
    if (bucket->hash)
    {
      result = arena_new(arena, Argument);
      bucket->hash_next = result;
      LOG_INFO("Collision!");
    }
    else
    {
      result = bucket;
      LOG_INFO("No Collision!");
    }

    result->hash = u32_hash_string(name);
    result->name = name;
  }

  return result;
}

static
Argument_Table parse_arguments(Arena *arena, i32 count, char **arguments)
{
  Argument_Table result = {0};

  result.raw_strings_count = count;
  result.raw_strings = arena_calloc(arena, result.raw_strings_count, String);
  for (i32 i = 0; i < count; i++)
  {
    char *c_string = arguments[i];

    String string = string_from_c_string(c_string);

    result.raw_strings[i] = string;
  }

  result.table_array_count = 64;
  result.table_array = arena_calloc(arena, result.table_array_count, Argument);

  b32 parsing_values = false;
  Argument *current_argument = NULL;
  for (isize i = 0; i < result.raw_strings_count; i++)
  {
    Argument argument = {0};

    String name = result.raw_strings[i];

    // Flag!
    if (string_starts_with(String("--"), name))
    {
      parsing_values = false;
      name = string_advance(name, 2);
    }
    else if (string_starts_with(String("-"), name))
    {
      parsing_values = false;
      name = string_advance(name, 1);
    }

    // Values
    else
    {
      parsing_values = true;
    }

    if (parsing_values)
    {
    }
    else
    {
      Argument *key = insert_argument_into_table(arena, &result, name);
    }
  }

  Argument *test = find_argument(&result, String("bloop"));
  if (test)
  {
    printf("%.*s\n", String_Format(test->name));
  }
  else
  {
    printf("No!\n");
  }

  return result;
}
