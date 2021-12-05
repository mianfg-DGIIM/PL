#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {

	MARK = 0,
	FUNCTION,
	VAR,
	FORM

} tIn;

typedef enum {

	NOT_ASIG = 0,
	ENTERO,
	FLOTANTE,
	CARACTER,
	BOOLEANO,
	STRING,
	LIST_OF,
	NA

} tData;

typedef struct {

	tIn in;
	char *lex;
	tData type;
	int nParam;
	unsigned int nDim;

	// Tamaño de la dimensión 1
	int tDim1;

	// Tamaño de la dimensión 2
	int tDim2;

} inTS;

typedef struct {

	int attr;
	char *lex;
	tData type;
	unsigned int nDim;

	// Tamaño de la dimensión 1
	int tDim1;

	// Tamaño de la dimensión 2
	int tDim2;

} attrs;

#define YYSTYPE attrs
#define MAX_IN 1000

extern long int LIMIT;

extern inTS ts[MAX_IN];

// Línea del fichero que se está analizando
extern int line;

// Se indica si se están utilizando las variables (0) o si se están declarando
// (1), (2) llamada desde expresión
extern int decVar;

// Indica el comienzo de un subprograma o función con 0 si es un bloque y 1 si
// es la cabecera del subprograma
extern int subProg;

// Indica si se están declarando parámetros formales en una función
extern int decParam;

extern int decFunction;

// Variable global que almacena el tipo en las declaraciones
extern tData globalType;

// Cuenta el número de parámetros de una función
extern int nParam;

// Índice de la tabla de símbolos de la función que se está utilizando
extern int currentFunction;
extern int aux;

// Devuelve si el atributo es array o no
int isArray(attrs e);

// Devuelve si los dos posibles arrays que recibe tienen el mismo tamaño
int equalSize(attrs e1, attrs e2);

// Guarda el tipo de la variable
int setType(attrs value);

///////////////////////////////////////////////////////////////////////////////
// Tabla de Símbolos
//

// Inserta una entrada en la tabla de símbolos
int tsAddIn(inTS in);

// Elimina una entrada de la tabla de símbolos
int tsDelIn();

// Elimina las entradas de la tabla de símbolos hasta la marca de tope
void tsCleanIn();

// Busca una entrada según el identificador
int tsSearchId(attrs e);

// Busca una entrada según el nombre
int tsSearchName(attrs e);

// Añade un identificador
void tsAddId(attrs e);

// Añade una marca de tope
void tsAddMark();

// Añade una entrada de subprograma
void tsAddSubprog(attrs e);

// Añade una entrada de parametro formal
void tsAddParam(attrs e);

// Actualiza el número de parámetros de la función
void tsUpdateNparam(attrs e);

//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Analizador Semántico
//

// Devuelve la entrada que sea función más cercana
int tsGetNextFunction();

// Comprueba si el tipo de la expresión coincide con lo que devuelve la función
void tsCheckReturn(attrs expr, attrs* res);

// Devuelve el identificar
void tsGetId(attrs id, attrs* res);

// Realiza la comprobación de la operación !, &, ~
void tsOpUnary(attrs op, attrs o, attrs* res);

// Realiza la comprobación de la operación +, -
void tsOpSign(attrs op, attrs o, attrs* res);

// Realiza la comprobación de la operación +, - binaria
void tsOpSignBin(attrs o1, attrs op, attrs o2, attrs* res);

// Realiza la comprobación de la operación *, /
void tsOpMul(attrs o1, attrs op, attrs o2, attrs* res);

// Realiza la comprobación de la operación &&
void tsOpAnd(attrs o1, attrs op, attrs o2, attrs* res);

// Realiza la comprobación de la operación ||
void tsOpOr(attrs o1, attrs op, attrs o2, attrs* res);

// Realiza la comprobación de la operación ==, !=
void tsOpEqual(attrs o1, attrs op, attrs o2, attrs* res);

// Realiza la comprobación de la operación <, >, <=, >=, <>
void tsOpRel(attrs o1, attrs op, attrs o2, attrs* res);

// Realiza la comprobación de la llamada a una función
void tsFunctionCall(attrs id, attrs* res);

// Realiza la comprobación de cada parámetro de una función
void tsCheckParam(attrs param, int checkParam);

//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Visualización
//

// Muestra una entrada de la tabla de símbolos
void printIn(int row);

// Muestra el tipo de la entrada
void printInType(tIn tipo);

// Muestra el tipo del dato recibido
void printDataType(tData type);

// Muestra la tabla de símbolos
void printTS();

// Muestra un atributo recibido
void printAttr(attrs e, char *t);
