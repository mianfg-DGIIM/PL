%{

// Declaraciones
//#include <y.tab.h>
#define MAXLONBUFFER 200
char buffer[MAXLONBUFFER];

%}

%option noyywrap
identificador      (_|[a-zA-Z])[a-zA-Z0-9_]*
float              [0-9]*\.[0-9]+
%%

\n                                  { linea++; }
[ \t]+                              {}
.                                   {
                                      snprintf(buffer, MAXLONBUFFER, "el(los) caracter(es) '%s' no forma(n) ningun token conocido", yytext);
                                      yyerror(buffer);
                                    }
