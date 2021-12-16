#include "semantic.h"
#define DEBUG 0



inTS     ts[MAX_STACK];
long int TOS             = 0;
long int TOPEFLUJO             = 0;   // RENAME TOF
int      line            = 1;
int      decVar          = 0;
int      decParam        = 0;
int      esFunc          = 0;
tData    currentType     = NONE;
int      nParams         = 0;
int      checkParams     = 0;
int      checkFunction   = 0;
int      currentFunction = -1;

unsigned int contBloques = 0;
unsigned int contBloquesPrimeraFun = 0;
unsigned int numLinea = 1;


unsigned int Subprog ;     /*Indicador de comienzo de bloque de un subprog*/
FILE* file;
FILE* file_std;
FILE* file_fun;
char* argumento;
char* tabs = NULL;

tData getListType(tData type) {
  switch (type) {
    case INT:
      return LIST_INT;
    case FLOAT:
      return LIST_FLOAT;
    case CHAR:
      return LIST_CHAR;
    case BOOLEAN:
      return LIST_BOOLEAN;
    default:
      return type;
  }
}

const char* tDataToString(tData type) {
  switch (type) {
    case INT:
      return "INT";
    case FLOAT:
      return "FLOAT";
    case CHAR:
      return "CHAR";
    case BOOLEAN:
      return "BOOLEAN";
    case LIST_INT:
      return "LIST OF INT";
    case LIST_FLOAT:
      return "LIST OF FLOAT";
    case LIST_CHAR:
      return "LIST OF CHAR";
    case LIST_BOOLEAN:
      return "LIST OF BOOLEAN";
    default:
      return "NONE";
  }
}


void setType(attrs value) {
  currentType = value.type;
}

int isList(attrs e) {
  return e.type == LIST_INT || e.type == LIST_FLOAT || e.type == LIST_CHAR || e.type == LIST_BOOLEAN;
}

tData listToType(tData listType) {
  switch (listType) {
    case LIST_INT:
      return INT;
    case LIST_FLOAT:
      return FLOAT;
    case LIST_CHAR:
      return CHAR;
    case LIST_BOOLEAN:
      return BOOLEAN;
    default:
      return NONE;
  }
}


int TS_AddEntry(inTS in) {
  if (TOS < MAX_STACK) {        // Comprobamos si quedan entradas en la tabla de símbolos
    ts[TOS].entry   = in.entry;
    ts[TOS].lex     = in.lex;
    ts[TOS].type    = in.type;
    ts[TOS].nParams = in.nParams;
    ts[TOS].nDim    = in.nDim;
    // WIP -> ts[TOS].ended   = in.ended;

    TOS++;          // Se aumenta el contador de entradas
    //print_TS();    // Se muestra la tabla de símbolos por pantalla

    return 1;
  } else {
    printf("[SEMANTIC ERROR @ line %d] Symbol table overflow", line);
    return -1;
  }
}

int TS_DeleteEntry() {
  if (TOS > 0) {  // Si la tabla de símbolos tiene alguna in puede eliminar la última
    TOS--;
    return 1;
  } else {
    printf("[SEMANTIC ERROR @ line %d] Empty symbol table", line);
    return -1;
  }
}

/*int TS_ClearBlock() {
  while (ts[TOS-1].in != MARK && TOS > 0) {
    TOS--;
  }
  if (ts[TOS-1].in == MARK) {
    TOS--;
  }
  if (ts[TOS-1].in == PARAM) {
    while(ts[TOS-1].in != FUNCTION && TOS > 0){
    TOS--;
  }
    TOS--;
  }
}*/

int TS_ClearBlock() {
  int ret = -1;
  int currentTOS = -1;    // valor del TOS antes de actualizar la función actual

  if (TOS == 0)           // la TS está vacía
    return 1;

  while (TOS > 0) {       // buscamos el inicio del bloque en el que estamos mientras que no
                          // lleguemos a la base de la pila
    TOS--;                // nos desplazamos a las entradas anteriores

    if (ts[TOS].entry == MARK) {   // encuentra una entrada con la marca de inicio de bloque
      ret = 1;
      break;
    }
  }

  if (TOS == 0) {
    printf("[SEMANTIC] Analysis ended\n");
    return ret;
  }

  

  // dejamos TOS donde estaría la marca de bloque para comenzar a insertar ahí,
  // todo lo anterior en la TS se conserva (parámetros formales, funciones...)
  currentTOS = TOS;
  currentTOS--;

  if (ts[currentTOS].entry == PARAM) {      // si el bloque es una función, actualizamos la
                                             // función actual
    while (ts[currentTOS].entry == PARAM) {
      currentTOS--;
    }
  }
  if (ts[currentTOS].entry == FUNCTION) {   // busca en la TS la última función definida no finalizada por declarar para
                                             // convertirla en la actual (es su ámbito ahora)
    ts[currentTOS].ended = 1;                // señalamos que esta función ha finalizado, pues
                                             // hemos eliminado el cuerpo de dicha función
    updateCurrentFunction(currentTOS);
  }

  return ret;
}

void insertarFlujo(etiquetaFlujo s){
    if (TOPEFLUJO == MAX_TF) {
      printf("\nError: tamanio maximo alcanzado\n");
      exit(-1);
    } else {
      TF[TOPEFLUJO].EtiquetaEntrada=s.EtiquetaEntrada;
      TF[TOPEFLUJO].EtiquetaSalida=s.EtiquetaSalida;
      TF[TOPEFLUJO].EtiquetaElse=s.EtiquetaElse;
      TF[TOPEFLUJO].NombreVarControl=s.NombreVarControl;
      ++TOPEFLUJO;
    }
  }

void updateCurrentFunction(int lastFunc) {
  lastFunc--;
  while (ts[lastFunc].entry != FUNCTION && lastFunc > 0){
    lastFunc--;
  }
  if (lastFunc == 0) {
    currentFunction = -1;
  } else {
    if (ts[lastFunc].ended == 0)    // si la función encontrada todavía no ha terminado de definirse
      currentFunction = lastFunc;
    else
      updateCurrentFunction(lastFunc);
  }
}

int TS_FindById(attrs e) {
  int i = TOS - 1;    

  if (TOS == 0)
    return -1;
  
  //print_TS();
  
  while (i > 0 /* && ts[i].entry != MARK */) {
    if (ts[i].entry == VAR && strcmp(e.lex, ts[i].lex) == 0) {
      //printf("ATRIBUTO FINDBYID. lex=%s, type=%d, entry=%d\n", ts[i].lex, ts[i].type, ts[i].entry);
      return i;
    }
    i--;
  }

  //printf("[SEMANTIC ERROR @ line %d] Identifier not declared: %s\n", line, e.lex);
  return -1;
}

int TS_FindByName(attrs e) {
  int i = TOS - 1;    

  if (TOS == 0)
    return -1;
  
  while (i > 0) {
    if (ts[i].entry == FUNCTION && strcmp(e.lex, ts[i].lex) == 0)
      return i;
    i--;
  }

  //printf("[SEMANTIC ERROR @ line %d] Identifier not declared: %s\n", line, e.lex);
  return -1;
}

int TS_FindByNameChar(char* name) {
  int i = TOS - 1;    

  if (TOS == 0)
    return -1;
  
  while (i > 0) {
    if (ts[i].entry == FUNCTION && strcmp(name, ts[i].lex) == 0)
      return i;
    i--;
  }

  //printf("[SEMANTIC ERROR @ line %d] Identifier not declared: %s\n", line, e.lex);
  return -1;
}

void TS_AddId(attrs e) {
  int j = TOS - 1;    // Para añadir un id a la pila no se puede haber llegado al tope,
                      // el id no puede existir y se deben estar declarando variables
  int found = 0;
  int index;

  int numparams = ts[currentFunction].nParams;

  if (index != 1) {   // Comprobamos que la variable a añadir no es una redeclaración de un
                      // argumento de la función en la que se encuentra
    // Comparamos con los parámetros formales de la fución actual
    for (index = currentFunction+1; index < currentFunction+1+numparams; index++) {
      if (strcmp(ts[index].lex, e.lex) == 0) {  // Su nombre es el de un argumento de la función
        printf("[SEMANTIC ERROR @ line %d] Declaration error. Id already exists: %s\n", line, e.lex);
        return;
      }
    }
  }

  if (j >= 0 && decVar == 1) {  // Caso declaración de variable
    while (ts[j].entry != MARK && j >= 0 && !found) {   // Busca entrada con el mismo nombre
                                                        // dentro del bloque
      if (strcmp(ts[j].lex, e.lex) != 0) {
        j--;
      } else {
        found = 1;
        printf("[SEMANTIC ERROR @ line %d] Declaration error. Id already exists: %s\n", line, e.lex);
        return;
      }
    }
    if (!found) {
      inTS inFunction;
      inFunction.entry   = VAR;
      inFunction.lex     = e.lex;
      inFunction.type    = currentType;
      inFunction.nParams = 0;
      inFunction.nDim    = e.nDim;
      TS_AddEntry(inFunction);
    }
  }
}

void TS_AddMark() {
  inTS inInitScope;

  inInitScope.entry   = MARK;
  inInitScope.lex     = "{";
  inInitScope.type    = NONE;
  inInitScope.nParams = 0;
  inInitScope.nDim    = 0;

  TS_AddEntry(inInitScope);

  // Si es el cuerpo de una función, se añaden a la tabla de símbolos los parámetros/argumentos
  // de la función como variables locales de ese bloque al fin de poder ser utilizadas
  if (esFunc == 1) {
    int j = TOS - 2;    // TOS-2 para leer los parámetros formales de antes de la llave
    while (j > 0 && ts[j].entry == PARAM) {   // Mientras leamos parámetros formales los aniadimos
                                              // como variables locales al nuevo bloque
      inTS newIn;
      newIn.entry   = VAR;
      newIn.lex     = ts[j].lex;
      newIn.type    = ts[j].type;
      newIn.nParams = ts[j].nParams;
      newIn.nDim    = ts[j].nDim;
      TS_AddEntry(newIn);

      j--;
    }
  }
}

void TS_AddFunction(attrs e) {
  inTS inFunction;

  inFunction.entry   = FUNCTION;
  inFunction.lex     = e.lex;
  inFunction.type    = currentType;
  inFunction.nParams = 0;   // lo actualizaremos a continuación
  inFunction.nDim    = 0;
  inFunction.ended   = 0;

  currentFunction = TOS;    // actualizamos la función actual
  TS_AddEntry(inFunction);
}

void TS_AddParam(attrs e) {
  int j = TOS - 1;
  int found = 0;

  while (j != currentFunction && !found){   // Comprobamos si ya existe un argumento de esa
                                            // función con el mismo nombre
    if (strcmp(ts[j].lex, e.lex) != 0) {
      j--;
    } else {
      found = 1;
      printf("[SEMANTIC ERROR @ line %d] Declaration error. Param already exists: %s\n", line, e.lex);
    }
  }

  if (!found) {
    inTS inParam;
    inParam.entry   = PARAM;
    inParam.lex     = e.lex;
    inParam.type    = currentType;
    inParam.nParams = 0;
    inParam.nDim    = e.nDim;
    TS_AddEntry(inParam);

    if (currentFunction > -1)             // si no son los parámetros de entrada del programa
      ts[currentFunction].nParams += 1;   // actualiza el número de parámetros de la función
  }
}


void TS_CheckReturn(attrs expr, attrs *res) {
  int index = currentFunction;

  if (index > -1) {
    if (expr.type != ts[index].type) {
      printf("[SEMANTIC ERROR @ line %d] Return type of %s not equal to function type of %s\n",
        line, tDataToString(expr.type), tDataToString(ts[index].type));
      return;
    }
    attrs tmp;
    tmp.nDim = ts[index].nDim;

    if (!Check_EqualSize(expr, tmp)) {
      printf("[SEMANTIC ERROR @ line %d] Return expression not same size as return function\n", line);
    }

    res->type = expr.type;
    res->nDim = expr.nDim;
    return;
  } else {
    printf("[SEMANTIC ERROR @ line %d] Result not declared into function\n", line);
    return;
  }
}

char *strdup(const char *src) {
    char *dst = malloc(strlen (src) + 1);  // Space for length plus nul
    if (dst == NULL) return NULL;          // No memory
    strcpy(dst, src);                      // Copy the characters
    return dst;                            // Return the new string
}

void TS_GetById(attrs id, attrs *res) {
  int index = TS_FindById(id);
  if(index == -1) {   // No es ninguna variable de la TS
    //if (TS[index].entry != FUNCTION)
    printf("[SEMANTIC ERROR @ line %d] Search error. Id not found: %s\n", line, id.lex);
  } else {
    res->lex  = strdup(ts[index].lex);
    res->type = ts[index].type;
  }
}

int TS_GetType(attrs id) {
  int index = TS_FindById(id);
  if (index == -1) {   // No es ninguna variable de la TS
    //if (TS[index].entry != FUNCTION)
    printf("[SEMANTIC ERROR @ line %d] Search error. Id not found: %s\n", line, id.lex);
    return -1;
  } else {
    return ts[index].type;
  }
}

int TS_GetNDim(attrs id) {
  int index = TS_FindById(id);
  if (index != -1)
    return ts[index].nDim;
  else
    return 0;
}

void TS_FunctionCall(attrs *res) {
  //printf("CF:%d\n", currentFunction);
  //print_TS();
  if (currentFunction != -1) {
    if (checkParams != ts[currentFunction].nParams) {
      printf("[SEMANTIC ERROR @ line %d] Args error. Number of params not valid. Expected %d, but got %d\n",
        line, ts[currentFunction].nParams, checkParams);
      res->lex  = strdup(ts[currentFunction].lex);
      res->type = NONE;
      res->nDim = 0;
    } else {
      res->lex  = strdup(ts[currentFunction].lex);
      res->type = ts[currentFunction].type;
      res->nDim = ts[currentFunction].nDim;
    }
  }
}

void TS_CheckParam(attrs param) {
  checkParams += 1;
  int formalParam = currentFunction + checkParams;

  if (param.type != ts[formalParam].type && ts[formalParam].type > 0) {
    printf("[SEMANTIC ERROR @ line %d] Args error. Param type not valid. Expected %s, but got %s\n",
      line, tDataToString(ts[formalParam].type), tDataToString(param.type));
    return;
  }
}


void print_TS() {
  int j = 0;
  char *t, *e;

  printf("------------------------------\n");

  while (j <= TOS-1) {
    if (ts[j].entry == 0) { e = "MARK"; }
    if (ts[j].entry == 1) { e = "FUNCTION"; }
    if (ts[j].entry == 2) { e = "VAR"; }
    if (ts[j].entry == 3) { e = "PARAM"; }

    if (ts[j].type == 0) { t = "NONE"; }
    if (ts[j].type == 1) { t = "INT"; }
    if (ts[j].type == 2) { t = "FLOAT"; }
    if (ts[j].type == 3) { t = "CHAR"; }
    if (ts[j].type == 4) { t = "BOOLEAN"; }
    if (ts[j].type == 5) { t = "LIST_INT"; }
    if (ts[j].type == 6) { t = "LIST_FLOAT"; }
    if (ts[j].type == 7) { t = "LIST_CHAR"; }
    if (ts[j].type == 8) { t = "LIST_BOOLEAN"; }

    printf("[%d]\n", j);
    printf("  -Entrada: %-12s\n", e);
    printf("  -Lexema:  %-12s\n", ts[j].lex);
    printf("  -type:    %-10s\n", t);
    printf("  -nParams: %-4d\n", ts[j].nParams);

    printf("------------------------------\n");
    j++;
  }
  char strvar[100];
  printf("(Insert any value to continue:) ");
  fgets (strvar, 100, stdin);
}

void print_Attrs(attrs e, char *msg) {
  char *t;

    if (e.type == 0) { t = "NONE"; }
    if (e.type == 1) { t = "INT"; }
    if (e.type == 2) { t = "FLOAT"; }
    if (e.type == 3) { t = "CHAR"; }
    if (e.type == 4) { t = "BOOLEAN"; }
    if (e.type == 5) { t = "LIST_INT"; }
    if (e.type == 6) { t = "LIST_FLOAT"; }
    if (e.type == 7) { t = "LIST_CHAR"; }
    if (e.type == 8) { t = "LIST_BOOLEAN"; }

  printf("------------------------------\n");
  printf("%s\n", msg);
  printf("  - Atributos: %-4d\n", e.attr);
  printf("  - Lexema:    %-12s\n", e.lex);
  printf("  - type:      %-10s\n", t);
  printf("------------------------------\n");
}

int Check_EqualSize(attrs e1, attrs e2) {
  return e1.nDim == e2.nDim;
}

void Check_Assign(attrs e1, attrs e2) {
  int type = TS_GetType(e1);
  if (type != e2.type && e2.type != NONE && type > 0)
    printf("%s[SEMANTIC ERROR @ line %d] Assigning expression of type %s to %s, of type %s\n", DEBUG ? "{481}" : "",line, tDataToString(e2.type), e1.lex, tDataToString(TS_GetType(e1)));
  /* WIP unnecessary -> if (!Check_EqualSize(e1, e2))
    printf("[SEMANTIC ERROR @ line %d] Expression and %s are not the same size\n", line, e2.lex); */
}

void Check_Boolean(attrs e) {
  if (e.type != BOOLEAN)
    printf("%s[SEMANTIC ERROR @ line %d] Expected expression of type BOOLEAN, but got type %s\n", DEBUG ? "{489}" : "",line, tDataToString(e.type));
}

void Check_Int(attrs e) {
  if (e.type != INT)
    printf("%s[SEMANTIC ERROR @ line %d] Expected expression of type INT, but got type %s\n", DEBUG ? "{494}" : "",line, tDataToString(e.type));
}

void Check_ListSentence(attrs id) {
  int type = TS_GetType(id);
  if (type != -1 && !(type == LIST_INT || type == LIST_FLOAT || type == LIST_BOOLEAN || type == LIST_CHAR))
    printf("%s[SEMANTIC ERROR @ line %d] %s is not of type LIST, but type %s\n", DEBUG ? "{499}" : "",line, id.lex, tDataToString(type));
}

void Check_OpUnaryNeg(attrs op, attrs expr, attrs *res) {
  if (expr.type != BOOLEAN) {
    printf("%s[SEMANTIC ERROR @ line %d] Unary operator ! expects expression of type ![BOOLEAN], but got type ![%s]\n",
      DEBUG ? "{505}" : "",line, tDataToString(expr.type));
    return ;
  }
  res->type = BOOLEAN;
  res->nDim = 0;
}

void Check_OpUnaryCount(attrs op, attrs expr, attrs *res) {
  if (!isList(expr)) {
    printf("%s[SEMANTIC ERROR @ line %d] Unary operator # expects expression of type #[LIST], but got type #[%s]\n",
      DEBUG ? "{515}" : "",line, tDataToString(expr.type));
    return ;
  }
  res->type = INT;
  res->nDim = 0;
}

void Check_OpUnaryQuest(attrs op, attrs expr, attrs *res) {
  if (!isList(expr)) {
    printf("%s[SEMANTIC ERROR @ line %d] Unary operator ? expects expression of type ?[LIST], but got type ?[%s]\n",
      DEBUG ? "{525}" : "",line, tDataToString(expr.type));
    return ;
  }
  res->type = listToType(expr.type);
  res->nDim = 0;
}

void Check_IncrementDecrement(attrs op, attrs expr, attrs *res) {
  if (!(expr.type == INT || expr.type == FLOAT)) {
    printf("%s[SEMANTIC ERROR @ line %d] Unary operator %s expects expression of type %s[INT|FLOAT], but got type %s[%s]\n",
      DEBUG ? "{535}" : "",line, op.lex, op.lex, op.lex, tDataToString(expr.type));
  }
  res->type = expr.type;
  res->nDim = expr.nDim;
}

void Check_PlusMinusBinary(attrs expr1, attrs op, attrs expr2, attrs *res) {
  // WIP sólo permitimos la suma y resta de INTs/flotantes (¿suma/resta de char/bool?)
  if (!(expr1.type == INT || expr1.type == LIST_INT || expr1.type == FLOAT || expr1.type == LIST_FLOAT) ||
    !(expr2.type == INT || expr2.type == LIST_INT || expr2.type == FLOAT || expr2.type == LIST_FLOAT)) {
    printf("%s[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [INT|FLOAT|LIST OF INT|LIST OF FLOAT]%s[INT|FLOAT|LIST OF INT|LIST OF FLOAT], but got types [%s]%s[%s]\n",
      DEBUG ? "{544}" : "",line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
    res->type = NONE;
    return ;
  }

  // casting int->float
  int resType = INT;
  if (expr1.type == FLOAT || expr1.type == LIST_FLOAT || expr2.type == FLOAT || expr2.type == LIST_FLOAT)
    resType = FLOAT;

  if (!isList(expr1) && !isList(expr2)) {
    res->type = resType;
    res->nDim = 0;
  } else {
    // alguno de ellos es array
    if (isList(expr1) && !isList(expr2)) {
      // lista+valor ó lista-valor (ambas operaciones posibles)
      res->type = resType == INT ? LIST_INT : LIST_FLOAT;  // WIP comprobar si correcto en C
      res->nDim = expr1.nDim;
    } else if (!isList(expr1) && isList(expr2)) {
      // sólo permitir valor+lista
      if (op.attr == 1) {
        printf("%s[SEMANTIC ERROR @ line %d] Binary operator - does not allow expressions of types [NOT LIST]-[LIST], but got types [%s]-[%s]\n",
          DEBUG ? "{572}" : "",line, tDataToString(expr1.type), tDataToString(expr2.type));
        return ;
      }
      res->type = resType == INT ? LIST_INT : LIST_FLOAT;   // WIP ídem
      res->nDim = expr2.nDim;
    } else {
      printf("%s[SEMANTIC ERROR @ line %d] Binary operator %s does not allow expressions of types [LIST]%s[LIST], but got types [%s]%s[%s]\n",
        DEBUG ? "{578}" : "",line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
    }
  }
}

void Check_PlusMinus(attrs op, attrs expr, attrs *res) {
  if (!(expr.type == INT || expr.type == FLOAT)) {
    printf("%s[SEMANTIC ERROR @ line %d] Unary operator %s expects expression of type %s[INT|FLOAT], but got type %s[%s]\n",
      DEBUG ? "{584}" : "",line, op.lex, op.lex, op.lex, tDataToString(expr.type));
    return ;
  }
  res->type = expr.type;
  res->nDim = 0;
}

void Check_OpBinaryMul(attrs expr1, attrs op, attrs expr2, attrs *res) {
  if (op.attr == 0) {  // %
    // int % int
    if (expr1.type == INT && expr2.type == INT) {
      res->type = INT;
      res->nDim = 0;
    // list % int
    } else if (isList(expr1) && expr2.type == INT) {
      res->type = expr1.type;
      res->nDim = atoi(expr2.lex); // WIP comprobar
    } else {
      printf("%s[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [INT]%s[INT] or [LIST]%s[INT], but got [%s]%s[%s]\n",
        DEBUG ? "{605}" : "",line, op.lex, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
    }
  } else if (op.attr == 3) {  // **
    if (isList(expr1) && isList(expr2)) {
      // both must be of the same type
      if (expr1.type == expr2.type) {
        res->type = expr1.type;
        res->nDim = expr1.nDim + expr2.nDim;
      } else {
        printf("%s[SEMANTIC ERROR @ line %d] Binay operator ** expects expressions of types [LIST OF x]**[LIST OF x] (lists of same type), but got [%s]**[%s]\n",
          DEBUG ? "{615}" : "",line, tDataToString(expr1.type), tDataToString(expr2.type));
      }
    } else {
      printf("%s[SEMANTIC ERROR @ line %d] Binary operator ** expects expressions of types [LIST]**[LIST], but got [%s]**[%s]\n",
        DEBUG ? "{619}" : "",line, tDataToString(expr1.type), tDataToString(expr2.type));
    }
  } else {  // * /
    // WIP sólo permitimos producto/división de INTs/flotantes (¿de char/bool?)
    if (!(expr1.type == INT || expr1.type == LIST_INT || expr1.type == FLOAT || expr1.type == LIST_FLOAT) ||
      !(expr2.type == INT || expr2.type == LIST_INT || expr2.type == FLOAT || expr2.type == LIST_FLOAT)) {
      printf("%s[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [INT|FLOAT|LIST OF INT|LIST OF FLOAT]%s[INT|FLOAT|LIST OF INT|LIST OF FLOAT], but got [%s]%s[%s]\n",
        DEBUG ? "{626}" : "",line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
      return ;
    }

    // casting int->float
    int resType = INT;
    if (expr1.type == FLOAT || expr1.type == LIST_FLOAT || expr2.type == FLOAT || expr2.type == LIST_FLOAT)
      resType = FLOAT;

    if (!isList(expr1) && !isList(expr2)) {
      res->type = resType;
      res->nDim = 0;
    } else {
      // alguno de ellos es array
      if (isList(expr1) && !isList(expr2)) {
        // lista+valor ó lista-valor (ambas operaciones posibles)
        res->type = resType == INT ? LIST_INT : LIST_FLOAT;  // WIP comprobar si correcto en C
        res->nDim = expr1.nDim;
      } else if (!isList(expr1) && isList(expr2)) {
        // sólo permitir valor+lista
        if (op.attr == 2) {
          printf("%s[SEMANTIC ERROR @ line %d] Binary operator / does not allow expressions of types [NOT LIST]/[LIST], but got [%s]/[%s]\n",
            DEBUG ? "{648}" : "",line, tDataToString(expr1.type), tDataToString(expr2.type));
          return ;
        }
        res->type = resType == INT ? LIST_INT : LIST_FLOAT;   // WIP ídem
        res->nDim = expr2.nDim;
      } else {
        printf("%s[SEMANTIC ERROR @ line %d] Binary operator %s does not allow expressions of types [LIST]%s[LIST], but got types [%s]%s[%s]\n",
          DEBUG ? "{655}" : "",line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
      }
    }
  }
}

void Check_OpBinaryAndOr(attrs expr1, attrs op, attrs expr2, attrs *res) {
  if (expr1.type == BOOLEAN && expr2.type == BOOLEAN) {
    res->type = BOOLEAN;
    res->nDim = 0;
    return ;
  }
  printf("%s[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [BOOLEAN]%s[BOOLEAN], but got [%s]%s[%s]\n",
    DEBUG ? "{668}" : "",line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
}

void Check_OpBinaryRel(attrs expr1, attrs op, attrs expr2, attrs *res) {
  if ((expr1.type == INT || expr1.type == FLOAT || expr1.type == CHAR) && (expr2.type == INT || expr2.type == FLOAT || expr2.type == CHAR)) {
    res->type = BOOLEAN;
    res->nDim = 0;
    return ;
  }
  printf("%s[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [INT|FLOAT|CHAR]%s[INT|FLOAT|CHAR], but got [%s]%s[%s]\n",
    DEBUG ? "{678}" : "",line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
}

void Check_OpBinaryEq(attrs expr1, attrs op, attrs expr2, attrs *res) {
  if (isList(expr1) || isList(expr2)) {
    printf("%s[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [NOT LIST]%s[NOT LIST], but got [%s]%s[%s]\n",
      DEBUG ? "{684}" : "",line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
    return ;
  }
  if (expr1.type == expr2.type) {
    res->type = BOOLEAN;
    res->nDim = 0;
    return ;
  }
  printf("%s[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [x]%s[x] (same type), but got [%s]%s[%s]\n",
    DEBUG ? "{693}" : "",line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
}

// WIP si hacemos IDENTIFIER AT expresion, debemos de hacer TS_GetById
void Check_At(attrs expr1, attrs op, attrs expr2, attrs *res) {
  if (isList(expr1) && expr2.type == INT) {
    res->type = listToType(expr1.type);
    res->nDim = 0;
    return ;
  }
  printf("%s[SEMANTIC ERROR @ line %d] Binary operator @ expects expressions of types [LIST]@[INT], but got [%s]@[%s]\n",
    DEBUG ? "{704}" : "", line, tDataToString(expr1.type), tDataToString(expr2.type));
  res->type = NONE;
  res->nDim = 0;
}

void Check_MinusMinus(attrs expr1, attrs op, attrs expr2, attrs *res) {
  if (isList(expr1) && expr2.type == INT) {
    res->type = expr1.type;
    res->nDim = expr1.nDim - 1;
  } else {
    printf("%s[SEMANTIC ERROR @ line %d] Binary operator -- expects expressions of types [LIST]--[INT], but got [%s]--[%s]\n",
      DEBUG ? "{715}" : "", line, tDataToString(expr1.type), tDataToString(expr2.type));
  }
}

void sacarTF(){
	if(DEBUG) printf("sacar()\n");
   if (TOPEFLUJO > 0) {
      --TOPEFLUJO;
   }
}

void Check_ListTernary(attrs expr1, attrs op1, attrs expr2, attrs op2, attrs expr3, attrs *res) {
  if (!isList(expr1) || listToType(expr1.type) != expr2.type || expr3.type != INT) {
    printf("%s[SEMANTIC ERROR @ line %d] Ternary operator ++ @ expects expressions of types [LIST OF x]++[x]@[INT], but got types [%s]++[%s]@[%s]\n",
      DEBUG ? "{722}" : "",line, tDataToString(expr1.type), tDataToString(expr2.type), tDataToString(expr3.type));
    return ;
  }
  res->type = expr1.type;
  res->nDim = expr1.nDim + 1;
}

void Check_FunctionCall(attrs id) {
  currentFunction = TS_FindByName(id);

  if (currentFunction == -1)
    printf("%s[SEMANTIC ERROR @ line %d] Function with name %s not found\n", DEBUG ? "{734}" : "",line, id.lex);
}

void VarList_Id(attrs id, attrs *res) {
  if (decVar == 1)
    TS_AddId(id);
  else
    TS_GetById(id, res);
}




/* PRÁCTICA 5 */

int etiqueta = -1;

char* generarTemp(tData tipo){
  char* cadena = (char*) malloc(30);
  ++temp;
  if(tipo == LIST_INT || tipo == LIST_FLOAT || tipo == LIST_CHAR || tipo == LIST_BOOLEAN)
    sprintf(cadena, "%s temp%d = NULL;\n%stemp%d", tipoDeDato(tipo), temp, numTabs(), temp);
  else
    sprintf(cadena, "%s temp%d;\n%stemp%d", tipoDeDato(tipo), temp, numTabs(), temp);
  return cadena;
}

void copiarEF(etiquetaFlujo *dest, etiquetaFlujo *source){
  if (source->EtiquetaEntrada != NULL)   dest->EtiquetaEntrada = strdup(source->EtiquetaEntrada) ;
  if (source->EtiquetaSalida != NULL)    dest->EtiquetaSalida = strdup(source->EtiquetaSalida) ;
  if (source->EtiquetaElse != NULL)    dest->EtiquetaElse = strdup(source->EtiquetaElse) ;
  if (source->NombreVarControl != NULL)  dest->NombreVarControl = strdup(source->NombreVarControl) ;
}

char* generarEtiqueta() {
  char* cadena = (char*) malloc(20);
  ++etiqueta;
  sprintf(cadena, "etiqueta%d", etiqueta);
  return cadena;
}

void generarFicheroFunciones() {
  file_fun = fopen("dec_fun.h", "w");
  fputs("#include<stdio.h>\n", file_fun);
  fputs("#include \"dec_dat.h\"\n\n", file_fun);
  fputs("typedef int bool;\n", file_fun);
}

void generarFichero() {
  file_std = fopen("codigoGenerado.c", "w");
  file = file_std;
  fputs("#include<stdio.h>\n", file);
  fputs("#include \"dec_fun.h\"\n", file);
  //fputs("#include \"dec_dat.h\"\n\n", file);
  fputs("typedef int bool;\n\n", file);
  generarFicheroFunciones();
}

void cerrarFichero() {
  fclose(file);
  fclose(file_fun);
}

char* tipoDeDato (tData td) {
  switch (td) {
    case NONE:
      return "None";
    case INT:
      return "int";
    case BOOLEAN:
      return "bool";
    case FLOAT:
      return "float";
    case CHAR:
      return "char";
    case LIST_INT:
    case LIST_BOOLEAN:
    case LIST_FLOAT:
    case LIST_CHAR:
      return "List";
    default:
      return "/* error */";
  }
}

void insertarParametros(char* nom, int numArgumentos){
  int index;

  for(int i=numArgumentos; i>0; --i) {
    if(i!=numArgumentos)
      fputs(",",file);
    index = TS_FindByNameChar(nom);
    char* nombre = ts[index-i].lex;
    char* midato = tipoDeDato(ts[index-i].type);
    char* sent;
    sent = (char*) malloc(200);;
    sprintf(sent, "%s %s", midato, nombre);
    fputs(sent, file);
  }
}

/*
void insertarSubprog(char* nom, tData dato, int numArgumentos){
  char* sent;
  sent = (char*) malloc(200);
  sprintf(sent,"%s %s (", tipoDeDato(dato), nom);
  fputs(sent, file);
  insertarParametros(nom, numArgumentos);
  fputs(")", file);
}


void insertarVariables(tData dato){
  int i;
  bool fin = false;
  bool coma = false;
  char* sent;
  sent = (char*) malloc(200);
  sprintf(sent, "%s%s ", tabs, tipoDeDato(dato));

  for(i=0; i<TOPE && fin==false; ++i){
    if(ts[TOPE-1-i].entrada == 3 && ts[TOPE-1-i].tipoDato == dato){
      if(coma) sprintf(sent,"%s,",sent);
      sprintf(sent, "%s %s", sent, ts[TOPE-1-i].nombre);
      coma = true;
    }
    else{
      fin=true;
    }
  }

  sprintf(sent, "%s;\n", sent);
  fputs(sent, file);
}

*/

void insertarAsignacion(char* nom, char* valor) {
  char* sent = (char*) malloc(200);
  sprintf(sent, "%s%s = %s;\n", tabs, nom, valor);
  fputs(sent, file);
}

void insertarCadena(char* cad){
  fputs(cad, file);
}

char tipoAFormato(tData dato) {
  if(dato == NONE)    return 's';
  else if(dato == FLOAT)    return 'f';
  else if(dato == INT)    return 'd';
  else if(dato == CHAR)  return 'c';
  else if(dato == LIST_CHAR /*WIP WARN*/ )  return 's';
  else if(dato == BOOLEAN)  return 'd';
  else             return 'l';
}

char* tipoAPuntero(tData dato){
  if(dato == NONE)    return " s";
  else if(dato == FLOAT)    return " &";
  else if(dato == INT)    return " &";
  else if(dato == CHAR)  return " &";
  else if(dato == LIST_CHAR /*WIP WARN*/ )  return " ";
  else if(dato == BOOLEAN)  return " &";
  else             return " ";
}

char* numTabs(){
  char* aux = (char*) malloc(50);
  sprintf(aux, "");
  for( int i=0; i<contBloques-contBloquesPrimeraFun; ++i )
    sprintf(aux, "%s\t", aux);
  return aux;
}

void concatenarStrings1(char* destination, char* source1){
  if( destination == NULL)
    destination = (char *) malloc(200);
  sprintf(destination, "%s", source1);
}

void concatenarStrings2(char* destination, char* source1, char* source2){
  if( destination == NULL)
    destination = (char *) malloc(200);
  sprintf(destination, "%s%s", source1, source2);
}

void concatenarStrings3(char* destination, char* source1, char* source2, char* source3){
  if( destination == NULL)
    destination = (char *) malloc(200);
  sprintf(destination, "%s,%s", source2, source3);
}

void concatenarStrings4(char* destination, char* s1, char* s2, char* s3, char* s4){
  if( destination == NULL)
    destination = (char *) malloc(200);
  sprintf(destination, "%s%s%s%s", s1, s2, s3, s4);
}

void concatenarStrings5(char* destination, char* s1, char* s2, char* s3, char* s4, char* s5){
  if( destination == NULL)
    destination = (char *) malloc(200);
  sprintf(destination, "%s%s%s%s%s", s1, s2, s3, s4, s5);
}

void mensajeErrorTipo1(inTS ts, tData esperado){
	if (ts.type != NONE && esperado != NONE){
		if( ts.entry == VAR )
			printf("Error semantico en la linea %d: La variable %s no es de tipo %s\n", numLinea, ts.lex, tDataToString(esperado));
		else if( ts.entry == FUNCTION )
			printf("Error semantico en la linea %d: La funcion %s no devuelve valores de tipo %s\n", numLinea, ts.lex,tDataToString(esperado));
		else printf("Error semantico en la linea %d: La expresion no es de tipo %s\n", numLinea, tDataToString(esperado));
	}
}