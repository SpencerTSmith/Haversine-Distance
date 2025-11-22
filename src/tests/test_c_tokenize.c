#define COMMON_IMPLEMENTATION
#include "../common.h"

#include "../c_tokenize.c"


int main(int argc, char **argv)
{
  Arena arena = arena_make();
  {
    const char *label = "Hello, world!";
    String sample_program =
      STR(
        "int main(int argc, char **argv)\n"
        "{\n"
        "  printf(\"Hello, world!\\n\");\n"
        "  return 0;\n"
        "}\n"
      );

    C_Token_Array tokens = tokenize_c_code(&arena, sample_program);
    for EACH_INDEX(token_idx, tokens.count)
    {
      C_Token token = tokens.v[token_idx];
      printf("Token %lu: %s ( '%.*s' )\n",
             token_idx, C_Token_Type_strings[token.type], STRF(token.value));
    }
  }

}
