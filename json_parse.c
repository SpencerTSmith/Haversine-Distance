#include "common.h"

typedef enum JSON_Token_Type
{
  JSON_TOKEN_EOF,

  JSON_TOKEN_OPEN_CURLY_BRACE,
  JSON_TOKEN_CLOSE_CURLY_BRACE,
  JSON_TOKEN_OPEN_SQUARE_BRACE,
  JSON_TOKEN_CLOSE_SQUARE_BRACE,
  JSON_TOKEN_COMMA,
  JSON_TOKEN_COLON,
  JSON_TOKEN_STRING,
  JSON_TOKEN_NUMBER,
  JSON_TOKEN_TRUE,
  JSON_TOKEN_FALSE,
  JSON_TOKEN_NULL,

  JSON_TOKEN_COUNT,
} JSON_Token_Type;

typedef struct JSON_Token JSON_Token;
struct JSON_Token
{
  JSON_Token_Type type;
  String          value;

  JSON_Token      *parent;
  JSON_Token      *next_sibling;
  JSON_Token      *first_child;
};

typedef struct JSON_Parser JSON_Parser;
struct JSON_Parser
{
  String source;
  usize  at;
};

u8 *parser_at(JSON_Parser *parser)
{
  return parser->source.data + parser->at;
}

// TODO: Use this to peek so don't have to always advance one at a time
u8 *parser_peek(JSON_Parser *parser, usize advance)
{
  return parser_at(parser) + advance;
}

b8 parser_advance(JSON_Parser *parser, usize advance)
{
  usize new_at = parser->at + advance;
  if (new_at < parser->source.count)
  {
    parser->at = new_at;
    return true;
  }
  else
  {
    return false;
  }
}

b8 parser_incomplete(JSON_Parser *parser)
{
  return parser->at != (parser->source.count - 1);
}

b8 is_numeric(u8 ch)
{
  b8 result = false;
  switch (ch)
  {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
    case '-':
    {
      result = true;
    }
    break;
    // default:
    // printf("%c\n", ch);
    // break;
  }


  return result;
}

JSON_Token get_token(JSON_Parser *parser)
{
  JSON_Token token = {0};

  // Eat white spaces
  while (*parser_at(parser) == ' ' ||
         *parser_at(parser) == '\n')
  {
    // TODO: Probably just count all white space and then advance once for all at the end
    parser_advance(parser, 1);
  }

  token.value.data = parser_at(parser);

  switch (*parser_at(parser))
  {
    case '{':
    {
      token.type = JSON_TOKEN_OPEN_CURLY_BRACE;
      token.value.count = 1;
      parser_advance(parser, 1);
    }
    break;
    case '}':
    {
      token.type = JSON_TOKEN_CLOSE_CURLY_BRACE;
      token.value.count = 1;
      parser_advance(parser, 1);
    }
    break;
    case '[':
    {
      token.type = JSON_TOKEN_OPEN_SQUARE_BRACE;
      token.value.count = 1;
      parser_advance(parser, 1);
    }
    break;
    case ']':
    {
      token.type = JSON_TOKEN_CLOSE_SQUARE_BRACE;
      token.value.count = 1;
      parser_advance(parser, 1);
    }
    break;
    case ',':
    {
      token.type = JSON_TOKEN_COMMA;
      token.value.count = 1;
      parser_advance(parser, 1);
    }
    break;
    case ':':
    {
      token.type = JSON_TOKEN_COLON;
      token.value.count = 1;
      parser_advance(parser, 1);
    }
    break;
    case '"':
    {
      token.type = JSON_TOKEN_STRING;

      parser_advance(parser, 1); // For the quotation mark

      token.value.data = parser_at(parser); // Special case, we want the start to ignore the "

      usize string_count = 0;
      while (*parser_at(parser) != '"')
      {
        string_count += 1;
        parser_advance(parser, 1);
      }
      token.value.count = string_count;

      parser_advance(parser, 1); // For the other quotation mark
    }
    break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
    case '-':
    {
      token.type  = JSON_TOKEN_NUMBER;

      usize digit_count = 0;
      while (is_numeric(*parser_at(parser)))
      {
        digit_count += 1;
        parser_advance(parser, 1);
      }
      token.value.count = digit_count;
    }
    break;
    case 't':
    {
      String true_string = String("true");
      if (memcmp(parser_at(parser), true_string.data, true_string.count))
      {
        // No 'value' for this
        token.type  = JSON_TOKEN_TRUE;
        parser_advance(parser, true_string.count);
      }
    }
    break;
    case 'f':
    {
      String false_string = String("false");
      if (memcmp(parser_at(parser), false_string.data, false_string.count))
      {
        // No 'value' for this
        token.type  = JSON_TOKEN_FALSE;
        parser_advance(parser, false_string.count);
      }
    }
    break;
  }

  return token;
}

// Returns the very first token
JSON_Token *parse_json(u8 *buffer, usize buffer_count, const char *file_name)
{
  // TODO: redo read_file_to_memory, probaly should just return a bool on whether it failed or not
  usize bytes_read = read_file_to_memory(file_name, buffer, buffer_count);

  String source =
  {
    .data  = buffer,
    .count = bytes_read,
  };

  JSON_Parser parser = {
    .source = source,
    .at     = 0,
  };

  while (parser_incomplete(&parser))
  {
    JSON_Token token = get_token(&parser);
    printf("Token: %.*s\n", (int)token.value.count, token.value.data);
    printf("%lu, %lu\n", parser.at, parser.source.count);
  }

  return NULL;
}
