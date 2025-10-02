#include "common.h"

#define JSON_Token_Type(X)         \
  X(JSON_TOKEN_EOF)                \
  X(JSON_TOKEN_OPEN_CURLY_BRACE)   \
  X(JSON_TOKEN_CLOSE_CURLY_BRACE)  \
  X(JSON_TOKEN_OPEN_SQUARE_BRACE)  \
  X(JSON_TOKEN_CLOSE_SQUARE_BRACE) \
  X(JSON_TOKEN_COMMA)              \
  X(JSON_TOKEN_COLON)              \
  X(JSON_TOKEN_STRING)             \
  X(JSON_TOKEN_NUMBER)             \
  X(JSON_TOKEN_TRUE)               \
  X(JSON_TOKEN_FALSE)              \
  X(JSON_TOKEN_NULL)               \
  X(JSON_TOKEN_COUNT)

ENUM_TABLE(JSON_Token_Type);

typedef struct JSON_Token JSON_Token;
struct JSON_Token
{
  JSON_Token_Type type;
  String          value;
};

typedef struct JSON_Object JSON_Object;
struct JSON_Object
{
  String key;   // Not required for arrays, or the outer most object
  String value;

  JSON_Object *first_child;
  JSON_Object *next_sibling;
};

typedef struct JSON_Parser JSON_Parser;
struct JSON_Parser
{
  String source;
  usize  at;
};

u8 *parser_at(JSON_Parser *parser)
{
  ASSERT(parser->at < parser->source.count, "Attempted to read past parser source");
  return parser->source.data + parser->at;
}

// TODO: Use this to peek so don't have to always advance one at a time
u8 *parser_peek(JSON_Parser *parser, usize advance)
{
  return parser_at(parser) + advance;
}

void parser_advance(JSON_Parser *parser, usize advance)
{
  parser->at += advance;
}

b8 parser_incomplete(JSON_Parser *parser)
{
  return parser->at < parser->source.count;
}

b8 parser_token_is_literal(JSON_Parser *parser, String literal_string)
{

  return memcmp(parser_at(parser), literal_string.data, literal_string.count) == 0;
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

JSON_Token get_json_token(JSON_Parser *parser)
{
  JSON_Token token = {0};

  // Eat white spaces
  while (parser_incomplete(parser)  &&
         (*parser_at(parser) == ' '  ||
          *parser_at(parser) == '\n' ||
          *parser_at(parser) == '\r' ||
          *parser_at(parser) == '\t'))
  {
    // TODO: Probably just count all white space and then advance once for all at the end
    parser_advance(parser, 1);
  }

  if (parser_incomplete(parser)) // If we've not reached the end of file
  {
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

        // TODO: account for escaped quotes
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
        String string = String("true");
        if (parser_token_is_literal(parser, string))
        {
          // No 'value' for this
          token.type  = JSON_TOKEN_TRUE;
          parser_advance(parser, string.count);
        }
        else
        {
          LOG_ERROR("Encountered unrecognized literal at byte %lu", parser->at);
        }
      }
      break;
      case 'f':
      {
        String string = String("false");
        if (parser_token_is_literal(parser, string))
        {
          // No 'value' for this
          token.type  = JSON_TOKEN_FALSE;
          parser_advance(parser, string.count);
        }
        else
        {
          LOG_ERROR("Encountered unrecognized literal at byte %lu", parser->at);
        }
      }
      break;
      case 'n':
      {
        String string = String("null");
        if (parser_token_is_literal(parser, string))
        {
          // No 'value' for this
          token.type  = JSON_TOKEN_NULL;
          parser_advance(parser, string.count);
        }
        else
        {
          LOG_ERROR("Encountered unrecognized literal at byte %lu", parser->at);
        }
      }
      break;
    }
  }
  else
  {
    // EOF
    parser_advance(parser, 1);
  }

  return token;
}

JSON_Object *parse_json_children(Arena *arena, JSON_Parser *parser,
                                 JSON_Token_Type end_token, b32 has_keys);

JSON_Object *parse_json_parent(Arena *arena, JSON_Parser *parser, String key, JSON_Token token)
{

  JSON_Object *first_child = NULL;

  if (token.type == JSON_TOKEN_OPEN_CURLY_BRACE)
  {
    // Normal key : value pairs
    b32 has_keys = true;
    first_child = parse_json_children(arena, parser, JSON_TOKEN_CLOSE_CURLY_BRACE, has_keys);
  }
  else if (token.type == JSON_TOKEN_OPEN_SQUARE_BRACE)
  {
    // Array, no key
    b32 has_keys = false;
    first_child = parse_json_children(arena, parser, JSON_TOKEN_CLOSE_SQUARE_BRACE, has_keys);
  }
  else
  {
    // Do nothing
  }

  JSON_Object *result = arena_new(arena, JSON_Object);
  result->key          = key;
  result->first_child  = first_child;
  result->next_sibling = NULL;
  result->value        = token.value;

  return result;
}

JSON_Object *parse_json_children(Arena *arena, JSON_Parser *parser,
                                 JSON_Token_Type end_token, b32 has_keys)
{

}

// Returns the very first object
JSON_Object *parse_json(Arena *arena, const char *file_name)
{
  String source = read_file_to_arena(arena, file_name);

  JSON_Parser parser =
  {
    .source = source,
    .at     = 0,
  };

  int i = 0;
  while (parser_incomplete(&parser))
  {
    JSON_Token token = get_json_token(&parser);
    printf("Token :: Type = %s, Value = '%.*s', \n", JSON_Token_Type_strings[token.type],
           String_Format(token.value));
  }

  return NULL;
}
