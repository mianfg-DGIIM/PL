#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Tipo de entrada en la tabla de símbolos
 */
typedef enum {
  MARK = 0,           /** Marca especial para referenciar los inicios de bloque */
  FUNCTION,           /** Es función */
  VAR,                /** Es variable local */
  PARAM               /** Es parámetro formal de una función */
} tIn;

/**
 * Tipo de dato de las entradas función, variable local o parámetro formal
 */
typedef enum {
  NOT_ASSIGNED = 0,   /** Aún no se ha asignado el tipo para la inicialización */
  INT,                /** Entero */
  FLOAT,              /** Flotante */
  CHAR,               /** Caracter */
  BOOLEAN,            /** Booleano */
  LIST_INT,           /** Lista de enteros */
  LIST_FLOAT,         /** Lista de flotantes */
  LIST_CHAR,          /** Lista de caracteres */
  LIST_BOOLEAN,       /** Lista de booleanos */
} tData;


/* ELEMENTOS DE LA TABLA DE SÍMBOLOS */

/**
 * Entrada de la tabla de símbolos
 */
typedef struct {
  tIn entry;          /** Tipo de entrada */
  char *lex;          /** Caracteres que conforman el identificador, no utilizado en una marca de bloque */
  tData type;         /** Tipo de dato para las funciones, variables o parámetros formales */
  int nParams;        /** Indica el número de parámetros formales (en el caso de una función) */
  unsigned int nDim;  /** Dimensión de la lista */
  int ended;          /** Indica si la función ha finalizado */
} inTS;

/**
 * Los atributos usados son el tipo de los elementos y el lexema
 */
typedef struct {
  int attr;           /**< Atributo del símbolo (si tiene) */
  char *lex;          /**< Nombre del lexema */
  tData type;         /**< Tipo del símbolo */
  unsigned int nDim;  /**< Dimensión de la lista */
} attrs;

#define YYSTYPE attrs   /** En adelante, cada símbolo tiene una estructura de tipo atributos */
#define MAX_STACK 1000  /** Tamaño máximo de la tabla de símbolos */

/**
 * Pila de la tabla de símbolos (TS)
 */
extern inTS ts[MAX_STACK];  // Pila de la tabla de símbolos

/**
 * Tope de la pila (Top Of Stack), indica la siguiente posición en la
 * pila TS para insertar una entrada
 */
extern long int TOS;

/**
 * Línea del fichero que se está analizando
 */
extern int line;

/**
 * Indica si:
 *   - decVar=0: las variables se están utilizando
 *   - decVar=1: las variables se están declarando
 *   - decVar=2: las variables se llaman desde una expresión
 */
extern int decVar;

/**
 * Indica:
 *   - decParam=1: inicio de una declaración de parámetros formales
 *   - decParam=0: final de una declaración de parámetros formales
 */
extern int decParam;

/**
 * Indica el comienzo de una función:
 *   - esFunc=1: es cabecera de la función
 *   - esFunc=0: es el bloque de la función
 */
extern int esFunc;

/**
 * Tipo de dato actual para asignarlo a las entradas de la TS.
 * Variable global que almacena el tipo en las declaraciones
 */
extern tData currentType;

/**
 * Cuenta el número de parámetros de una función
 */
extern int nParams;

/**
 * Número de parámetros de la función llamada para comprobarlos
 */
extern int checkParams;

/**
 * Nombre de la función llamada que se quiere comprobar
 */
extern int checkFunction;

/**
 * Indica posición en la TS de la función actual
 */
extern int currentFunction;


/**
 * @brief Devuelve el tipo de variable de la lista
 * Ejemplo: getListType(LIST_INT) = INT
 * @param type: Tipo de variable de tipo lista
 * @return Tipo de variable de la lista
 */
tData getListType(tData type);

/**
 * @brief Guarda el tipo del atributo leído (la variable)
 * @param value: Atributo leído
 */
void setType(attrs value);

/**
 * @brief Determina si es de tipo lista
 * @param e: Atributos de un identificador
 * @return Si es de tipo lista o no
 */
int isList(attrs e);

/**
 * @brief Devuelve la lista del tipo de variable
 * Ejemplo: listToType(INT) = LIST_INT
 * @note Es la operación inversa a getListType()
 * @param listType: Tipo de variable de tipo no lista
 * @return Tipo de variable lista del tipo
 */
tData listToType(tData listType);


/* MODIFICACIÓN DE LA TABLA DE SÍMBOLOS */

/**
 * @brief Inserta una entrada en la TS
 * @return 1 si funciona correctamente, -1 en caso de error
 */
int TS_AddEntry(inTS in);

/**
 * @brief Elimina entrada del tope de la TS
 * @return 1 si funciona correctamente, -1 en caso de error
 */
int TS_DeleteEntry();

/**
 * @brief Elimina todas las entradas de la TS del bloque actual y la cabecera del mismo
 * si el bloque la tiene. Debe ser llamada al final de cada bloque
 * @return 1 si funciona correctamente, -1 en caso de error
 */
int TS_ClearBlock();

/**
 * @brief Actualizar función actual
 * @param lastFunc: WIP completar
 */
void updateCurrentFunction(int lastFunc);

/**
 * @brief Busca una entrada en la TS de una variable por su identificador o nombre
 * @return Índice de la entrada encontrada, -1 en caso de no encontrarla
 */
int TS_FindById(attrs e);

/**
 * @brief Busca una entrada en la TS de una función por su identificador o nombre
 * @return Índice de la entrada encontrada, -1 en caso de no encontrarla
 */
int TS_FindByName(attrs e);

/**
 * @brief Añade una entrada (identificador) en la tabla de símbolos de una variable local
 */
void TS_AddId(attrs e);

/**
 * @brief Inserta una entrada en la tabla de símbolos de una función o un bloque
 */
void TS_AddMark();

/**
 * @brief Inserta una entrada en la tabla de símbolos de una función
 */
void TS_AddFunction(attrs e);

/**
 * @brief Inserta una entrada en la tabla de símbolos de un parámetro formal
 */
void TS_AddParam(attrs e);


/* MÉTODOS DEL ANALIZADOR SINTÁCTICO */

/**
 * @brief Comprueba si el tipo de la expresión coincide con el tipo de retorno de la función
 * @param WIP insertar params
 */
void TS_CheckReturn(attrs expr, attrs *res);

/**
 * @brief Devuelve en res la variable en la tabla de símbolos TS del identificador id si lo encuentra definido
 * @param WIP
 */
void TS_GetById(attrs id, attrs *res);

/**
 * @brief Devuelve en res la variable en la tabla de símbolos TS del identificador id si lo encuentra definido
 * @param WIP
 */
int TS_GetType(attrs id);

/**
 * @brief Realiza la comprobación de la llamada a una función
 * @param WIP
 */
void TS_FunctionCall(attrs *res);

/**
 * @brief Realiza la comprobación de cada parámetro de una función
 */
void TS_CheckParam(attrs param);


/**
 * @brief Imprime las entradas de la tabla de símbolos
 */
void print_TS();

/**
 * @brief Imprime un atributo
 */
void print_Attrs(attrs e, char *msg);


int Check_EqualSize(attrs e1, attrs e2);
void Check_ListSequence(attrs expr);
void Check_OpUnary(attrs op, attrs expr, attrs *res);
void Check_PlusMinus(attrs op, attrs expr, attrs *res);
void Check_PlusMinusBinary(attrs expr1, attrs op, attrs expr2, attrs *res);
void Check_OpBinaryList(attrs expr1, attrs op, attrs expr2, attrs *res);
void Check_OpBinaryAndOr(attrs expr1, attrs op, attrs expr2, attrs *res);
void Check_OpBinaryEq(attrs expr1, attrs op, attrs expr2, attrs *res);
void Check_OpBinaryRel(attrs expr1, attrs op, attrs expr2, attrs *res);
void Check_OpBinaryMul(attrs expr1, attrs op, attrs expr2, attrs *res);
void Check_At(attrs expr1, attrs op, attrs expr2, attrs *res);
void Check_ListTernary(attrs expr1, attrs op1, attrs expr2, attrs op2, attrs expr3, attrs *res);
void Check_FunctionCall(attrs id, attrs *res);

void VarList_Id(attrs id, attrs *res);
