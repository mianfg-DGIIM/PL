#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"

extern FILE *yyin;
int yyparse(void);

FILE *abrir_entrada(int argc, char *argv[]) {
	FILE *f = NULL;

	if (argc > 1) 	{
		f = fopen(argv[1], "r");
		if (f==NULL) 		{
			fprintf(stderr, "No se ha reconocido el fichero de entrada\n");
			exit(1);
		} else
			printf("\nLeyendo fichero...\n\n");
	} else
		printf("\nLeyendo entrada estandar.\n\n");
	return f;
}

/*******************************************************************************/

int main(int argc, char *argv[1]) {
	yyin = abrir_entrada(argc, argv);
	return yyparse();
}