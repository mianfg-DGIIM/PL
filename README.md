# DGIIM-PL
## Prácticas de PL

<br/>

### Pasos para compilar y ejecutar el programa (Windows working):  
```
flex lex.l 
gcc lex.yy.c 
a.exe prueba.txt
```

> Si se quiere guardar la salida en un fichero de texto:
```
a.exe prueba.txt > salida.txt
```

### Pasos para compilar y ejecutar la práctica 3 (Windows working): 

Eliminamos ficheros temporales:
```
make clean
```
Y generamos el programa correspondiente a la práctica 3:
```
make 
```
En la carpeta /bin tendremos generado el ejecutable `practica3` que acepta como argumento un fichero de entrada para realizar su análisis sintáctico con YACC.

Para ejecutarlo:

```
./practica3 fichero_entrada.txt
```