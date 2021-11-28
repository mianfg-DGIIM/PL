%option noyywrap
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	//#include "constants.h" PARECE NO USARSE YA, SE DEJAN LOS QUE SACA YACC (creo, aunque he visto gente que lo deja y funciona igual)
	#include "gramatica.tab.h"
	extern FILE *yyin;

	int lineno = 1; // initialize to 1
	void yyerror();
%}


identificador      (_|[a-zA-Z])[a-zA-Z0-9_]*
float              [0-9]*\.[0-9]+

%%

"main"                              return MAIN;
"\{"                                return BLOCK_START;
"\}"                                return BLOCK_END;
"\("                                return PARENT_START;
"\)"                                return PARENT_END;
"\["                                return BRACKET_START;
"\]"                                return BRACKET_END;
";"                                 return COLON;
","                                 return COMMA;
"begin_local"                       return BEGIN_LOCAL;
"end_local"                         return END_LOCAL;
"int"                               return TYPE;
"bool"                              return TYPE;
"char"                              return TYPE;
"float"                             return TYPE;
"list of"                           return LIST_OF;
"="                                 return ASSIGN;
"if"                                return IF;
"else"                              return ELSE;
"while"                             return WHILE;
"for"                               return FOR;
"to"                                return TO;
"input"                             return INPUT;
"output"                            return OUTPUT;
"return"                            return RETURN;
"#"                                 return OP_UNARY;
"?"                                 return OP_UNARY;
"!"                                 return OP_UNARY;
">>"                                return OP_UNARY;
"<<"                                return OP_UNARY;
"$"                                 return OP_UNARY;
"*"                                 return OP_BINARY;
"/"                                 return OP_BINARY;
"<"                                 return OP_BINARY;
">"                                 return OP_BINARY;
"<="                                return OP_BINARY;
">="                                return OP_BINARY;
"=="                                return OP_BINARY;
"!="                                return OP_BINARY;
"&&"                                return OP_BINARY;
"||"                                return OP_BINARY;
"--"                                return OP_BINARY;
"&"                                 return OP_BINARY;
"**"                                return OP_BINARY;
"%"                                 return OP_BINARY;
"++"                                return OP_TERNARY_1;
"@"                                 return OP_TERNARY_2;
"+"                                 return PLUS_MINUS;
"-"                                 return PLUS_MINUS;
[0-9]+                              return CONST_INT;
\+[0-9]+                            return CONST_INT;
\-[0-9]+                            return CONST_INT;
{float}                             return CONST_FLOAT;
\+{float}                           return CONST_FLOAT;
\-{float}                           return CONST_FLOAT;
"true"                              return CONST_BOOL;
"false"                             return CONST_BOOL;
\'[^\']\'                           return CONST_CHAR;
\"[^\"]*\"                          return STRING;
{identificador}                     return IDENTIFIER;
[\n]                                { lineno += 1; }
[ \t]+                              ;
.                                   { yyerror("Unrecognized character"); }

%%