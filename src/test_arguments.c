#define COMMON_IMPLEMENTATION
#include "common.h"
#include "args.c"

int main(int argc, char **argv)
{
  Arena arena = arena_make();
  Argument_Table arguments = parse_arguments(&arena, argc, argv);
}
