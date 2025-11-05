#define COMMON_IMPLEMENTATION
#include "../common.h"

int main(int argc, char **argv)
{
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
    const char *label = "string_hash_u32";
    String string1 = String("Hello");
    String string2 = String("Hello");
    String string3 = String("World");
    PRINT_EVAL(label, string_hash_u32(string1) == string_hash_u32(string2), true);
    PRINT_EVAL(label, string_hash_u32(string1) == string_hash_u32(string3), false);
  }

  {
    const char *label = "char_is_whitespace";
    PRINT_EVAL(label, char_is_whitespace(' '), true);
    PRINT_EVAL(label, char_is_whitespace('\n'), true);
    PRINT_EVAL(label, char_is_whitespace('\t'), true);
    PRINT_EVAL(label, char_is_whitespace('A'), false);
    PRINT_EVAL(label, char_is_whitespace('1'), false);
  }

  {
    const char *label = "char_is_digit";
    PRINT_EVAL(label, char_is_digit('0'), true);
    PRINT_EVAL(label, char_is_digit('5'), true);
    PRINT_EVAL(label, char_is_digit('9'), true);
    PRINT_EVAL(label, char_is_digit('a'), false);
    PRINT_EVAL(label, char_is_digit(' '), false);
  }
}
