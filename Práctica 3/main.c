#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
int yyparse(void);

FILE *abrir_entrada(int argc, char *argv[]) {
  FILE *f = NULL;

  if (argc > 1) {
    f = fopen(argv[1], "r");
    if (f == NULL) {
      printf ("\nNo se ha podido abrir el fichero %s\n", argv[1]);
      exit (1);
    } else {
      printf ("\nLeyendo fichero '%s'\n", argv[1]);
    }
  } else {
    printf("Leyendo entrada estándar\n");
  }

  return f;
}

int main(int argc, char *argv[]) {
  yyin = abrir_entrada(argc, argv);
  return yyparse();
}
