%{

// Declaraciones
#include "constants.h"

%}

%option yylineno
%option noyywrap
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
{float}                             return CONST_FLOAT;
\+{float}                           return CONST_FLOAT;
\-{float}                           return CONST_FLOAT;
"true"                              return CONST_BOOL;
"false"                             return CONST_BOOL;
\'[^\']\'                           return CONST_CHAR;
\"[^\"]\"                           return STRING;
{identificador}                     return IDENTIFIER;
\n                                  {}
[ \t]+                              {}
.                                   {
                                      printf("\nERROR LÉXICO (línea %d): no se reconoce '%s'", yylineno, yytext);
                                    }

%%

// Procedimientos
int main(int argc, char** argv) {
  // Se comprueba que se recibe 1 argumento (nombre del fichero fuente)
  if (argc <= 1) {

        printf("\nError al ejecutar la aplicación...\n");
        printf("Uso: %s nombre_fichero_fuente\n", argv[0]);

    exit(-1);

  }

    // Se abre el fichero recibido por parámetro
    yyin = fopen(argv[1], "r");

    // Si "yyin" es nulo no se ha podido abrir el fichero
    if (yyin == NULL) {

        printf ("\nError al abrir el fichero %s\n", argv[1]);

        exit (-2);

    }

    // Invoca al analizador léxico para comenzar el análisis
  int an = yylex();

    // Hasta que no termine de analizar todo el fichero no finalizará la
    // ejecución
  while (an != 0) {

    printf("__%d__ : %s\n", an, yytext);
    //printf("%s ", yytext());
    an = yylex();

  }

  exit(1);

}