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
"int"                               {yyval.type = INT; return TYPE;}
"bool"                              {yyval.type = BOOLEAN; return TYPE;}
"char"                              {yyval.type = CHAR; return TYPE;}
"float"                             {yyval.type = FLOAT; return TYPE;}
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
"#"                                 {yylval.attr = 0; return OP_UNARY;}
"?"																	{yylval.attr = 1; return OP_UNARY;}
"--"                                {yylval.attr = 0; return OP_BINARY_LIST;}
"**"                                {yylval.attr = 1; return OP_BINARY_LIST;}
"++"                                return OP_TERNARY_1;
"!"                                 {yylval.attr = 2; return OP_UNARY;}
"$"                                 return OP_DOLLAR;
">>"                                {yylval.attr = 0; return OP_LIST;}
"<<"                                {yylval.attr = 1; return OP_LIST;}
"%"                                 {yylval.attr = 0; return OP_BINARY_MUL;}
"*"                                 {yylval.attr = 1; return OP_BINARY_MUL;}
"/"                                 {yylval.attr = 2; return OP_BINARY_MUL;}
"+"                                 {yylval.attr = 0; return PLUS_MINUS;}
"-"                                 {yylval.attr = 1; return PLUS_MINUS;}
"<"                                 {yylval.attr = 0; return OP_BINARY_REL;}
">"                                 {yylval.attr = 1; return OP_BINARY_REL;}
"<="                                {yylval.attr = 2; return OP_BINARY_REL;}
">="                                {yylval.attr = 3; return OP_BINARY_REL;}
"=="                                {yylval.attr = 0; return OP_BINARY_EQ;}
"!="                                {yylval.attr = 1; return OP_BINARY_EQ;}
"&&"                                return OP_BINARY_AND;
"||"                                return OP_BINARY_OR;
"@"                                 return OP_TERNARY_2;
[0-9]+                              {yylval.name = strdup(yytext); yylval.attr = 0; return CONST_INT;}
\+[0-9]+                            {yylval.name = strdup(yytext); yylval.attr = 1; return CONST_INT;}
\-[0-9]+                            {yylval.name = strdup(yytext); yylval.attr = 2; return CONST_INT;}
{float}                             {yylval.name = strdup(yytext); yylval.attr = 3; return CONST_FLOAT;}
\+{float}                           {yylval.name = strdup(yytext); yylval.attr = 4; return CONST_FLOAT;}
\-{float}                           {yylval.name = strdup(yytext); yylval.attr = 5; return CONST_FLOAT;}
"true"                              {yylval.name = strdup(yytext); yylval.attr = 0; return CONST_BOOL;}
"false"                             {yylval.name = strdup(yytext); yylval.attr = 1; return CONST_BOOL;}
\'[^\']\'                           {yylval.name = strdup(yytext); yylval.attr = 6; return CONST_CHAR;}
\"[^\"]*\"                          {yylval.name = strdup(yytext); yylval.attr = 7; return STRING;}
{identificador}                     {yylval.lex = strdup(yytext);return IDENTIFIER;} 
[\n]                                {;}
[ \t]+                              {;}
.                                   {printf("\n[LEXICAL ERROR @ line %d] No se reconoce la palabra '%s'\n", yylineno, yytext); }

%%
