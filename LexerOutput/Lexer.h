
// Generated from Lexer.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"

class Lexer : public antlr4::Lexer {
public:
  enum {
    FUNC = 1,
    VAR = 2,
    IF = 3,
    ELSE = 4,
    RETURN = 5,
    INT = 6,
    STRING = 7,
    IDENTIFIER = 8,
    INT_LITERAL = 9,
    STRING_LITERAL = 10,
    LPAREN = 11,
    RPAREN = 12,
    LBRACE = 13,
    RBRACE = 14,
    SEMI = 15,
    COLON = 16,
    COMMA = 17,
    ASSIGN = 18,
    PLUS = 19,
    MINUS = 20,
    MUL = 21,
    DIV = 22,
    WS = 23,
    COMMENT = 24,
    MULTILINE_COMMENT = 25
  };

  explicit Lexer(antlr4::CharStream *input);

  ~Lexer() override;

  std::string getGrammarFileName() const override;

  const std::vector<std::string> &getRuleNames() const override;

  const std::vector<std::string> &getChannelNames() const override;

  const std::vector<std::string> &getModeNames() const override;

  const antlr4::dfa::Vocabulary &getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN &getATN() const override;

  // By default the static state used to implement the lexer is lazily
  // initialized during the first call to the constructor. You can call this
  // function if you wish to initialize the static state ahead of time.
  static void initialize();

private:
  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.
};
