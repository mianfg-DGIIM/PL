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
%right OP_LISTA;
%left OP_BINARY_OR;
%left OP_BINARY_AND;
%left OP_BINARY_EQ;
%left OP_BINARY_REL;
%left PLUS_MINUS;
%left OP_BINARY_MUL;
%right OP_UNARY;

%%

//REGLAS GRAMATICALES produciones

Programa : MAIN bloque ;
bloque : BLOCK_START
         Declar_de_variables_locales
         Declar_de_subprogs
         Sentencias
         BLOCK_END;
Declar_de_subprogs : Declar_de_subprogs Declar_subprog
                   | ;
Declar_subprog : Cabecera_subprograma bloque ;
Cabecera_subprograma : TYPE IDENTIFIER PARENT_START lista_de_parametros PARENT_END
                     | TYPE IDENTIFIER PARENT_START PARENT_END 
                     | error; 
Declar_de_variables_locales : BEGIN_LOCAL Variables_locales END_LOCAL
                            | ;
Variables_locales : Variables_locales Cuerpo_declar_variables 
                  | Cuerpo_declar_variables ;                  
Cuerpo_declar_variables : TYPE lista_variables COLON
                        | LIST_OF TYPE lista_variables COLON
                        | error
                        | TYPE error
                        | LIST_OF TYPE error;
lista_variables : lista_variables COMMA IDENTIFIER 
                | IDENTIFIER 
                | error;
lista_de_parametros : lista_de_parametros COMMA TYPE IDENTIFIER
                    | lista_de_parametros COMMA LIST_OF TYPE IDENTIFIER
                    | TYPE IDENTIFIER
                    | LIST_OF IDENTIFIER ;
Sentencias : Sentencias Sentencia
           | ;
Sentencia : bloque
          | Sentencia_asignacion
          | Sentencia_if
          | Sentencia_while
          | Sentencia_for
          | Sentencia_entrada
          | Sentencia_salida
          | Sentencia_return
          | Sentencias_lista ;
Sentencia_asignacion : IDENTIFIER ASSIGN expresion COLON ;
Sentencia_if : IF PARENT_START expresion PARENT_END Sentencia 
             | IF PARENT_START expresion PARENT_END Sentencia ELSE Sentencia ;
Sentencia_while : WHILE PARENT_START expresion PARENT_END Sentencia ;
Sentencia_for : FOR IDENTIFIER ASSIGN expresion TO expresion Sentencia ;
Sentencia_entrada : INPUT lista_variables COLON ;
Sentencia_salida : OUTPUT Lista_expresiones_o_cadena COLON ;
Lista_expresiones_o_cadena : Lista_expresiones_o_cadena COMMA expresion
                           | Lista_expresiones_o_cadena COMMA STRING
                           | expresion
                           | STRING ;
Sentencia_return : RETURN expresion COLON ;
Sentencias_lista : OP_UNARY expresion COLON
                 | expresion OP_LISTA COLON ;
expresion : PARENT_START expresion PARENT_END
          | OP_UNARY expresion
          | expresion OP_BINARY expresion
          | expresion OP_BINARY_OR expresion
          | expresion OP_BINARY_AND expresion
          | expresion OP_BINARY_EQ expresion
          | expresion OP_BINARY_REL expresion
          | expresion OP_BINARY_MUL expresion
          | expresion PLUS_MINUS expresion
          | PLUS_MINUS expresion %prec OP_UNARY
          | expresion OP_TERNARY_1 expresion OP_TERNARY_2 expresion
          | expresion OP_TERNARY_2 expresion
          | IDENTIFIER
          | constante
          | funcion
          | error ;
funcion : IDENTIFIER PARENT_START Lista_expresiones PARENT_END
        | IDENTIFIER PARENT_START PARENT_END ;
Lista_expresiones : Lista_expresiones COMMA expresion
                  | expresion ;
constante : constante_base
          | constante_lista ;
constante_base : CONST_INT
               | CONST_FLOAT
               | CONST_BOOL
               | CONST_CHAR ;
constante_lista : BRACKET_START constante_lista_int BRACKET_END
                | BRACKET_START constante_lista_float BRACKET_END
                | BRACKET_START constante_lista_bool BRACKET_END
                | BRACKET_START constante_lista_char BRACKET_END ;
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
	fprintf(stderr, "Linea %d: %s\n", yylineno, msg) ;
}
