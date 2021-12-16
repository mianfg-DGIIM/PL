#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_t {
    int data;
    struct Node_t* next;
	struct Node_t* previous;
} Node;

typedef enum {
  NONE = 0,   /** Aún no se ha asignado el tipo para la inicialización */
  INT,                /** Entero */
  FLOAT,              /** Flotante */
  CHAR,               /** Caracter */
  BOOLEAN,            /** Booleano */
  LIST_INT,           /** Lista de enteros */
  LIST_FLOAT,         /** Lista de flotantes */
  LIST_CHAR,          /** Lista de caracteres */
  LIST_BOOLEAN,       /** Lista de booleanos */
} tData;
typedef Node* List;

void next(Node** l){
	if (l == NULL)
		return;
    if (*l == NULL)
        return;
	if ((*l)->next != NULL)
		*l = (*l)->next;
}

void previous(Node** l){
	if (l == NULL)
		return;
    if (*l == NULL)
        return;
	if ((*l)->previous != NULL)
		(*l) = (*l)->previous;
}

void begin(Node** l){
	if (l == NULL)
		return;
    if ((*l) == NULL)
        return;
	while ((*l)->previous != NULL)
		previous(l);
}

void end(Node** l){
	if (l == NULL)
		return;
	if ((*l) == NULL)
        return;
	while ((*l)->next != NULL)
		next(l);
}

void push(Node** l, int new_data)
{
    Node** aux = l;
    if(aux != NULL){
        end(aux);
    }
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = NULL;
    new_node->previous = *aux;
    if(*aux != NULL) (*aux)->next = new_node;
    else *l = new_node;
}

void printList(Node* l)
{
	if (l == NULL)
		return;
    Node* aux = l;
    int first = 1;
	begin(&aux);
	printf("[");
    while (aux != NULL)
    {
        if (first)
            printf("%d", aux->data);
        else
		      printf(", %d", aux->data);
        aux = aux->next;
        first = 0;
    }
	printf("]\n");
}

void printListNext(Node* l)
{
	if (l == NULL)
		return;
    Node* aux = l;
    int first = 1;
	begin(&aux);
    while (aux != NULL)
    {
		//printf("aux == NULL: %d\n", aux == NULL);
		//printf("aux->next == NULL: %d\n", aux->next == NULL);
        aux = aux->next;
        first = 0;
    }
}

unsigned int length(Node* l){
	if (l == NULL)
		return 0;
	unsigned int count = 1;
	Node* aux = l;
	begin(&aux);
	while(aux->next != NULL){
		next(&aux);
		++count;
	}
	return count;
}

int currentData(Node* l){
    if(l == NULL)
        return 0;
	return l->data;
}

int dataAt(Node* l, unsigned int pos){
	if (l == NULL)
		return 0;
	if (pos >= length(l))
		return 0;
	Node* aux = l;
	begin(&aux);
	for(int i = 0; i < pos; ++i){
		next(&aux);
	}
	return currentData(aux);
}

Node* addAt(Node* l, unsigned int pos, int dat){
	if (l == NULL)
		return NULL;
	if (pos >= length(l))
		pos = length(l)-1;
	Node* aux = l;
	begin(&aux);
	for(int i = 0; i < pos; ++i){
		next(&aux);
	}
	Node* n = malloc(sizeof(Node));
	n->previous = aux->previous;
	n->next = aux;
    if(aux->previous != NULL)
	   (aux->previous)->next = n;
	aux->previous = n;
	n->data = dat;
	return l;
}

Node* deleteAt(Node* l, unsigned int pos){
	if (l == NULL)
		return NULL;
	if (pos >= length(l))
		return NULL;
	Node* aux = l;
	begin(&aux);
	for(int i = 0; i < pos; ++i){
		next(&aux);
	}
    if(aux->previous != NULL)
	   (aux->previous)->next = aux->next;
    if(aux->next!=NULL)
	   (aux->next)->previous = aux->previous;
	if (aux == l)
		l = aux->next;
	free(aux);
	return l;
}

Node* deleteSince(Node* l, unsigned int pos){
	if (l == NULL)
		return NULL;
	if (pos >= length(l))
		return NULL;
	Node* aux = l;
	begin(&aux);
	for(unsigned int i=0; i<pos-1; ++i)
		next(&aux);
    aux->next = NULL;
    /*
    Node* node_aux = aux;
	Node* node_last = aux;
	while (node_aux->next != NULL){
		if (node_aux == l)
			l = node_last;
		node_aux = aux->next;
		free(aux);
	}
	free(node_aux);*/
    return l;
}

/*
Node* concatenate(Node** l1, Node** l2){
	if (l1 == NULL)
		return *l2;
	else if (l2 == NULL)
		return *l1;

    begin(l1);
    begin(l2);
    Node** res;

    do{
        push(res, currentData(*l1));
        next(l1);
    }while((l1!=NULL));

    do{sip
        push(res, currentData(*l2));
        next(l2);
    }while((l2!=NULL));

	return *res;
}
*/

Node* concatenate(Node** l1, Node** l2){
	if (l1 == NULL && l2 == NULL)
		return NULL;
	if (l1 == NULL)
        return *l2;
    else if (l2 == NULL)
        return *l1;
    if (*l1 == NULL)
        return *l2;
    else if (*l2 == NULL)
        return *l1;

    end(l1);
    begin(l2);
    (*l1)->next = *l2;
    (*l2)->previous = *l1;
    begin(l1);
    return *l1;
}

Node* sum(Node* l, int dat){
	if (l == NULL)
		return NULL;
    //printf("HOLA\n");
	Node* aux = l;
	begin(&aux);
	//printf("%d", aux);
	if(aux != NULL)	aux->data = aux->data + dat;
	while(aux->next != NULL){
		//printf("aux: %d\n", aux);
        //printf("aux->next: %d\n", aux->next);
        aux->next->data = aux->next->data + dat;
		next(&aux);
	}
	return l;
}

Node* subtract(Node* l, int dat){
	if (l == NULL)
		return NULL;
	Node* aux = l;
	begin(&aux);
	if(aux != NULL)	aux->data = aux->data - dat;
	while(aux->next != NULL){
        aux->next->data = aux->next->data - dat;
		next(&aux);
	}
	return l;
}

Node* mult(Node* l, int dat){
	if (l == NULL)
		return NULL;
	Node* aux = l;
	begin(&aux);
	if(aux != NULL)	aux->data = aux->data * dat;
	while(aux->next != NULL){
        aux->next->data = aux->next->data * dat;
		next(&aux);
	}
	return l;
}

Node* divi(Node* l, int dat){
	if (l == NULL || dat == 0)
		return NULL;
	Node* aux = l;
	begin(&aux);
	if(aux != NULL)	aux->data = aux->data / dat;
	while(aux->next != NULL){
        aux->next->data = aux->next->data / dat;
		next(&aux);
	}
	return l;
}
