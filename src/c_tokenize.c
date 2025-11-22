#include "common.h"

#define C_Token_Type(X)               \
  X(C_TOKEN_NONE)                     \
  X(C_TOKEN_OPEN_PARENTHESIS)         \
  X(C_TOKEN_OPEN_CURLY_BRACE)         \
  X(C_TOKEN_OPEN_SQUARE_BRACE)        \
  X(C_TOKEN_CLOSE_PARENTHESIS)        \
  X(C_TOKEN_CLOSE_CURLY_BRACE)        \
  X(C_TOKEN_CLOSE_SQUARE_BRACE)       \
  X(C_TOKEN_STAR)                     \
  X(C_TOKEN_PLUS)                     \
  X(C_TOKEN_MINUS)                    \
  X(C_TOKEN_LITERAL_STRING)           \
  X(C_TOKEN_LITERAL_INT)              \
  X(C_TOKEN_KEYWORD_INT)              \
  X(C_TOKEN_KEYWORD_CHAR)             \
  X(C_TOKEN_IDENTIFIER)               \
  X(C_TOKEN_EOF)

ENUM_TABLE(C_Token_Type);

typedef struct C_Token C_Token;
struct C_Token
{
  C_Token_Type type;
  String value;
};

typedef struct C_Lexer C_Lexer;
struct C_Lexer
{
  String source;
  usize  at;
};

DEFINE_ARRAY(C_Token);

static
b32 c_lexer_incomplete(C_Lexer lexer)
{
  return lexer.at < lexer.source.count;
}

static
u8 *c_lexer_at(C_Lexer lexer)
{
  ASSERT(c_lexer_incomplete(lexer), "Out of bounds access in C lexer.");
  return lexer.source.v + lexer.at;
}

static
void c_lexer_advance(C_Lexer *lexer, usize count)
{
  // FIXME: hmm
  usize max  = lexer->source.count;
  usize wish = lexer->at + count;
  usize real = wish < max ? count : max - lexer->at;

  lexer->at += real;
}

static
String c_lexer_get_token_value(C_Lexer *lexer, usize count)
{
  // FIXME: hmm
  usize max  = lexer->source.count;
  usize wish = lexer->at + count;
  usize real = wish < max ? count : max - lexer->at;

  String result =
  {
    .v = c_lexer_at(*lexer),
    .count = real,
  };

  c_lexer_advance(lexer, result.count);

  return result;
}

static
void c_lexer_eat_whitespace(C_Lexer *lexer)
{
  while (c_lexer_incomplete(*lexer))
  {
    u8 curr_char = *c_lexer_at(*lexer);
    if (char_is_whitespace(curr_char))
    {
      c_lexer_advance(lexer, 1);
    }
    else
    {
      break;
    }
  }
}

static
C_Token_Array tokenize_c_code(Arena *arena, String code)
{
  C_Token_Array result = {0};

  C_Lexer lexer =
  {
    .source = code,
    .at = 0,
  };

  // TODO: Not thrilled about this comma operator here, but can't think of anything nicer
  // to do yet
  while (c_lexer_eat_whitespace(&lexer), c_lexer_incomplete(lexer))
  {
    u8 curr_char = *c_lexer_at(lexer);

    C_Token token = {0};

    // TODO: Could potentially just do a lookup table indexed by ascii code for these
    // would collapse this code into one
    switch (curr_char)
    {
      case '(':
      {
        token.type = C_TOKEN_OPEN_PARENTHESIS;
        token.value = c_lexer_get_token_and_advance(&lexer, 1);
      }
      break;
      case ')':
      {
        token.type = C_TOKEN_CLOSE_PARENTHESIS;
        token.value = c_lexer_get_token_and_advance(&lexer, 1);
      }
      break;
      case '{':
      {
        token.type = C_TOKEN_OPEN_CURLY_BRACE;
        token.value = c_lexer_get_token_and_advance(&lexer, 1);
      }
      break;
      case '}':
      {
        token.type = C_TOKEN_CLOSE_CURLY_BRACE;
        token.value = c_lexer_get_token_and_advance(&lexer, 1);
      }
      break;
      case '*':
      {
        token.type = C_TOKEN_STAR;
        token.value = c_lexer_get_token_and_advance(&lexer, 1);
      }
      break;
      case '+':
      {
        token.type = C_TOKEN_PLUS;
        token.value = c_lexer_get_token_and_advance(&lexer, 1);
      }
      break;
      case '-':
      {
        token.type = C_TOKEN_MINUS;
        token.value = c_lexer_get_token_and_advance(&lexer, 1);
      }
      break;
    }

    // Not an easy one...
    if (token.type == C_TOKEN_NONE)
    {
      if (char_is_alphabetic(curr_char) || curr_char == '_')
      {

      }
      else if (curr_char == '"')
      {

      }
      else if (char_is_digit(curr_char))
      {

      }
    }

    if (token.type != C_TOKEN_NONE)
    {
      array_add(arena, result, token);
    }
  }

  return result;
}
