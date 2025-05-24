lexer grammar Lexer;

// Tokens for keywords 
FUNC: 'func';
VAR: 'var';
IF: 'if';
ELSE: 'else';
RETURN: 'return';
INT: 'int';
STRING: 'string';

// Literals
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;
INT_LITERAL: [0-9]+;
STRING_LITERAL: '"' (~["\\] | '\\' .)* '"';

// Operators and punctuation
LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
SEMI: ';';
COLON: ':';
COMMA: ',';
ASSIGN: '=';
PLUS: '+';
MINUS: '-';
MUL: '*';
DIV: '/';

// Whitespace and comments
WS: [ \t\r\n]+ -> skip;
COMMENT: '//' ~[\r\n]* -> skip;
MULTILINE_COMMENT: '/*' .*? '*/' -> skip;