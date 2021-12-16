%{ //CÓDIGO C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "semantic.h"

int yylex();
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

%token MAIN PARENT_END BLOCK_START BLOCK_END BRACKET_START BRACKET_END COLON COMMA ASSIGN IF ELSE WHILE RETURN FOR TO STEP OUTPUT INPUT BEGIN_LOCAL END_LOCAL LIST_OF TYPE STRING
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

Programa : {generarFichero();} MAIN {fputs("int main()", file);} bloque {cerrarFichero();} ;
bloque : BLOCK_START { contBloques++; fputs("{\n", file); TS_AddMark(); }
         bloque_in
         BLOCK_END {
           contBloques--; TS_ClearBlock();
           char* sent = (char*) malloc(200);
           sprintf(sent, "%s}\n", numTabs());
           fputs(sent, file);
           if (contBloquesPrimeraFun == contBloques){
             file = file_std;
             contBloquesPrimeraFun = 0;
           }
         } ;
bloque_in : Declar_de_variables_locales Declar_de_subprogs Sentencias
          | Declar_de_variables_locales Declar_de_subprogs ;
Declar_de_subprogs : Declar_de_subprogs Declar_subprog
                   | ;
Declar_subprog : Cabecera_subprograma { esFunc = 1; }
                 bloque { esFunc = 0; } ;
Declar_de_variables_locales : BEGIN_LOCAL { decVar = 1; } Variables_locales END_LOCAL { decVar = 0; }
                            | ;
Variables_locales : Variables_locales Cuerpo_declar_variables 
                  | Cuerpo_declar_variables ;
Cuerpo_declar_variables : tipo { setType($1); } lista_variables COLON {  char* sent = (char*) malloc(200);
                                      sprintf(sent, "%s%s  %s;\n", numTabs(), tipoDeDato($1.type), $3.lex);
                                      fputs(sent, file);
                                    }
                        | error ;
Cabecera_subprograma : tipo IDENTIFIER { setType($1); decParam = 1; TS_AddFunction($2); }
                       PARENT_START
                       lista_de_parametros
                       PARENT_END { decParam = 0; $5.nDim = 0; /*WIP*/ {
                         if(contBloquesPrimeraFun == 0)
                        contBloquesPrimeraFun = contBloques;
                      char* sent = (char*) malloc(200);
                      sprintf(sent, "%s%s %s(%s)", numTabs(), tipoDeDato($1.type), $2.lex, $5.lex);
                      fputs(sent, file_fun);
                      file = file_fun;
                       } } ;
lista_de_parametros : lista_de_parametros COMMA tipo IDENTIFIER { /* WIP CHECK $4.nDim=0; */ setType($3); TS_AddParam($4); concatenarStrings5($$.lex, $1.lex, $2.lex, tipoDeDato($3.type), " ", $4.lex); }
                    | tipo IDENTIFIER { /* WIP CHECK $2.nDim=0; */ setType($1); TS_AddParam($2); concatenarStrings3($$.lex, tipoDeDato($1.type), " ", $2.lex); }
                    |
                    | error ;
Sentencias : Sentencias {decVar = 2; } Sentencia
           | { decVar = 2; } Sentencia ;
Sentencia : bloque
          | Sentencia_asignacion
          | Sentencia_if
          | Sentencia_while
          | Sentencia_entrada
          | Sentencia_salida
          | Sentencia_return
          | Sentencia_for
          | Sentencia_lista ;
Sentencia_asignacion : IDENTIFIER ASSIGN expresion COLON { Check_Assign($1, $3); insertarAsignacion($1.lex, $3.lex); } ;
aux    : {  etiquetaFlujo *aux = malloc(sizeof(etiquetaFlujo));
      aux->EtiquetaElse = generarEtiqueta();
      aux->EtiquetaSalida = generarEtiqueta();
      insertarFlujo(*aux);
      copiarEF(&($$.ef), aux);
      char* sent = (char*) malloc(200);
      sprintf(sent, "%sif(!%s) goto %s;\n", numTabs(), $-1.lex, aux->EtiquetaElse);
      fputs(sent, file);
    } ;
Sentencia_if : IF PARENT_START expresion PARENT_END aux Sentencia { Check_Boolean($3); {
  char* sent = (char*) malloc(200);
                          sprintf(sent, "%sgoto %s;\n", numTabs(), TF[TOPEFLUJO-1].EtiquetaSalida);
                          fputs(sent, file);
                          sprintf(sent, "%s%s:\n", numTabs(), TF[TOPEFLUJO-1].EtiquetaElse);
                          fputs(sent, file);
                          sprintf(sent, "%s%s:\n;\n", numTabs(), TF[TOPEFLUJO-1].EtiquetaSalida);
                          fputs(sent, file);
                          sacarTF();
} }
              | IF PARENT_START expresion PARENT_END aux Sentencia {
                char* sent = (char*) malloc(200);
                                    sprintf(sent, "%sgoto %s;\n", numTabs(), TF[TOPEFLUJO-1].EtiquetaSalida);
                                    fputs(sent, file);
              } ELSE {
                char* sent = (char*) malloc(200);
                            sprintf(sent, "%s%s:\n;\n", numTabs(), TF[TOPEFLUJO-1].EtiquetaElse);
                            fputs(sent, file);
              } Sentencia { Check_Boolean($3); {
                char* sent = (char*) malloc(200);
                          sprintf(sent, "%s%s:\n;\n", numTabs(), TF[TOPEFLUJO-1].EtiquetaSalida);
                          fputs(sent, file);
                          sacarTF();
              } } ;
Sentencia_while : WHILE PARENT_START {
   etiquetaFlujo *aux = malloc(sizeof(etiquetaFlujo));
                          aux->EtiquetaEntrada = generarEtiqueta();
                          aux->EtiquetaSalida = generarEtiqueta();
                          insertarFlujo(*aux);
                          char* sent = (char*) malloc(200);
                          sprintf(sent, "%s%s:\n;\n", numTabs(), aux->EtiquetaEntrada);
                          fputs(sent, file);
} expresion {
  char* sent = (char*) malloc(200);
                          sprintf(sent, "%sif (!%s) goto %s;\n", numTabs(), $4.lex ,TF[TOPEFLUJO-1].EtiquetaSalida);
                          fputs(sent, file);
} PARENT_END Sentencia { Check_Boolean($4); {
  char* sent = (char*) malloc(200);
                            sprintf(sent, "%sgoto %s;\n", numTabs(), TF[TOPEFLUJO-1].EtiquetaEntrada);
                            fputs(sent, file);
                            sprintf(sent, "%s%s:\n;\n", numTabs(), TF[TOPEFLUJO-1].EtiquetaSalida);
                            fputs(sent, file);
                            sacarTF();
} } ;
Sentencia_entrada : INPUT lista_variables COLON {
                      char* sent = (char*) malloc(200);
                                    sprintf(sent, "\", %s);\n", $2.lex);
                                    fputs(sent, file);
} ;
Sentencia_salida : OUTPUT Lista_expresiones_o_cadena COLON {
  char* sent = (char*) malloc(200);
                                    sprintf(sent, "\", %s);\n", $2.lex);
                                    fputs(sent, file);
} ;
Sentencia_return : RETURN expresion { TS_CheckReturn($2, &$$); char* sent = (char*) malloc(200);
                                sprintf(sent, "%sreturn %s;\n", numTabs(), $2.lex);
                                fputs(sent, file); } COLON ;
Sentencia_for : FOR IDENTIFIER ASSIGN expresion {
  etiquetaFlujo *aux = malloc(sizeof(etiquetaFlujo));
                          aux->EtiquetaEntrada = generarEtiqueta();
                          aux->EtiquetaSalida = generarEtiqueta();
                          insertarFlujo(*aux);
                          char* sent = (char*) malloc(200);
                          /*sprintf(sent, "%sint %s;\n", numTabs(), $2.lex);
                          fputs(sent, file);*/
                          sprintf(sent, "%s%s = %s;\n", numTabs(), $2.lex, $4.lex);
                          fputs(sent, file);
                          sprintf(sent, "%s%s:\n;\n", numTabs(), aux->EtiquetaEntrada);
                          fputs(sent, file);
} TO expresion {
  char* sent = (char*) malloc(200);
                          sprintf(sent, "%s%s = %s<%s;\n", numTabs(), generarTemp(BOOLEAN), $2.lex, $7.lex);
                          fputs(sent, file);
                          sprintf(sent, "%sif (!temp%d) goto %s;\n", numTabs(), temp ,TF[TOPEFLUJO-1].EtiquetaSalida);
                          fputs(sent, file);
} STEP expresion Sentencia { Check_Int($4); Check_Int($6); char* sent = (char*) malloc(200);
                    sprintf(sent, "%s%s = %s+%s;\n", numTabs(), generarTemp(INT), $2.lex, $10.lex);
                    fputs(sent, file);
                    sprintf(sent, "%s%s = temp%d;\n", numTabs(), $2.lex, temp);
                    fputs(sent, file);
                    sprintf(sent, "%sgoto %s;\n", numTabs(), TF[TOPEFLUJO-1].EtiquetaEntrada);
                    fputs(sent, file);
                    sprintf(sent, "%s%s:\n;\n", numTabs(), TF[TOPEFLUJO-1].EtiquetaSalida);
                    fputs(sent, file);
                    sacarTF(); } ;
Sentencia_lista : IDENTIFIER OP_LIST COLON { Check_ListSentence($1); {
  char* sent = (char*) malloc(200);
                    if (strcmp($2.lex, ">>") == 0)
                      sprintf(sent, "%snext(&%s);\n", numTabs(), $1.lex);
                    else
                      sprintf(sent, "%sprevious(&%s);\n", numTabs(), $1.lex);
                    fputs(sent, file);
} }
                | DOLLAR IDENTIFIER COLON { Check_ListSentence($2); {
                  char* sent = (char*) malloc(200);
                    sprintf(sent, "%sbegin(&%s);\n", numTabs(), $2.lex);
                    fputs(sent, file);
                } } ;
expresion : OP_UNARY_NEG expresion { Check_OpUnaryNeg($1, $2, &$$); {	
															char* sent = (char*) malloc(200);
															sprintf(sent, "%s%s = %s%s;\n", numTabs(), generarTemp($$.type), $1.valor, $2.valor);
															fputs(sent, file);
															char* aux = (char*) malloc(20);
															sprintf(aux, "temp%d", temp);
															concatenarStrings1($$.valor, aux);
														}}
          | OP_UNARY_COUNT expresion { Check_OpUnaryCount($1, $2, &$$); {	
															char* sent = (char*) malloc(200);
															sprintf(sent, "%s%s = %s%s;\n", numTabs(), generarTemp($$.type), $1.valor, $2.valor);
															fputs(sent, file);
															char* aux = (char*) malloc(20);
															sprintf(aux, "temp%d", temp);
															concatenarStrings1($$.valor, aux);
														}}
          | OP_UNARY_QUEST expresion { Check_OpUnaryQuest($1, $2, &$$); {	
															char* sent = (char*) malloc(200);
															sprintf(sent, "%s%s = %s%s;\n", numTabs(), generarTemp($$.type), $1.valor, $2.valor);
															fputs(sent, file);
															char* aux = (char*) malloc(20);
															sprintf(aux, "temp%d", temp);
															concatenarStrings1($$.valor, aux);
														}}
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
          | IDENTIFIER { $$.type = TS_GetType($1); $$.nDim = TS_GetNDim($1); decVar = 0; }
          | constante { $$.type = $1.type; $$.nDim = $1.nDim; }
          | funcion { $$.type = $1.type; $$.nDim = $1.nDim; currentFunction = -1; }
          | expresion PLUS_PLUS expresion AT expresion { Check_ListTernary($1, $2, $3, $4, $5, &$$); }
          | PARENT_START expresion PARENT_END { $$.type = $2.type; $$.nDim = $2.nDim; {
            char* aux = (char*) malloc(20);
                                sprintf(aux, "temp%d", temp);
                                concatenarStrings1($$.valor, aux);
          } }
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
lista_variables : lista_variables COMMA IDENTIFIER { VarList_Id($3, &$$); {
  if( $0.type != LIST_INT && $0.type != LIST_FLOAT && $0.type != LIST_CHAR && $0.type != LIST_BOOLEAN)
                            concatenarStrings3($$.lex, $1.lex, $2.lex, $3.lex);
                          else{
                            concatenarStrings5($$.lex, $1.lex, ";\n", numTabs(), tipoDeDato($0.type), " ");
                            concatenarStrings3($$.lex, $$.lex, $3.lex, " = NULL");
                          }
} }
                | IDENTIFIER { VarList_Id($1, &$$); {
                  if( $0.type != LIST_INT && $0.type != LIST_FLOAT && $0.type != LIST_CHAR && $0.type != LIST_BOOLEAN)
                            concatenarStrings1($$.lex, $1.lex);
                          else{
                            concatenarStrings2($$.lex, $1.lex, " = NULL");
                          }
                } }
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