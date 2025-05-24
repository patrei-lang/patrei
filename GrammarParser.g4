parser grammar GrammarParser;

options {
	tokenVocab = Tokens;
}

sourceFile: packageClause? importDecl* topLevelDecl* EOF;

packageClause: 'package' IDENTIFIER SEMI;

importDecl: 'import' (importSpec | '(' importSpec* ')') SEMI;

importSpec: STRING_LITERAL;

topLevelDecl: functionDecl | varDecl;

functionDecl:
	FUNC IDENTIFIER LPAREN parameterList? RPAREN (type)? LBRACE statementList RBRACE;

parameterList: parameterDecl (COMMA parameterDecl)*;

parameterDecl: IDENTIFIER type;

type: INT | STRING;

varDecl: VAR IDENTIFIER type (ASSIGN expression)? SEMI;

statementList: statement*;

statement:
	varDecl
	| simpleStmt SEMI
	| returnStmt SEMI
	| ifStmt
	| block;

simpleStmt: assignment | expression;

assignment: IDENTIFIER ASSIGN expression;

returnStmt: RETURN expression?;

ifStmt: IF expression block (ELSE (ifStmt | block))?;

block: LBRACE statementList RBRACE;

expression:
	primaryExpr
	| expression (PLUS | MINUS | MUL | DIV) expression;

primaryExpr:
	IDENTIFIER
	| INT_LITERAL
	| STRING_LITERAL
	| LPAREN expression RPAREN;