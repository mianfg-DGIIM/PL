%{

// Declaraciones
#include <y.tab.h>

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
\"[^\"]*\"                           return STRING;
{identificador}                     return IDENTIFIER;
\n                                  {}
[ \t]+                              {}
.                                   {
                                      printf("\nERROR LÉXICO (línea %d): no se reconoce '%s'", yylineno, yytext);
                                    }

%%

// Programa
int main(int argc, char** argv) {
  
  // Comprobación de argumentos
  if (argc <= 1) {
    printf("\nERROR: el numero de argumentos introducidos es incorrecto\n");
    printf("\nEjecucion correcta: %s nombre_fichero\n", argv[0]);
    
    exit(-1);
  }

    // Abrimos el fichero en modo lectura (r)
    yyin = fopen(argv[1], "r");

    // En caso de no poder abrir el fichero (NULL) mostramos el error 
    if (yyin == NULL) {
        printf ("\nNo se ha podido abrir el fichero %s\n", argv[1]);

        exit (-2);
    }

    // Llamamos a yylex para lanzar el analizador léxico
  int analyzer = yylex();

  // Continuamos lanzando yylex() mientras quede fichero por leer
  while (analyzer != 0) {

    printf("__%d__ : %s\n", analyzer, yytext);
    analyzer = yylex();

  }

  // Finaliza el programa
  exit(1);

}