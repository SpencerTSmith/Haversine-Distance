#define COMMON_IMPLEMENTATION
#include "../common.h"

int main(int argc, char **argv)
{
  {
    const char *label = "arena_alloc / arena_make";
    Arena arena = arena_make();
    u8 *mem1 = arena_alloc(&arena, 16, 8);
    u8 *mem2 = arena_alloc(&arena, 32, 16);

    PRINT_EVAL(label, mem1 != NULL, true);
    PRINT_EVAL(label, mem2 != NULL, true);
    PRINT_EVAL(label, mem2 > mem1, true);

    arena_clear(&arena);
    u8 *mem3 = arena_alloc(&arena, 8, 4);
    PRINT_EVAL(label, mem3 == arena.base, true);

    arena_free(&arena);
  }

  {
    const char *label = "arena_calloc";
    Arena arena = arena_make();
    u32 *arr = arena_calloc(&arena, 4, u32);
    PRINT_EVAL(label, arr != NULL, true);
    PRINT_EVAL(label, arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0, true);

    arena_free(&arena);
  }

  {
    const char *label = "arena_array";
    Arena arena = arena_make();
    i32_Array array = arena_array(&arena, 4, i32);

    array.data[0] = 10;
    array.data[1] = 20;
    array.data[2] = 30;
    array.data[3] = 40;

    PRINT_EVAL(label, array.count == 4, true);
    PRINT_EVAL(label, array.data[0] == 10 && array.data[1] == 20 && array.data[2] == 30 && array.data[3] == 40, true);

    arena_free(&arena);
  }

  {
    const char *label = "array_add";
    Arena arena = arena_make();
    i32_Array array = {0};

    i32 val1 = 42;
    i32 val2 = 17;
    int *added1 = array_add(&arena, array, val1);
    int *added2 = array_add(&arena, array, val2);

    PRINT_EVAL(label, added1 != NULL && added2 != NULL, true);
    PRINT_EVAL(label, array.count == 2, true);
    PRINT_EVAL(label, array.data[0] == 42 && array.data[1] == 17, true);

    arena_free(&arena);
  }

  {
    const char *label = "arena_pop / arena_pop_to";
    Arena arena = arena_make();
    u32 *mem = arena_calloc(&arena, 3, u32);
    mem[0] = 1;
    mem[1] = 2;
    mem[2] = 3;

    usize saved_offset = arena.next_offset;
    arena_pop(&arena, sizeof(u32));
    PRINT_EVAL(label, arena.next_offset == saved_offset - sizeof(u32), true);

    arena_pop_to(&arena, 0);
    PRINT_EVAL(label, arena.next_offset == 0, true);

    arena_free(&arena);
  }

  {
    const char *label = "scratch_begin / scratch_end";
    Arena arena = arena_make();
    u32 *mem = arena_calloc(&arena, 5, u32);
    mem[0] = 1;
    Scratch scratch = scratch_begin(&arena);
    u32 *temp = arena_calloc(&arena, 10, u32);
    temp[1] = 1;
    scratch_close(&scratch);
    PRINT_EVAL(label, arena.next_offset == 5 * sizeof(u32), true);

    arena_free(&arena);
  }

  Arena arena = arena_make();
  {
    const char *label = "char_is_whitespace";
    PRINT_EVAL(label, char_is_whitespace(' '),  true);
    PRINT_EVAL(label, char_is_whitespace('\n'), true);
    PRINT_EVAL(label, char_is_whitespace('\t'), true);
    PRINT_EVAL(label, char_is_whitespace('A'),  false);
    PRINT_EVAL(label, char_is_whitespace('1'),  false);
  }

  {
    const char *label = "char_is_digit";
    PRINT_EVAL(label, char_is_digit('0'), true);
    PRINT_EVAL(label, char_is_digit('5'), true);
    PRINT_EVAL(label, char_is_digit('9'), true);
    PRINT_EVAL(label, char_is_digit('a'), false);
    PRINT_EVAL(label, char_is_digit(' '), false);
  }

  {
    const char *label = "string_hash_u32";
    String string1 = String("Hello");
    String string2 = String("Hello");
    String string3 = String("World");
    PRINT_EVAL(label, string_hash_u32(string1) == string_hash_u32(string2), true);
    PRINT_EVAL(label, string_hash_u32(string1) == string_hash_u32(string3), false);
  }

  {
    const char *label = "string_match";
    String string = String("Foo");
    PRINT_EVAL(label, string_match(string, String("Foo")),   true);
    PRINT_EVAL(label, string_match(string, String("Bar")),   false);
    PRINT_EVAL(label, string_match(string, String("Foo\n")), false);
    PRINT_EVAL(label, string_match(string, String(" Foo ")), false);
  }

  {
    const char *label = "string_starts_with";
    String string = String("Arkham");
    PRINT_EVAL(label, string_starts_with(string, String("A")),   true);
    PRINT_EVAL(label, string_starts_with(string, String("Ark")), true);
    PRINT_EVAL(label, string_starts_with(string, String("ham")), false);
  }

  {
    const char *label = "string_skip";
    String string = String("Skipper");
    PRINT_EVAL(label, string_match(string_skip(string, 1), String("kipper")), true);
    PRINT_EVAL(label, string_match(string_skip(string, 2), String("ipper")),  true);
    PRINT_EVAL(label, string_match(string_skip(string, string.count), String("")),  true);
    PRINT_EVAL(label, string_match(string_skip(string, 8), String("")),       true);
  }

  {
    const char *label = "string_chop";
    String string = String("Chopper");
    PRINT_EVAL(label, string_match(string_chop(string, 1), String("Choppe")), true);
    PRINT_EVAL(label, string_match(string_chop(string, 2), String("Chopp")), true);
    PRINT_EVAL(label, string_match(string_chop(string, string.count), String("")), true);
    PRINT_EVAL(label, string_match(string_chop(string, 10), String("")), true);
  }

  {
    const char *label = "string_trim_white_space";
    PRINT_EVAL(label, string_match(string_trim_whitespace(String("  Foo")), String("Foo")), true);
    PRINT_EVAL(label, string_match(string_trim_whitespace(String("Foo  ")), String("Foo")), true);
    PRINT_EVAL(label, string_match(string_trim_whitespace(String("Foo\n")), String("Foo")), true);
  }

  {
    const char *label = "string_substring";
    String string = String("SubstringTest");
    PRINT_EVAL(label, string_match(string_substring(string, 0, 6), String("Substr")), true);
    PRINT_EVAL(label, string_match(string_substring(string, 3, 9), String("string")), true);
    PRINT_EVAL(label, string_match(string_substring(string, 0, string.count), String("SubstringTest")), true);
    PRINT_EVAL(label, string_match(string_substring(string, 5, 20), String("ringTest")), true);
    PRINT_EVAL(label, string_match(string_substring(string, string.count, string.count), String("")), true);
  }

  {
    const char *label = "string_find_substring";
    String string = String("Find the needle in the haystack.");
    PRINT_EVAL(label, string_find_substring(string, 0, String("needle")) == 9, true);
    PRINT_EVAL(label, string_find_substring(string, 10, String("needle")) == string.count, true);
    PRINT_EVAL(label, string_find_substring(string, 0, String("haystack")) == 23, true);
    PRINT_EVAL(label, string_find_substring(string, 0, String("missing")) == string.count, true);
  }

  {
    const char *label = "string_split";
    String commas = String("Foo,bar,baz");
    String_Array commas_split = string_split(&arena, commas, String(","));
    b32 result = commas_split.count == 3;
    result = string_match(commas_split.data[0], String("Foo"));
    result = string_match(commas_split.data[1], String("bar"));
    result = string_match(commas_split.data[2], String("baz"));
    PRINT_EVAL(label, result, true);
  }

  {
    const char *label = "string_split";
    String commas = String("Foo, bar, baz");
    String_Array commas_split = string_split(&arena, commas, String(", "));
    b32 result = commas_split.count == 3;
    result = string_match(commas_split.data[0], String("Foo"));
    result = string_match(commas_split.data[1], String("bar"));
    result = string_match(commas_split.data[2], String("baz"));
    PRINT_EVAL(label, result, true);
  }

  {
    const char *label = "string_split";
    String spaces = String("Foo bar baz");
    String_Array space_split = string_split(&arena, spaces, String(" "));
    b32 result = space_split.count == 3;
    result = string_match(space_split.data[0], String("Foo"));
    result = string_match(space_split.data[1], String("bar"));
    result = string_match(space_split.data[2], String("baz"));
    PRINT_EVAL(label, result, true);
  }

  {
    const char *label = "string_split_whitespace";
    String ws = String("\n Foo  \n\nbar \r baz  \n");
    String_Array ws_split = string_split_whitepace(&arena, ws);
    PRINT_EVAL(label, ws_split.count == 3, true);
    PRINT_EVAL(label, string_match(ws_split.data[0], String("Foo")), true);
    PRINT_EVAL(label, string_match(ws_split.data[1], String("bar")), true);
    PRINT_EVAL(label, string_match(ws_split.data[2], String("baz")), true);
  }
}
