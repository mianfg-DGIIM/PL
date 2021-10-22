%{

// Declaraciones
#include "constants.h"

%}

%option yylineno
%option noyywrap

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
"(_|[a-zA-Z])[a-zA-Z0-9_]*"         return IDENTIFIER;
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
"++"                                return OP_TERNARY_1;
"@"                                 return OP_TERNARY_2;
"+"                                 return PLUS_MINUS;
"-"                                 return PLUS_MINUS;
[0-9]+                              return CONST_INT;
\+[0-9]+                            return CONST_INT;
\-[0-9]+                            return CONST_INT;
[0-9]*.[0-9]+                       return CONST_FLOAT;
\+[0-9]*.[0-9]+                     return CONST_FLOAT;
\-[0-9]*.[0-9]+                     return CONST_FLOAT;
"true"                              return CONST_BOOL;
"false"                             return CONST_BOOL;
\'[^\']\'                           return CONST_CHAR;
\"[^\"]\"                           return STRING;
\n                                  {}
[ \t]+                              {}
.                                   {
                                      printf("\nERROR LÉXICO (línea %d): no se reconoce '%s'", yylineno, yytext);
                                    }

%%

// Procedimientos
int main(int argc, char** argv) {
  if (argc <= 1) {
    printf("\ERROR: debe especificar un nombre de fichero.");
    exit(-2);
  }

  // Invocamos al analizador lexico 
  int analizador = yylex();

  // Analizamos todo el fichero para finalizar la ejecución
  while (analizador != 0){
    printf("__%d__", analizador);
    analizador = yylex();
  }

  exit(1);

}