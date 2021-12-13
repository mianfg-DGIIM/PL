%{ //CÓDIGO C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h"

void yyerror(const char *msg);

#define YYERROR_VERBOSE

%}

/*
Mensaje de error sintáctico con BISON: 
BISON ante un error sintactivo, visualiza mensajes de errores con indicaciones de los tokens
que se esperaban en lugar de los que han producido el error
*/
//%error-verbose
%define parse.error verbose

/*Declaramos el conjunto de reglas o produciones que definen nuestra gramática*/

%token MAIN PARENT_END BLOCK_START BLOCK_END BRACKET_START BRACKET_END COLON COMMA ASSIGN IF ELSE WHILE RETURN FOR TO OUTPUT INPUT BEGIN_LOCAL END_LOCAL LIST_OF TYPE STRING
%right AT
%left OP_BINARY_OR
%left OP_BINARY_AND
%left OP_BINARY_EQ
%left OP_BINARY_REL
%left PLUS_MINUS
%left OP_BINARY_MUL
%right OP_UNARY_NEG
%right OP_UNARY_COUNT
%right OP_UNARY_QUEST
%right MINUS_MINUS
%right PLUS_PLUS
%right DOLLAR OP_LIST
%left CONST_INT CONST_FLOAT CONST_BOOL CONST_CHAR IDENTIFIER
%right PARENT_START

%%

// REGLAS GRAMATICALES produciones

Programa :{generateIntermedio();} MAIN bloque {closeIntermedio();};

bloque : BLOCK_START { TS_AddMark(); }
         bloque_in
         BLOCK_END  { fputs("\n}\n",file); } { TS_ClearBlock(); } ;

bloque_in : Declar_de_variables_locales 
              {
                if(varPrinc==1){
                  varPrinc=0;
                  fputs("int main(){\n",file); ????
                }
               
              } 
            Declar_de_subprogs
            Sentencias
          | Declar_de_variables_locales 
              {
                if(varPrinc==1){
                  varPrinc=0;
                  fputs("int main(){\n",file); ????
                }
               
              }
          Declar_de_subprogs ;

Declar_de_subprogs : Declar_de_subprogs Declar_subprog
                   | ;
Declar_subprog : Cabecera_subprograma { esFunc = 1; }
                 bloque { esFunc = 0; } ;
Declar_de_variables_locales : BEGIN_LOCAL { decVar = 1; } Variables_locales END_LOCAL { decVar = 0; }
                            | ;
Variables_locales : Variables_locales Cuerpo_declar_variables 
                  | Cuerpo_declar_variables ;                  
Cuerpo_declar_variables : tipo { setType($1); } lista_variables COLON
                        | error ;
Cabecera_subprograma : tipo IDENTIFIER { setType($1); decParam = 1; TS_AddFunction($2); }
                       PARENT_START
                       lista_de_parametros
                       PARENT_END { fputs(")",file); }  { decParam = 0; $4.nDim = 0; /*WIP*/ } ;
lista_de_parametros : lista_de_parametros COMMA parametro
                    | parametro
                    |
                    | error ;
parametro : tipo IDENTIFIER { /* WIP CHECK $2.nDim=0; */ setType($1); TS_AddParam($2); } ;
Sentencias : Sentencias {decVar = 2; } Sentencia
           | { decVar = 2; } Sentencia ;
Sentencia : {	if(decIF==1){
                {insertCond(1);}
                fputs("{\n",file);
                decIF++;
              }  
				    } bloque
          | Sentencia_asignacion
          | { decIF=1;insertDesc(1);} Sentencia_if {decIF = 0;eliminaDesc();}
          | {	if(decIF==1){
                insertCond(1);
                fputs("{\n",file);
                decIF++;
						  }
              insertDesc(2);
              insertEtiqInput();
              fputs("{\n",file);
					  } Sentencia_while
          | {	if(decIF==1){
                insertCond(1);
                fputs("{\n",file);
                decIF++;
						  }
					} Sentencia_entrada
          | {if(decIF==1){
							insertCond(1);
							fputs("{\n",file);
							decIF++;
						}
					  }Sentencia_salida
          | {if(decIF==1){
							insertCond(1);
							fputs("{\n",file);
							decIF++;
						}
					}Sentencia_return
          | if(decIF==1){
							insertCond(1);
							fputs("{\n",file);
							decIF++;
						}
					}Sentencia_for
          | if(decIF==1){
							insertCond(1);
							fputs("{\n",file);
							decIF++;
						}
					}Sentencia_lista ;
Sentencia_asignacion : IDENTIFIER ASSIGN expresion COLON { 
                  Check_Assign($1, $3); 
                  if(decIF==1){
                    insertCond(1);
                    fputs("{\n",file);
                    decIF++;
                  }
		              generate(4,$1,$2,$3,$4);
                } ;
Sentencia_if : IF PARENT_START expresion PARENT_END Sentencia { 
                Check_Boolean($3);
                
                $$.lex = $3.lex;
                fputs("}\n",file);
                insertEtiqElse();
                fputs("{}\n",file);
					     
              }
              | IF PARENT_START expresion PARENT_END Sentencia ELSE  {
                decElse=1; 
                fputs("}\n",file);
                insertEtiqElse();
                fputs("{\n",file);
                decElse=0;
                }
                Sentencia { Check_Boolean($3);fputs("}\n",file);insertEtiqOutput();fputs("{}\n",file);} ;
Sentencia_while : WHILE PARENT_START expresion PARENT_END {insertCond(2);} Sentencia { 
                    Check_Boolean($3); 

                    $$.lex = $3.lex;
                    fputs("}\n",file);
                    insertGotoInput();
                    insertEtiqOutput();
                    fputs("{}\n",file);
                    
                  } ;
Sentencia_entrada : INPUT STRING COMMA lista_variables COLON {generateEntSal(1,$2);}
                  | INPUT lista_variables COLON {generateEntSal(1,$2);};
Sentencia_salida : OUTPUT Lista_expresiones_o_cadena COLON {generateEntSal(2,$2);};
Sentencia_return : RETURN expresion { TS_CheckReturn($2, &$$); } COLON ;

Sentencia_for : FOR IDENTIFIER ASSIGN expresion TO expresion Sentencia { Check_Int($4); Check_Int($6); } ;

Sentencia_lista : IDENTIFIER OP_LIST COLON { Check_ListSentence($1); }
                | DOLLAR IDENTIFIER COLON { Check_ListSentence($2); } ;
expresion : OP_UNARY_NEG expresion { Check_OpUnaryNeg($1, $2, &$$); }
          | OP_UNARY_COUNT expresion { Check_OpUnaryCount($1, $2, &$$); }
          | OP_UNARY_QUEST expresion { Check_OpUnaryQuest($1, $2, &$$); }
          | PLUS_PLUS expresion { Check_IncrementDecrement($1, $2, &$$); }
          | MINUS_MINUS expresion { Check_IncrementDecrement($1, $2, &$$); }
          | expresion PLUS_MINUS expresion { Check_PlusMinusBinary($1, $2, $3, &$$); }
          | PLUS_MINUS expresion %prec OP_UNARY_NEG { Check_PlusMinus($1, $2, &$$); }
          | expresion OP_BINARY_MUL expresion { Check_OpBinaryMul($1, $2, $3, &$$); }
          | expresion OP_BINARY_AND expresion { Check_OpBinaryAndOr($1, $2, $3, &$$); }
          | expresion OP_BINARY_OR expresion { Check_OpBinaryAndOr($1, $2, $3, &$$); }
          | expresion OP_BINARY_REL expresion  { Check_OpBinaryRel($1, $2, $3, &$$); }
          | expresion OP_BINARY_EQ expresion { Check_OpBinaryEq($1, $2, $3, &$$); }
          | expresion AT expresion { Check_At($1, $2, $3, &$$); }
          | expresion MINUS_MINUS expresion { Check_MinusMinus($1, $2, $3, &$$); }
          | IDENTIFIER { generateDecVar($1); $$.type = TS_GetType($1); $$.nDim = TS_GetNDim($1); decVar = 0; }
          | constante { $$.type = $1.type; $$.nDim = $1.nDim; }
          | funcion { $$.type = $1.type; $$.nDim = $1.nDim; currentFunction = -1; }
          | expresion PLUS_PLUS expresion AT expresion { Check_ListTernary($1, $2, $3, $4, $5, &$$); }
          | PARENT_START expresion PARENT_END { $$.type = $2.type; $$.nDim = $2.nDim; }
          | error ;
funcion : cabecera_funcion argumentos_funcion { $$.attr = $2.attr; $$.type = $2.type, $$.nDim = $2.nDim; } ;
cabecera_funcion : IDENTIFIER PARENT_START { Check_FunctionCall($1); } ;
argumentos_funcion : Lista_expresiones PARENT_END { TS_FunctionCall(&$$); }
                   | PARENT_END { TS_FunctionCall(&$$); } ;
Lista_expresiones_o_cadena : Lista_expresiones_o_cadena COMMA expresion { nParams++; TS_CheckParam($1); }
                           | Lista_expresiones_o_cadena COMMA STRING { nParams++; TS_CheckParam($1); }
                           | expresion { nParams=1; TS_CheckParam($1); }
                           | STRING { nParams=1; TS_CheckParam($1); };
constante : constante_base
          | constante_lista ;
constante_base : CONST_INT { $$.type = INT; }
               | CONST_FLOAT { $$.type = FLOAT; }
               | CONST_BOOL { $$.type = BOOLEAN; }
               | CONST_CHAR { $$.type = CHAR; } ;
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
Lista_expresiones : Lista_expresiones COMMA expresion { TS_CheckParam($3); }
                  | expresion { /* WIP correct? -> */ checkParams = 0; TS_CheckParam($1); } ;
tipo : TYPE { $$.type = $1.type; }
     | LIST_OF TYPE { $$.type = getListType($2.type); } ;
lista_variables : lista_variables COMMA IDENTIFIER { VarList_Id($3, &$$); }
                | IDENTIFIER { VarList_Id($1, &$$); }
                | lista_variables error IDENTIFIER ;

%%

#ifdef DOSWINDOWS /* Variable de entorno que indica la plataforma */
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

void yyerror(const char *msg) {
  fprintf(stderr, "[SYNTACTIC ERROR @ line %d] %s\n", yylineno, msg) ;
}