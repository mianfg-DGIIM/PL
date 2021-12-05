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

%left OP_BINARY_OR;
%left OP_BINARY_AND;
%left OP_BINARY_EQ;
%left OP_BINARY_REL;
%left PLUS_MINUS;
%right OP_BINARY_MUL;
%right OP_UNARY;

%%

//REGLAS GRAMATICALES produciones

Programa : MAIN bloque ;
bloque : BLOCK_START
         {tsAddMark()}
         Declar_de_variables_locales
         Declar_de_subprogs
         Sentencias
         BLOCK_END;
         {tsCleanIn()}
Declar_de_subprogs : Declar_de_subprogs Declar_subprog
                   | ;
Declar_subprog : Cabecera_subprograma {subProg=1;} bloque {subProg=0;} ;
Cabecera_subprograma : TYPE IDENTIFIER {decParam=1;} {tsAddSubprog($2);} PARENT_START lista_de_parametros PARENT_END {tsUpdateNparam($4);nParam=0;decParam=0}{$4.nDim=0;}
                     | TYPE IDENTIFIER {decParam=1;} {tsAddSubprog($2);} PARENT_START PARENT_END
                     | error; 
Declar_de_variables_locales : BEGIN_LOCAL {decVar=1;} Variables_locales END_LOCAL {decVar=0;}
                            | ;
Variables_locales : Variables_locales Cuerpo_declar_variables 
                  | Cuerpo_declar_variables ;                  
Cuerpo_declar_variables : TYPE  {setType($1)} lista_variables COLON
                        | LIST_OF TYPE {setType($1)} lista_variables COLON
                        | error
                        | TYPE error
                        | LIST_OF TYPE error;
lista_variables : lista_variables COMMA IDENTIFIER 
                | IDENTIFIER 
                | error;
lista_de_parametros : lista_de_parametros COMMA TYPE IDENTIFIER {$4.nDim=0;nParam++;setType($3);tsAddParam($4);}
                    | lista_de_parametros COMMA LIST_OF TYPE IDENTIFIER {$5.nDim=0;nParam++;setType($3);tsAddParam($5);}
                    | TYPE IDENTIFIER {$2.nDim=0;nParam++;setType($1);tsAddParam($2);}
                    | LIST_OF IDENTIFIER {$2.nDim=0;nParam++;setType($1);tsAddParam($2);} ; 
Sentencias : Sentencias {decVar = 2; } Sentencia
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
Sentencia_asignacion : IDENTIFIER ASSIGN expresion COLON {
        if($1.type!=$3.type){
                printf("Semantic Error(%d): Types are not equal.\n",line, $1.type, $3.type);
        }
        if(!equalSize($1,$3)){
               printf("Semantic Error(%d): Sizes are not equal.\n",line); 
        }


};
Sentencia_if : IF PARENT_START expresion PARENT_END Sentencia {
        if($3.type!=BOOLEANO){
              printf("Semantic Error(%d): Expression are not logic.\n", line);  
        }
}
                | IF PARENT_START expresion PARENT_END Sentencia ELSE Sentencia {
                     if($3.type!=BOOLEANO){
                        printf("Semantic Error(%d): Expression are not logic.\n", line);    
                     }
                };

Sentencia_while : WHILE PARENT_START expresion PARENT_END Sentencia {
        if($3.type != BOOLEANO){
		printf("Semantic Error(%d): Expression are not logic.\n", line);
	}
};
Sentencia_for : FOR IDENTIFIER ASSIGN expresion TO expresion Sentencia {
        if($4.type != ENTERO){
		printf("Semantic Error(%d): Expression are not int.\n", line);
	}
        if($6.type != ENTERO){
		printf("Semantic Error(%d): Expression are not int\n", line);
	}
};
Sentencia_entrada : INPUT lista_variables COLON ;
Sentencia_salida : OUTPUT Lista_expresiones_o_cadena COLON ;
Lista_expresiones_o_cadena : Lista_expresiones_o_cadena COMMA expresion { nParam++; tsCheckParam($1, nParam); }
                           | Lista_expresiones_o_cadena COMMA STRING { nParam++; tsCheckParam($1, nParam); }
                           | expresion { nParam=1; tsCheckParam($1, nParam); }
                           | STRING { nParam=1; tsCheckParam($1, nParam); };
Sentencia_return : RETURN expresion {tsCheckReturn($2,&$$);} COLON ;
Sentencias_lista : OP_UNARY expresion COLON ;
expresion : PARENT_START expresion PARENT_END { $$.type = $2.type; $$.nDim = $2.nDim; $$.tDim1 = $2.tDim1; $$.tDim2 = $2.tDim2; }
          | OP_UNARY expresion {tsOpUnary($1, $2, &$$); }
          | expresion OP_BINARY expresion
          | expresion OP_BINARY_OR expresion {tsOpOr($1, $2, $3, &$$); }
          | expresion OP_BINARY_AND expresion {tsOpAnd($1, $2, $3, &$$); }
          | expresion OP_BINARY_EQ expresion {tsOpEqual($1, $2, $3, &$$); }
          | expresion OP_BINARY_REL expresion  {tsOpRel($1, $2, $3, &$$); }
          | expresion OP_BINARY_MUL expresion {tsOpMul($1, $2, $3, &$$); }
          | expresion PLUS_MINUS expresion {tsOpSignBin($1, $2, $3, &$$); }
          | PLUS_MINUS expresion {tsOpSign($1, $2, &$$); } %prec OP_UNARY
          | expresion OP_TERNARY_1 expresion OP_TERNARY_2 expresion
          | IDENTIFIER  {decVar = 0;}
          | constante  {$$.type = $1.type; $$.nDim = $1.nDim; $$.tDim1 = $1.tDim1; $$.tDim2 = $1.tDim2; }
          | funcion {$$.type = $1.type; $$.nDim = $1.nDim; $$.tDim1 = $1.tDim1; $$.tDim2 = $1.tDim2; currentFunction = -1;}
          | error ;
funcion : IDENTIFIER PARENT_START Lista_expresiones PARENT_END { tsFunctionCall($1, &$$); }
        | IDENTIFIER PARENT_START PARENT_END { tsFunctionCall($1, &$$); } ;
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
