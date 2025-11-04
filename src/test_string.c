#define COMMON_IMPLEMENTATION
#include "common.h"

int main(int argc, char **argv)
{
  {
    const char *label = "strings_equal";
    String string = String("Foo");
    PRINT_EVAL(label, strings_equal(string, String("Foo")),   true);
    PRINT_EVAL(label, strings_equal(string, String("Bar")),   false);
    PRINT_EVAL(label, strings_equal(string, String("Foo\n")), false);
    PRINT_EVAL(label, strings_equal(string, String(" Foo ")), false);
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
    PRINT_EVAL(label, strings_equal(string_skip(string, 1), String("kipper")), true);
    PRINT_EVAL(label, strings_equal(string_skip(string, 2), String("ipper")),  true);
    PRINT_EVAL(label, strings_equal(string_skip(string, 8), String("")),       true);
  }

  {
    const char *label = "string_trim_white_space";
    PRINT_EVAL(label, strings_equal(string_trim_whitespace(String("  Foo")), String("Foo")), true);
    PRINT_EVAL(label, strings_equal(string_trim_whitespace(String("Foo  ")), String("Foo")), true);
    PRINT_EVAL(label, strings_equal(string_trim_whitespace(String("Foo\n")), String("Foo")), true);
  }
}
