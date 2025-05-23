grammar Expr;

// Parser rules
expr: expr ('+'|'-') expr   # AddSub
    | INT                  # Int
    ;

INT : [0-9]+ ;              // Lexer rule for integers
WS  : [ \t\r\n]+ -> skip ;  // Skip whitespace
