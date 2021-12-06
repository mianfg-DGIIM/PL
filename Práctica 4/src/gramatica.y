%{ //CÓDIGO C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gramatica.tab.h"

void yyerror(const char *msg);

#define YYERROR_VERBOSE

%}

/*
Mensaje de error sintáctico con BISON: 
BISON ante un error sintactivo, visualiza mensajes de errores con indicaciones de los tokens
que se esperaban en lugar de los que han producido el error
*/
%error-verbose


/*Declaramos el conjunto de reglas o produciones que definen nuestra gramática*/

%token MAIN
%token BLOCK_START
%token BLOCK_END
%token PARENT_START;
%token PARENT_END;
%token BRACKET_START;
%token BRACKET_END;
%token COLON;
%token COMMA;
%token BEGIN_LOCAL;
%token END_LOCAL;
%token TYPE;
%token LIST_OF;
%token ASSIGN;
%token IF;
%token ELSE;
%token WHILE;
%token FOR;
%token TO;
%token INPUT;
%token OUTPUT;
%token RETURN;
%token CONST_INT;
%token CONST_FLOAT;
%token CONST_BOOL;
%token CONST_CHAR;
%token STRING;
%token IDENTIFIER;
%left OP_BINARY;
%left OP_TERNARY_1;
%left OP_TERNARY_2;
%right OP_LIST OP_DOLLAR;

%left OP_BINARY_OR;
%left OP_BINARY_AND;
%left OP_BINARY_EQ;
%left OP_BINARY_REL;
%left PLUS_MINUS;
%right OP_BINARY_MUL;
%right OP_UNARY;

%%

// REGLAS GRAMATICALES produciones

Programa : MAIN bloque ;
bloque : BLOCK_STAR { TS_AddMark(); }
         bloque_in
         BLOCK_END { TS_ClearBlock(); } ;
bloque_in : Declar_de_variables_locales Declar_de_subprogs
          | Declar_de_variables_locales Declar_de_subprogs Sentencias ;
Declar_de_subprogs : Declar_de_subprogs Declar_subprog
                   | ;
Declar_subprog : Cabecera_subprograma { esFunc = 1; }
                 bloque { esFunc = 0; } ;
tipo : TYPE { $$.type = $1.type; }
     | LIST_OF TYPE { $$.type = getListType($1.type); }
Cabecera_subprograma : tipo IDENTIFIER { setType($1); decParam = 1; TS_AddFunction($2); }
                       PARENT_START
                       lista_de_parametros
                       PARENT_END { decParam = 0; $4.nDim = 0; }
                     | tipo IDENTIFIER { setType($1); decParam = 1; TS_AddFunction($2); }
                       PARENT_START PARENT_END { decParam = 0; $4.nDim = 0; }
                     | error ;
Declar_de_variables_locales : BEGIN_LOCAL { decVar = 1; } Variables_locales END_LOCAL { decVar = 0; }
                            | ;
Variables_locales : Variables_locales Cuerpo_declar_variables 
                  | Cuerpo_declar_variables ;                  
Cuerpo_declar_variables : tipo { setType($1); } lista_variables COLON
                        | error
                        | tipo error ;
lista_variables : lista_variables COMMA IDENTIFIER { VarList_Id($3, &$$); }
                | IDENTIFIER { VarList_Id($1, &$$); }
                | error ;
lista_de_parametros : lista_de_parametros COMMA tipo IDENTIFIER { $4.nDim=0; setType($3); TS_AddParam($4); }
                    | tipo IDENTIFIER { $2.nDim=0; setType($1); TS_AddParam($2);} ;
Sentencias : Sentencias {decVar = 2; } Sentencia
           | { decVar = 2; } Sentencia ;
Sentencia : bloque
          | Sentencia_asignacion
          | Sentencia_if
          | Sentencia_while
          | Sentencia_for
          | Sentencia_entrada
          | Sentencia_salida
          | Sentencia_return
          | Sentencia_lista ;
Sentencia_asignacion : IDENTIFIER ASSIGN expresion COLON {
                         if (TS_GetType($1) != $3.type) {
                           printf("[SEMANTIC ERROR @ line %d] Types are not equal: %s, %s\n", line, $1.type, $3.type);
                         }
                         if (!Check_EqualSize($1, $3)) {
                           printf("[SEMANTIC ERROR @ line %d] Sizes are not equal\n", line); 
                         }
                       } ;
Sentencia_if : IF PARENT_START expresion PARENT_END Sentencia {
                 if ($3.type != BOOLEAN) {
                   printf("[SEMANTIC ERROR @ line %d] Expression is not of type BOOLEAN\n", line);  
                 }
               }
             | IF PARENT_START expresion PARENT_END Sentencia ELSE Sentencia {
                 if($3.type != BOOLEAN) {
                   printf("[SEMANTIC ERROR @ line %d] Expression is not of type BOOLEAN\n", line);    
                 }
               };
Sentencia_while : WHILE PARENT_START expresion PARENT_END Sentencia {
                    if ($3.type != BOOLEAN) {
                      printf("[SEMANTIC ERROR @ line %d] Expression is not of type BOOLEAN\n", line);
                    }
                  };
Sentencia_for : FOR IDENTIFIER ASSIGN expresion TO expresion Sentencia {
                  if ($4.type != INT) {
                    printf("[SEMANTIC ERROR @ line %d] Expression is not of type INT\n", line);
                  }
                  if ($6.type != INT) {
                    printf("[SEMANTIC ERROR @ line %d] Expression is not of type INT\n", line);
                  }
                };
Sentencia_entrada : INPUT lista_variables COLON
                  : INPUT STRING COMMA lista_variables COLON ;
Sentencia_salida : OUTPUT Lista_expresiones_o_cadena COLON ;
Lista_expresiones_o_cadena : Lista_expresiones_o_cadena COMMA expresion { nParams++; TS_CheckParams($1, nParam); }
                           | Lista_expresiones_o_cadena COMMA STRING { nParam++; tsCheckParam($1, nParam); }
                           | expresion { nParam=1; tsCheckParam($1, nParam); }
                           | STRING { nParam=1; tsCheckParam($1, nParam); };
Sentencia_return : RETURN expresion { TS_CheckReturn($2, &$$); } COLON ;
Sentencia_lista : expresion OP_LIST COLON { Check_ListSentence($1); }
                | OP_DOLLAR expresion COLON { Check_ListSentence($2); } ;
expresion : PARENT_START expresion PARENT_END { $$.type = $2.type; $$.nDim = $2.nDim; }
          | OP_UNARY expresion { Check_OpUnary($1, $2, &$$); }
          | expresion OP_BINARY_LIST expresion { Check_OpBinaryList($1, $2, $3, &$$); }
          | expresion OP_BINARY_OR expresion { Check_OpBinaryAndOr($1, $2, $3, &$$); }
          | expresion OP_BINARY_AND expresion { Check_OpBinaryAndOr($1, $2, $3, &$$); }
          | expresion OP_BINARY_EQ expresion { Check_OpBinaryEq($1, $2, $3, &$$); }
          | expresion OP_BINARY_REL expresion  { Check_OpBinaryRel($1, $2, $3, &$$); }
          | expresion OP_BINARY_MUL expresion { Check_OpBinaryMul($1, $2, $3, &$$); }
          | expresion PLUS_MINUS expresion { Check_PlusMinusBinary($1, $2, $3, &$$); }
          | PLUS_MINUS expresion { Check_PlusMinus($1, $2, &$$); } %prec OP_UNARY
          | expresion OP_TERNARY_2 expresion { Check_At($1, $2, &$$); }
          | expresion OP_TERNARY_1 expresion OP_TERNARY_2 expresion { Check_ListTernary($1, $2, $3, $4, $5, &$$); }
          | IDENTIFIER { decVar = 0; }
          | constante { $$.type = $1.type; $$.nDim = $1.nDim; }
          | funcion { $$.type = $1.type; $$.nDim = $1.nDim; currentFunction = -1; }
          | error ;
funcion : IDENTIFIER PARENT_START Lista_expresiones PARENT_END { Check_FunctionCall($1, &$$); }
        | IDENTIFIER PARENT_START PARENT_END { Check_FunctionCall($1, &$$); } ;
Lista_expresiones : Lista_expresiones COMMA expresion { TS_CheckParam($3); }
                  | expresion { /* WIP correct? -> */ checkParams = 0; TS_CheckParam($1); } ;
constante : constante_base
          | constante_lista ;
constante_base : CONST_INT { $$.type = INT }
               | CONST_FLOAT { $$.type = FLOAT }
               | CONST_BOOL { $$.type = BOOLEAN }
               | CONST_CHAR { $$.type = CHAR };
constante_lista : BRACKET_START constante_lista_int BRACKET_END { $$.type = LIST_INT; $$.nDim = $2.nDim; }
                | BRACKET_START constante_lista_float BRACKET_END { $$.type = LIST_FLOAT; $$.nDim = $2.nDim; }
                | BRACKET_START constante_lista_bool BRACKET_END { $$.type = LIST_BOOLEAN; $$.nDim = $2.nDim; }
                | BRACKET_START constante_lista_char BRACKET_END { $$.type = LIST_CHAR; $$.nDim = $2.nDim; } ;
constante_lista_int : constante_lista_int COMMA CONST_INT
                    | CONST_INT ;
constante_lista_float : constante_lista_float COMMA CONST_FLOAT
                      | CONST_FLOAT ;
constante_lista_bool : constante_lista_bool COMMA CONST_BOOL
                     | CONST_BOOL ;
constante_lista_char : constante_lista_char COMMA CONST_CHAR
                     | CONST_CHAR ;

%%

#ifdef DOSWINDOWS /* Variable de entorno que indica la plataforma */
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

void yyerror(const char *msg) {
  fprintf(stderr, "[SYNTACTIC ERROR] Line %d: %s\n", yylineno, msg) ;
}
