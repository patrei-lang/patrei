#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

enum class TokenType {
  KEYWORD,
  IDENTIFIER,
  NUMBER,
  FLOAT,
  STRING,
  BOOLEAN,
  OPERATOR,
  PUNCTUATION,
  ANNOTATION,
  COMMENT,
  EOF_TOKEN
};

struct Token {
  TokenType type;
  std::string value;
  int line;
  int column;

  Token(TokenType t, std::string v, int l, int c)
      : type(t), value(v), line(l), column(c) {}
};

struct Lexer {
private:
  std::string input;
  size_t pos;
  int line;
  int column;

  const std::unordered_map<std::string, TokenType> keywords = {
      {"control", TokenType::KEYWORD},  {"data", TokenType::KEYWORD},
      {"logic", TokenType::KEYWORD},    {"func", TokenType::KEYWORD},
      {"var", TokenType::KEYWORD},      {"if", TokenType::KEYWORD},
      {"else", TokenType::KEYWORD},     {"for", TokenType::KEYWORD},
      {"return", TokenType::KEYWORD},   {"int", TokenType::KEYWORD},
      {"string", TokenType::KEYWORD},   {"bool", TokenType::KEYWORD},
      {"float", TokenType::KEYWORD},    {"struct", TokenType::KEYWORD},
      {"array", TokenType::KEYWORD},    {"map", TokenType::KEYWORD},
      {"true", TokenType::BOOLEAN},     {"false", TokenType::BOOLEAN},
      {"trigger", TokenType::KEYWORD},  {"policy", TokenType::KEYWORD},
      {"schedule", TokenType::KEYWORD}, {"uuid", TokenType::KEYWORD},
      {"call", TokenType::KEYWORD},     {"read", TokenType::KEYWORD},
      {"write", TokenType::KEYWORD}};

public:
  Lexer(const std::string &source)
      : input(source), pos(0), line(1), column(1) {}

  char peek() const { return pos < input.size() ? input[pos] : '\0'; }
};