#include "semantic.h"

inTS ts[MAX_IN];
int line=1;
long int LIMIT=0;
int decVar=0;
int decParam = 0;
int decFunction = 0;
int subProg = 0;
tData globalType = NA;
int nParam = 0;
int currentFunction = -1;
int aux = 0;


//¿LAS NECESITAMOS O NO?
// Devuelve si el atributo es array o no
int isArray(attrs e){

    return (e.nDim!=0);
}

// Devuelve si los dos posibles arrays que recibe tienen el mismo tamaño
int equalSize(attrs e1, attrs e2){

    return (e1.nDim == e2.nDim &&
        e1.tDim1 == e2.tDim1 &&
        e1.tDim2 == e2.tDim2);

}

// Guarda el type de la variable
int setType(attrs value){

    globalType = value.type;

}

///////////////////////////////////////////////////////7777
//CREACION TABLA SIMBOLOS 

// Inserta una in en la tabla de símbolos
int tsAddIn(inTS in){

    // Si se tienen más entradas de las que puede alojar la tabla de símbolos
    // dará un error, si no, se inserta
	if(LIMIT < MAX_IN) {

		ts[LIMIT].in=in.in;
		ts[LIMIT].lex=in.lex;
		ts[LIMIT].type=in.type;
		ts[LIMIT].nParam=in.nParam;
		ts[LIMIT].nDim=in.nDim;
		ts[LIMIT].tDim1=in.tDim1;
		ts[LIMIT].tDim2=in.tDim2;

        // Se aumenta el contador de entradas
		LIMIT++;

        // Se muestra la tabla de símbolos por pantalla
		//printTS();

		return 1;

	} else {

		printf("Semantic Error(%d): Stack overflow", line);

		return 0;

	}

}

// Elimina una in de la tabla de símbolos
int tsDelIn(){

    // Si la tabla de símbolos tiene alguna in puede eliminar la última
    if(LIMIT > 0){

		LIMIT--;
		return 1;

	}else{

		printf("Semantic Error(%d): Empty table", line);
		return 0;

	}

}

// Elimina las entradas de la tabla de símbolos hasta la mark de tope
void tsCleanIn(){

    while(ts[LIMIT-1].in != MARK && LIMIT > 0){
		LIMIT--;
	}
	if (ts[LIMIT-1].in == MARK) {
		LIMIT--;
	}

    if (ts[LIMIT-1].in == FORM) {
        while(ts[LIMIT-1].in != FUNCTION && LIMIT > 0){
    		LIMIT--;
    	}
        LIMIT--;
	}

}


// Busca una entrada según el id
int tsSearchId(attrs e){

    int i = LIMIT - 1;
	int found = 0;

	while (i > 0 && !found /*&& ts[i].in != MARK*/) {
		if (ts[i].in == VAR && strcmp(e.lex, ts[i].lex) == 0) {
			found = 1;
		} else{
			i--;
		}
	}

	if(!found) {
		//printf("Semantic Error(%d): Ident not declared: %s\n", line, e.lex);
		return -1;
	} else {
		return i;
	}

}

// Busca una in según el nombre
int tsSearchName(attrs e){

    int i = LIMIT - 1;
	int found = 0;


	while (i > 0 && !found /*&& ts[i].in != MARK*/) {
		if (ts[i].in == FUNCTION && strcmp(e.lex, ts[i].lex) == 0) {
			found = 1;
		} else{
			i--;
		}
	}

	if(!found) {
		//printf("Semantic Error(%d): Ident not declared: %s\n", line, e.lex);
		return -1;
	} else {
		return i;
	}

}

// Añade un id
void tsAddId(attrs e){

    // Para añadir un id a la pila no se puede haber llegado al tope,
    // el id no puede existir y se deben estar declarando variables
	int j = LIMIT-1;
	int found = 0;

	if(j >= 0 && decVar == 1){
		// Se obtiene la posición de la mark del bloque
		while((ts[j].in != MARK) && (j >= 0) && !found){

			if(strcmp(ts[j].lex, e.lex) != 0){

				j--;

			} else{

				found = 1;
				printf("Semantic Error(%d): Exist ident: %s\n", line, e.lex);

	 		}

		}

		// Si no se ha encontrado significa que no existe, por lo que se añade
        // a la pila
		if(!found) {
			inTS newIn;
			newIn.in = VAR;
			newIn.lex = e.lex;
			newIn.type = globalType;
			newIn.nParam = 0;
			newIn.nDim=e.nDim;
			newIn.tDim1=e.tDim1;
			newIn.tDim2=e.tDim2;
			tsAddIn(newIn);

		}

	}
}

// Añade una mark de tope
void tsAddMark(){

    inTS inInitScope;

	inInitScope.in = MARK;
	inInitScope.lex = "{";
	inInitScope.type = NA;
	inInitScope.nParam = 0;
	inInitScope.nDim = 0;
	inInitScope.tDim1 = 0;
	inInitScope.tDim2 = 0;

	tsAddIn(inInitScope);

    // Se añaden a la tabla de símbolos los parámetros de la función como las
    // variables locales de ese bloque
	if(subProg == 1){

		int j = LIMIT - 2, mark = 0, funct = 0;

		while(j > 0 && ts[j].in == FORM){

			/*printf("\n\n");
			printIn(j);
			printf("\n\n");*/

			if(ts[j].in == FORM) {

				inTS newIn;
				newIn.in = VAR;
				newIn.lex = ts[j].lex;
				newIn.type = ts[j].type;
				newIn.nParam = ts[j].nParam;
				newIn.nDim = ts[j].nDim;
				newIn.tDim1 = ts[j].tDim1;
				newIn.tDim2 = ts[j].tDim2;
				tsAddIn(newIn);

			}

			j--;

		}

	}

}

// Añade una in de subprograma
void tsAddSubprog(attrs e){

  inTS inSubProg;
	inSubProg.in = FUNCTION;
	inSubProg.lex = e.lex;
	inSubProg.nParam = 0;
	inSubProg.nDim = 0;
	inSubProg.tDim1 = 0;
	inSubProg.tDim2 = 0;
	inSubProg.type = e.type;

	currentFunction = LIMIT;
	tsAddIn(inSubProg);

}

// Añade una in de param formal
void tsAddParam(attrs e){

    int j = LIMIT - 1, found = 0;

	while((j != currentFunction)  && (!found) ){

		if(strcmp(ts[j].lex, e.lex) != 0) {

			j--;

		} else{

			found = 1;
			printf("Semantic Error(%d): Exist param: %s\n", line, e.lex);

        }

	}

	if(!found) {

		inTS newIn;
		newIn.in = FORM;
		newIn.lex = e.lex;
		newIn.type = globalType;
		newIn.nParam = 0;
		newIn.nDim = e.nDim;
		newIn.tDim1 = e.tDim1;
		newIn.tDim2 = e.tDim2;
		tsAddIn(newIn);

	}

}

// Actualiza el número de parámetros de la función
void tsUpdateNparam(attrs e){

    ts[currentFunction].nParam = nParam;
	ts[currentFunction].nDim=e.nDim;
	ts[currentFunction].tDim1=e.tDim1;
	ts[currentFunction].tDim2=e.tDim2;

}


//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Analizador Semántico
//

// Devuelve la in que sea función más cercana
int tsGetNextFunction(){

    int i = LIMIT - 1;
	int found = 0;

	while (i > 0 && !found) {

		if (ts[i].in == FUNCTION) {
			found = 1;
		} else {
			i--;
		}

	}

	if(!found) {
		return -1;
	} else {
		return i;
	}

}

// Comprueba si el type de la expresión coincide con lo que devuelve la función
void tsCheckReturn(attrs expr, attrs* res){

    int index = tsGetNextFunction();


	if (index > -1) {

		if (expr.type != ts[index].type) {
			printf("Semantic Error(%d): Return not equal to return function.\n", line);
			return;
		}

		attrs tmp;
		tmp.nDim = ts[index].nDim;
		tmp.tDim1 = ts[index].tDim1;
		tmp.tDim2 = ts[index].tDim2;

		if (!equalSize(expr,tmp)) {
			printf("Semantic Error(%d): Return expresion not same size than return function.\n", line);
			return;
		}

		res->type = expr.type;
		res->nDim = expr.nDim;
		res->tDim1 = expr.tDim1;
		res->tDim2 = expr.tDim2;

	} else {

		printf("Semantic Error(%d): res not declared into function.\n", line);
		return;

	}

}

// Devuelve el identificar
void tsGetId(attrs id, attrs* res){

    int index = tsSearchId(id);

	if(index==-1) {
        if(ts[index].in != FUNCTION)
		      printf("\nSemantic Error(%d): Id not found %s.\n", line, id.lex);
	} else {

		res->lex = strdup(ts[index].lex);
		res->type = ts[index].type;
		res->nDim = ts[index].nDim;
		res->tDim1 = ts[index].tDim1;
		res->tDim2 = ts[index].tDim2;

	}

}

// Realiza la comprobación de la operación !, &, ~
void tsOpUnary(attrs op, attrs o, attrs* res){

    if (o.type != BOOLEANO || isArray(o)) {
		printf("Semantic Error(%d): Not operator expects logic expression.", line);
	}

	res->type = BOOLEANO;
	res->nDim = 0;
	res->tDim1 = 0;
	res->tDim2 = 0;

}

// Realiza la comprobación de la operación +, -
void tsOpSign(attrs op, attrs o, attrs* res){

    if ((o.type != FLOTANTE && o.type != ENTERO) || isArray(o)) {
		printf("Semantic Error(%d): Operator expects integer or real expression.", line);
	}

	res->type = o.type;
	res->nDim = 0;
	res->tDim1 = 0;
	res->tDim2 = 0;

}

// Realiza la comprobación de la operación +, - binaria
void tsOpSignBin(attrs o1, attrs op, attrs o2, attrs* res){

    if (o1.type != o2.type) {
	    printf("Semantic Error(%d): Expressions must be equals types.", line);
  		return;
  	}

	if (o1.type != ENTERO && o1.type != FLOTANTE) {
		printf("Semantic Error%d): Invalid type in op. Both must be equals.", line);
		return;
	}

	if (isArray(o1) && isArray(o2)){

		if(equalSize(o1,o2)){

			res->type = o1.type;
			res->nDim = o1.nDim;
			res->tDim1 = o1.tDim1;
			res->tDim2 = o1.tDim2;

		} else {

            printf("Semantic Error(%d): Size arrays must be same", line);
			return;

		}

	} else {

		if (isArray(o1) && !isArray(o2)) {

			res->type = o1.type;
			res->nDim = o1.nDim;
			res->tDim1 = o1.tDim1;
			res->tDim2 = o1.tDim2;

		}

		if (!isArray(o1) && isArray(o2)){

			if (strcmp(op.lex,"-")==0){

				printf("Semantic Error(%d): Operation not allowed.", line);
				return;

			} else {

				res->type = o2.type;
				res->nDim = o2.nDim;
				res->tDim1 = o2.tDim1;
				res->tDim2 = o2.tDim2;

			}

		}

	}

}

// Realiza la comprobación de la operación *, /
void tsOpMul(attrs o1, attrs op, attrs o2, attrs* res){

    if (o1.type != o2.type) {
		printf("Semantic Error(%d): Expressions must be same types.", line);
		return;
	}

	if (o1.type != ENTERO && o1.type != FLOTANTE) {
		printf("Semantic Error%d): Invalid type in op. Both must be same.", line);
		return;
	}

	if (isArray(o1) && isArray(o2)){

		if(equalSize(o1,o2)){

			res->type = o1.type;
			res->nDim = o1.nDim;
			res->tDim1 = o1.tDim1;
			res->tDim2 = o1.tDim2;

		} else {

            printf("Semantic Error(%d): Size arrays must be same", line);
			return;

		}

	} else {

		if (isArray(o1) && !isArray(o2)) {

			res->type = o1.type;
			res->nDim = o1.nDim;
			res->tDim1 = o1.tDim1;
			res->tDim2 = o1.tDim2;

		}

		if (!isArray(o1) && isArray(o2)){

			if (strcmp(op.lex,"-")==0){

				printf("Semantic Error(%d): Operation not allowed.", line);
				return;

			} else {

				res->type = o2.type;
				res->nDim = o2.nDim;
				res->tDim1 = o2.tDim1;
				res->tDim2 = o2.tDim2;

			}

		}

	}

}

// Realiza la comprobación de la operación &&
void tsOpAnd(attrs o1, attrs op, attrs o2, attrs* res){

    if (o1.type != o2.type) {
		printf("Semantic Error (%d): Expressions must be same types.", line);
		return;
	}
	if (o1.type != BOOLEANO || isArray(o1) || isArray(o2)) {
		printf("Semantic Error(%d):Invalid type in op. Both must be same. Expects BOOLEANO", line);
		return;
	}

	res->type = BOOLEANO;
	res->nDim = 0;
	res->tDim1 = 0;
	res->tDim2 = 0;

}

// Realiza la comprobación de la operación ||
void tsOpOr(attrs o1, attrs op, attrs o2, attrs* res){

    if (o1.type != o2.type) {
		printf("Semantic Error (%d): Expressions must be same types.", line);
		return;
	}
	if (o1.type != BOOLEANO || isArray(o1) || isArray(o2)) {
		printf("Semantic Error(%d):Invalid type in op. Both must be same. Expects BOOLEANO", line);
		return;
	}

	res->type = BOOLEANO;
	res->nDim = 0;
	res->tDim1 = 0;
	res->tDim2 = 0;

}

// Realiza la comprobación de la operación ==, !=
void tsOpEqual(attrs o1, attrs op, attrs o2, attrs* res){

    if (o1.type != o2.type) {
		printf("Semantic Error (%d): Expressions must be same types.", line);
		return;
	}
	if (isArray(o1) || isArray(o2)) {
		printf("Semantic Error(%d):Invalid type in op. Both must be same. Expects ENTERO or REAL.", line);
		return;
	}

	res->type = BOOLEANO;
	res->nDim = 0;
	res->tDim1 = 0;
	res->tDim2 = 0;

}

// Realiza la comprobación de la operación <, >, <=, >=, <>
void tsOpRel(attrs o1, attrs op, attrs o2, attrs* res){

    if (o1.type != o2.type) {

		printf("Semantic Error (%d): Expressions must be same types.", line);
		return;
	}
	if ((o1.type != ENTERO && o1.type != FLOTANTE) || isArray(o1) || isArray(o2)) {
		printf("Semantic Error(%d):Invalid type in op. Both must be same. Expects ENTERO or REAL.", line);
		return;
	}

	res->type = BOOLEANO;
	res->nDim = 0;
	res->tDim1 = 0;
	res->tDim2 = 0;

}






// Realiza la comprobación de la llamada a una función
void tsFunctionCall(attrs id, attrs* res){

    int index = tsSearchName(id);

	if(index==-1) {

		currentFunction = -1;

		printf("\nSemantic Error(%d)): Function: Id not found %s.\n", line, id.lex);

    } else {

		if (nParam != ts[index].nParam) {
			printf("Semantic Error(%d): Number of param not valid.\n", line);
		} else {

			currentFunction = index;
			res->lex = strdup(ts[index].lex);
			res->type = ts[index].type;
			res->nDim = ts[index].nDim;
			res->tDim1 = ts[index].tDim1;
			res->tDim2 = ts[index].tDim2;

		}

	}

}

// Realiza la comprobación de cada parámetro de una función
void tsCheckParam(attrs param, int checkParam){

    int posParam = (currentFunction + ts[currentFunction].nParam) - (checkParam - 1);

	int error = ts[currentFunction].nParam - checkParam + 1;

	if (param.type != ts[posParam].type) {
		printf("Semantic Error(%d): Param type (%d) not valid.\n", line, error);
		return;
	}

	if (param.nDim != ts[posParam].nDim || param.tDim1 != ts[posParam].tDim1  || param.tDim2 != ts[posParam].tDim2) {
		printf("Semantic Error(%d): Size param (%d) not valid.\n", line, error);
		return;
	}

}

//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Visualización
//

// Muestra una in de la tabla de símbolos
void printIn(int row){

    inTS e = ts[row];
	printf("\n\nTipo Entrada: %d\nLexema: %s\nTipo Dato: %d\nNum Parametros: %d\nDimensiones[i][j]: %d[%d][%d]\n",
		e.in, e.lex, e.type, e.nParam, e.nDim, e.tDim1, e.tDim2);

}

// Muestra el type de la in
void printInType(tIn type){



}

// Muestra el type del dato recibido
void printDataType(tData type){



}

// Muestra la tabla de símbolos
void printTS(){

    int j = 0;
	char *t, *e;

	printf("--------------------------------\n");
	while(j <= LIMIT-1) {
		if(ts[j].in == 0) { e = "MARK"; }
		if(ts[j].in == 1) { e = "FUNCTION"; }
		if(ts[j].in == 2) { e = "VAR"; }
		if(ts[j].in == 3) { e = "FORM"; }

		if(ts[j].type == 0) { t = "NO_ASIG"; }
		if(ts[j].type == 1) { t = "ENTERO"; }
		if(ts[j].type == 2) { t = "FLOTANTE"; }
		if(ts[j].type == 3) { t = "CARACTER"; }
		if(ts[j].type == 4) { t = "BOOLEANO"; }
		if(ts[j].type == 5) { t = "STRING"; }
		if(ts[j].type == 6) { t = "MATRIZ"; }
		if(ts[j].type == 7) { t = "NA"; }
		printf("----ELEMENTO %d-----------------\n", j);
		printf("-Entrada: %-12s", e);
		printf("-Lexema: %-12s", ts[j].lex);
		printf("-type: %-10s", t);
		printf("-nParam: %-4d", ts[j].nParam);
		printf("-nDim: %-4d", ts[j].nDim);
		printf("-tDim1: %-4d", ts[j].tDim1);
		printf("-tDim2: %-4d\n", ts[j].tDim2);
		j++;
	}
	printf("--------------------------------\n");

}

// Muestra un atributo recibido
void printAttr(attrs e, char *msg){

  char *t;

	if(e.type == 0) { t = "NO_ASIG"; }
	if(e.type == 1) { t = "ENTERO"; }
	if(e.type == 2) { t = "FLOTANTE"; }
	if(e.type == 3) { t = "CARACTER"; }
	if(e.type == 4) { t = "BOOLEANO"; }
	if(e.type == 5) { t = "STRING"; }
	if(e.type == 6) { t = "MATRIZ"; }
	if(e.type == 7) { t = "NA"; }
	printf("------%s-------------------------\n", msg);
	printf("-Atributos: %-4d", e.attr);
	printf("-Lexema: %-12s", e.lex);
	printf("-type: %-10s", t);
	printf("-nDim: %-4d", e.nDim);
	printf("-tDim1: %-4d", e.tDim1);
	printf("-tDim2: %-4d\n", e.tDim2);
	printf("-------------------------------\n");

}
