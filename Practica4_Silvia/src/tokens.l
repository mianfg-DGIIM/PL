%{
#include <stdlib.h>
#include <string.h>

int lineno = 1; // initialize to 1
void yyerror();

%}

%option noyywrap
%option yylineno
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
"int"                               {yylval.type = INT; return TYPE;}
"bool"                              {yylval.type = BOOLEAN; return TYPE;}
"char"                              {yylval.type = CHAR; return TYPE;}
"float"                             {yylval.type = FLOAT; return TYPE;}
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
"#"                                 {yylval.lex = strdup(yytext); yylval.attr = 0; return OP_UNARY;}
"?"									{yylval.lex = strdup(yytext); yylval.attr = 1; return OP_UNARY;}
"--"                                {yylval.lex = strdup(yytext); yylval.attr = 0; return OP_BINARY_LIST;}
"**"                                {yylval.lex = strdup(yytext); yylval.attr = 1; return OP_BINARY_LIST;}
"++"                                {yylval.lex = strdup(yytext); return OP_TERNARY_1;}
"!"                                 {yylval.lex = strdup(yytext); yylval.attr = 2; return OP_UNARY;}
"$"                                 {yylval.lex = strdup(yytext); return OP_DOLLAR;}
">>"                                {yylval.lex = strdup(yytext); yylval.attr = 0; return OP_LIST;}
"<<"                                {yylval.lex = strdup(yytext); yylval.attr = 1; return OP_LIST;}
"%"                                 {yylval.lex = strdup(yytext); yylval.attr = 0; return OP_BINARY_MUL;}
"*"                                 {yylval.lex = strdup(yytext); yylval.attr = 1; return OP_BINARY_MUL;}
"/"                                 {yylval.lex = strdup(yytext); yylval.attr = 2; return OP_BINARY_MUL;}
"+"                                 {yylval.lex = strdup(yytext); yylval.attr = 0; return PLUS_MINUS;}
"-"                                 {yylval.lex = strdup(yytext); yylval.attr = 1; return PLUS_MINUS;}
"<"                                 {yylval.lex = strdup(yytext); yylval.attr = 0; return OP_BINARY_REL;}
">"                                 {yylval.lex = strdup(yytext); yylval.attr = 1; return OP_BINARY_REL;}
"<="                                {yylval.lex = strdup(yytext); yylval.attr = 2; return OP_BINARY_REL;}
">="                                {yylval.lex = strdup(yytext); yylval.attr = 3; return OP_BINARY_REL;}
"=="                                {yylval.lex = strdup(yytext); yylval.attr = 0; return OP_BINARY_EQ;}
"!="                                {yylval.lex = strdup(yytext); yylval.attr = 1; return OP_BINARY_EQ;}
"&&"                                {yylval.lex = strdup(yytext); return OP_BINARY_AND;}
"||"                                {yylval.lex = strdup(yytext); return OP_BINARY_OR;}
"@"                                 {yylval.lex = strdup(yytext); return OP_TERNARY_2;}
[0-9]+                              {yylval.lex = strdup(yytext); yylval.attr = 0; return CONST_INT;}
\+[0-9]+                            {yylval.lex = strdup(yytext); yylval.attr = 1; return CONST_INT;}
\-[0-9]+                            {yylval.lex = strdup(yytext); yylval.attr = 2; return CONST_INT;}
{float}                             {yylval.lex = strdup(yytext); yylval.attr = 3; return CONST_FLOAT;}
\+{float}                           {yylval.lex = strdup(yytext); yylval.attr = 4; return CONST_FLOAT;}
\-{float}                           {yylval.lex = strdup(yytext); yylval.attr = 5; return CONST_FLOAT;}
"true"                              {yylval.lex = strdup(yytext); yylval.attr = 0; return CONST_BOOL;}
"false"                             {yylval.lex = strdup(yytext); yylval.attr = 1; return CONST_BOOL;}
\'[^\']\'                           {yylval.lex = strdup(yytext); yylval.attr = 6; return CONST_CHAR;}
\"[^\"]*\"                          {yylval.lex = strdup(yytext); yylval.attr = 7; return STRING;}
{identificador}                     {yylval.lex = strdup(yytext); return IDENTIFIER;} 
[ \t]                               {;}
\n                                  {++line;}
[\n\r]                              {;}
.                                   {printf("\n[LEXICAL ERROR @ line %d] No se reconoce la palabra '%s'\n", yylineno, yytext); }

%%