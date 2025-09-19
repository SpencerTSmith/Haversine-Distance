#include "common.h"

enum JSON_Token_Type
{
  JSON_TOKEN_EOF,

  JSON_TOKEN_OPEN_CURLY_BRACE,
  JSON_TOKEN_CLOSE_CURLY_BRACE,
  JSON_TOKEN_OPEN_SQUARE_BRACE,
  JSON_TOKEN_CLOSE_SQUARE_BRACE,
  JSON_TOKEN_COMMA,
  JSON_TOKEN_STRING,
  JSON_TOKEN_COLON,
  JSON_TOKEN_NUMBER,
  JSON_TOKEN_TRUE,
  JSON_TOKEN_FALSE,
  JSON_TOKEN_NULL,

  JSON_TOKEN_COUNT,
};
typedef enum JSON_Token_Type JSON_Token_Type;

typedef struct JSON_Token JSON_Token;
struct JSON_Token
{
  JSON_Token_Type type;
  String          value;
};

typedef struct JSON_Parser JSON_Parser;
struct JSON_Parser
{
  String source;
  u64    at;
};
