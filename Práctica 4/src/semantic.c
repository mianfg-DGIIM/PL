#include "semantic.h"
#define DEBUG 0

inTS     ts[MAX_STACK];
long int TOS             = 0;
int      line            = 1;
int      decVar          = 0;
int      decParam        = 0;
int      esFunc          = 0;
tData    currentType     = NONE;
int      nParams         = 0;
int      checkParams     = 0;
int      checkFunction   = 0;
int      currentFunction = -1;


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
    case NONE:
      return "NONE";
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
    printf("{94}[SEMANTIC ERROR @ line %d] Symbol table overflow", line);
    return -1;
  }
}

int TS_DeleteEntry() {
  if (TOS > 0) {  // Si la tabla de símbolos tiene alguna in puede eliminar la última
    TOS--;
    return 1;
  } else {
    printf("{104}[SEMANTIC ERROR @ line %d] Empty symbol table", line);
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
        printf("{232}[SEMANTIC ERROR @ line %d] Declaration error. Id already exists: %s\n", line, e.lex);
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
        printf("{245}[SEMANTIC ERROR @ line %d] Declaration error. Id already exists: %s\n", line, e.lex);
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
      printf("{315}[SEMANTIC ERROR @ line %d] Declaration error. Param already exists: %s\n", line, e.lex);
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
      printf("{340}[SEMANTIC ERROR @ line %d] Return type of %s not equal to function type of %s\n",
        line, tDataToString(expr.type), tDataToString(ts[index].type));
      return;
    }
    attrs tmp;
    tmp.nDim = ts[index].nDim;

    if (!Check_EqualSize(expr, tmp)) {
      printf("{348}[SEMANTIC ERROR @ line %d] Return expression not same size as return function\n", line);
    }

    res->type = expr.type;
    res->nDim = expr.nDim;
    return;
  } else {
    printf("{355}[SEMANTIC ERROR @ line %d] Result not declared into function\n", line);
    return;
  }
}

void TS_GetById(attrs id, attrs *res) {
  int index = TS_FindById(id);
  if(index == -1) {   // No es ninguna variable de la TS
    //if (TS[index].entry != FUNCTION)
    printf("{364}[SEMANTIC ERROR @ line %d] Search error. Id not found: %s\n", line, id.lex);
  } else {
    res->lex  = strdup(ts[index].lex);
    res->type = ts[index].type;
  }
}

int TS_GetType(attrs id) {
  int index = TS_FindById(id);
  if (index == -1) {   // No es ninguna variable de la TS
    //if (TS[index].entry != FUNCTION)
    printf("{375}[SEMANTIC ERROR @ line %d] Search error. Id not found: %s\n", line, id.lex);
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
      printf("{386}[SEMANTIC ERROR @ line %d] Args error. Number of params not valid. Expected %d, but got %d\n",
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
    printf("{403}[SEMANTIC ERROR @ line %d] Args error. Param type not valid. Expected %s, but got %s\n",
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
    printf("{466}[SEMANTIC ERROR @ line %d] Assigning expression of type %s to %s, of type %s\n", line, tDataToString(e2.type), e1.lex, tDataToString(TS_GetType(e1)));
  /* WIP unnecessary -> if (!Check_EqualSize(e1, e2))
    printf("{468}[SEMANTIC ERROR @ line %d] Expression and %s are not the same size\n", line, e2.lex); */
}

void Check_Boolean(attrs e) {
  if (e.type != BOOLEAN)
    printf("{476}[SEMANTIC ERROR @ line %d] Expected expression of type BOOLEAN, but got type %s\n", line, tDataToString(e.type));
}

void Check_Int(attrs e) {
  if (e.type != INT)
    printf("{481}[SEMANTIC ERROR @ line %d] Expected expression of type INT, but got type %s\n", line, tDataToString(e.type));
}

void Check_ListSentence(attrs id) {
  int type = TS_GetType(id);
  if (type != -1 && !(type == LIST_INT || type == LIST_FLOAT || type == LIST_BOOLEAN || type == LIST_CHAR))
    printf("{474}[SEMANTIC ERROR @ line %d] %s is not of type LIST, but type %s\n", line, id.lex, tDataToString(type));
}

void Check_OpUnaryNeg(attrs op, attrs expr, attrs *res) {
  if (expr.type != BOOLEAN) {
    printf("{499}[SEMANTIC ERROR @ line %d] Unary operator ! expects expression of type ![BOOLEAN], but got type ![%s]\n",
      line, tDataToString(expr.type));
    return ;
  }
  res->type = BOOLEAN;
  res->nDim = 0;
}

void Check_OpUnaryCount(attrs op, attrs expr, attrs *res) {
  if (!isList(expr)) {
    printf("{481}[SEMANTIC ERROR @ line %d] Unary operator # expects expression of type #[LIST], but got type #[%s]\n",
      line, tDataToString(expr.type));
    return ;
  }
  res->type = INT;
  res->nDim = 0;
}

void Check_OpUnaryQuest(attrs op, attrs expr, attrs *res) {
  if (!isList(expr)) {
    printf("{490}[SEMANTIC ERROR @ line %d] Unary operator ? expects expression of type ?[LIST], but got type ?[%s]\n",
      line, tDataToString(expr.type));
    return ;
  }
  res->type = listToType(expr.type);
  res->nDim = 0;
}

void Check_IncrementDecrement(attrs op, attrs expr, attrs *res) {
  if (!(expr.type == INT || expr.type == FLOAT)) {
    printf("{522}[SEMANTIC ERROR @ line %d] Unary operator %s expects expression of type %s[INT|FLOAT], but got type %s[%s]\n",
      line, op.lex, op.lex, op.lex, tDataToString(expr.type));
  }
  res->type = expr.type;
  res->nDim = expr.nDim;
}

void Check_PlusMinusBinary(attrs expr1, attrs op, attrs expr2, attrs *res) {
  // WIP sólo permitimos la suma y resta de enteros/flotantes (¿suma/resta de char/bool?)
  if (!(expr1.type == INT || expr1.type == LIST_INT || expr1.type == FLOAT || expr1.type == LIST_FLOAT) ||
    !(expr2.type == INT || expr2.type == LIST_INT || expr2.type == FLOAT || expr2.type == LIST_FLOAT)) {
    printf("{526}[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [INT|FLOAT|LIST OF INT|LIST OF FLOAT]%s[INT|FLOAT|LIST OF INT|LIST OF FLOAT], but got types [%s]%s[%s]\n",
      line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
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
        printf("{550}[SEMANTIC ERROR @ line %d] Binary operator - does not allow expressions of types [NOT LIST]-[LIST], but got types [%s]-[%s]\n",
          line, tDataToString(expr1.type), tDataToString(expr2.type));
        return ;
      }
      res->type = resType == INT ? LIST_INT : LIST_FLOAT;   // WIP ídem
      res->nDim = expr2.nDim;
    } else {
      printf("{557}[SEMANTIC ERROR @ line %d] Binary operator %s does not allow expressions of types [LIST]%s[LIST], but got types [%s]%s[%s]\n",
        line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
    }
  }
}

void Check_PlusMinus(attrs op, attrs expr, attrs *res) {
  if (!(expr.type == INT || expr.type == FLOAT)) {
    printf("{514}[SEMANTIC ERROR @ line %d] Unary operator %s expects expression of type %s[INT|FLOAT], but got type %s[%s]\n",
      line, op.lex, op.lex, op.lex, tDataToString(expr.type));
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
      printf("{675}[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [INT]%s[INT] or [LIST]%s[INT], but got [%s]%s[%s]\n",
        line, op.lex, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
    }
  } else if (op.attr == 3) {  // **
    if (isList(expr1) && isList(expr2)) {
      // both must be of the same type
      if (expr1.type == expr2.type) {
        res->type = expr1.type;
        res->nDim = expr1.nDim + expr2.nDim;
      } else {
        printf("{571}[SEMANTIC ERROR @ line %d] Binay operator ** expects expressions of types [LIST OF x]**[LIST OF x] (lists of same type), but got [%s]**[%s]\n",
          line, tDataToString(expr1.type), tDataToString(expr2.type));
      }
    } else {
      printf("{575}[SEMANTIC ERROR @ line %d] Binary operator ** expects expressions of types [LIST]**[LIST], but got [%s]**[%s]\n",
        line, tDataToString(expr1.type), tDataToString(expr2.type));
    }
  } else {  // * /
    // WIP sólo permitimos producto/división de enteros/flotantes (¿de char/bool?)
    if (!(expr1.type == INT || expr1.type == LIST_INT || expr1.type == FLOAT || expr1.type == LIST_FLOAT) ||
      !(expr2.type == INT || expr2.type == LIST_INT || expr2.type == FLOAT || expr2.type == LIST_FLOAT)) {
      printf("{632}[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [INT|FLOAT|LIST OF INT|LIST OF FLOAT]%s[INT|FLOAT|LIST OF INT|LIST OF FLOAT], but got [%s]%s[%s]\n",
        line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
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
          printf("{654}[SEMANTIC ERROR @ line %d] Binary operator / does not allow expressions of types [NOT LIST]/[LIST], but got [%s]/[%s]\n",
            line, tDataToString(expr1.type), tDataToString(expr2.type));
          return ;
        }
        res->type = resType == INT ? LIST_INT : LIST_FLOAT;   // WIP ídem
        res->nDim = expr2.nDim;
      } else {
        printf("{661}[SEMANTIC ERROR @ line %d] Binary operator %s does not allow expressions of types [LIST]%s[LIST], but got types [%s]%s[%s]\n",
          line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
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
  printf("{598}[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [BOOLEAN]%s[BOOLEAN], but got [%s]%s[%s]\n",
    line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
}

void Check_OpBinaryRel(attrs expr1, attrs op, attrs expr2, attrs *res) {
  if ((expr1.type == INT || expr1.type == FLOAT || expr1.type == CHAR) && (expr2.type == INT || expr2.type == FLOAT || expr2.type == CHAR)) {
    res->type = BOOLEAN;
    res->nDim = 0;
    return ;
  }
  printf("{623}[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [INT|FLOAT|CHAR]%s[INT|FLOAT|CHAR], but got [%s]%s[%s]\n",
    line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
}

void Check_OpBinaryEq(attrs expr1, attrs op, attrs expr2, attrs *res) {
  if (isList(expr1) || isList(expr2)) {
    printf("{604}[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [NOT LIST]%s[NOT LIST], but got [%s]%s[%s]\n",
      line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
    return ;
  }
  if (expr1.type == expr2.type) {
    res->type = BOOLEAN;
    res->nDim = 0;
    return ;
  }
  printf("{613}[SEMANTIC ERROR @ line %d] Binary operator %s expects expressions of types [x]%s[x] (same type), but got [%s]%s[%s]\n",
    line, op.lex, op.lex, tDataToString(expr1.type), op.lex, tDataToString(expr2.type));
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

void Check_ListTernary(attrs expr1, attrs op1, attrs expr2, attrs op2, attrs expr3, attrs *res) {
  if (!isList(expr1) || listToType(expr1.type) != expr2.type || expr3.type != INT) {
    printf("{693}[SEMANTIC ERROR @ line %d] Ternary operator ++ @ expects expressions of types [LIST OF x]++[x]@[INT], but got types [%s]++[%s]@[%s]\n",
      line, tDataToString(expr1.type), tDataToString(expr2.type), tDataToString(expr3.type));
    return ;
  }
  res->type = expr1.type;
  res->nDim = expr1.nDim + 1;
}

void Check_FunctionCall(attrs id) {
  currentFunction = TS_FindByName(id);

  if (currentFunction == -1)
    printf("{706}[SEMANTIC ERROR @ line %d] Function with name %s not found\n", line, id.lex);
}

void VarList_Id(attrs id, attrs *res) {
  if (decVar == 1)
    TS_AddId(id);
  else
    TS_GetById(id, res);
}
