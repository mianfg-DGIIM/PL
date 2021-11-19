%{ //CÓDIGO C

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int yylex();   //Para el reconocimiento previo de los token
void yyerror(const char *msg); //Para imprimir el mensaje de error
int linea = 1;
 
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
%token IDENTIFIER

%right OP_UNARY;   //DUDA:LO VI POR INTERNET,PERO NO ESTOY SEGURA???
                    // PUEDE QUE TENGAMOS QUE PONE "NONASSOC" E INDICAMOS QUE NO ES ASOCIATIVA
%left OP_BINARY;

%left OP_TERNARY_1; //Es el ++ , asociativa derecha o izquierda???
%left OP_TERNARY_2; //Es el @, asociativa derecha o izquierda??

%right PLUS_MINUS;

%%

//REGLAS GRAMATICALES produciones

Programa : Cabecera_programa bloque COLON
Cabecera_programa : MAIN COLON
bloque : BLOCK_START
            Declar_de_variables_locales
            Declar_de_subprogs
            Sentencias
            BLOCK_END COLON
Declar_de_subprogs : Declar_de_subprogs Declar_subprog
                      |COLON
Declar_subprog : Cabecera_subprograma bloque COLON
Cabecera_subprograma : TYPE IDENTIFIER PARENT_START lista_de_parametros PARENT_END
                        |  TYPE IDENTIFIER PARENT_START PARENT_END COLON
Declar_de_variables_locales : BEGIN_LOCAL
                                  Variables_locales
                                  END_LOCAL COLON
Variables_locales : Variables_locales Cuerpo_declar_variables
                     |  Cuerpo_declar_variables COLON
Cuerpo_declar_variables : TYPE lista_variables COLON
                           |  LIST_OF TYPE lista_variables COLON
lista_variables : lista_variables COMMA IDENTIFIER
                   |  IDENTIFIER COLON
lista_de_parametros : lista_de_parametros COMMA TYPE IDENTIFIER
                       |  lista_de_parametros COMMA
                          LIST_OF TYPE IDENTIFIER
                       |  TYPE IDENTIFIER
                       |  LIST_OF IDENTIFIER COLON
Sentencias : Sentencias Sentencia
              |  Sentencia COLON
Sentencia : bloque
             |  Sentencia_asignacion
             |  Sentencia_if
             |  Sentencia_while
             |  Sentencia_for
             |  Sentencia_entrada
             |  Sentencia_salida
             |  Sentencia_return
             |  Sentencias_lista
Sentencia_asignacion : IDENTIFIER ASSIGN expresion COLON
Sentencia_if : IF PARENT_START expresion PARENT_END Sentencia
                |  IF PARENT_START expresion PARENT_END Sentencia ELSE Sentencia COLON
Sentencia_while : WHILE PARENT_START expresion PARENT_END Sentencia COLON
Sentencia_for : FOR IDENTIFIER ASSIGN expresion TO expresion Sentencia COLON
Sentencia_entrada : INPUT lista_variables COLON
Sentencia_salida : OUTPUT Lista_expresiones_o_cadena COLON
Lista_expresiones_o_cadena : Lista_expresiones_o_cadena COMMA expresion
                              |  Lista_expresiones_o_cadena COMMA STRING
                              |  expresion
                              |  STRING COLON
Sentencia_return : RETURN expresion COLON
Sentencias_lista : OP_UNARY expresion COLON
expresion : PARENT_START expresion PARENT_END
             |  OP_UNARY expresion
             |  expresion OP_BINARY expresion
             |  expresion  OP_TERNARY_1 expresion OP_TERNARY_2  expresion
             |  IDENTIFIER
             |  constante
             |  funcion COLON
funcion : IDENTIFIER PARENT_START Lista_expresiones PARENT_END
           |  IDENTIFIER PARENT_START PARENT_END COLON
Lista_expresiones : Lista_expresiones COMMA expresion
                     |  expresion COLON
constante : constante_base
             |  constante_lista COLON
constante_base : CONST_INT
                  |  CONST_FLOAT
                  |  CONST_BOOL
                  |  CONST_CHAR COLON
constante_lista :  BLOCK_START  constante_lista_int BLOCK_END
                   |  BLOCK_START constante_lista_float BLOCK_END
                   |  BLOCK_START constante_lista_bool BLOCK_END
                   |  BLOCK_START constante_lista_char BLOCK_END COLON
constante_lista_int : constante_lista_int COMMA CONST_INT
                       |  CONST_INT COLON
constante_lista_float : constante_lista_float COMMA CONST_FLOAT
                       |  CONST_FLOAT COLON
constante_lista_bool : constante_lista_bool COMMA CONST_BOOL
                       |  CONST_BOOL COLON
constante_lista_char : constante_lista_char COMMA CONST_CHAR
                       |  CONST_CHAR COLON

%%

#include "lex.yy.c"

// Se debe implementar la función yyerror. En este caso simplemente escribimos
// el mensaje de error en pantalla
void yyerror(const char *msg ){
	fprintf(stderr, "Línea %d: %s\n", linea, msg) ;
}
