OBJ = obj
SRC = src
BIN = bin
INCLUDE = include

practica4: $(OBJ)/semantic.o $(OBJ)/main.o $(OBJ)/gramatica.tab.o
	gcc -o $(BIN)/practica5 $(OBJ)/semantic.o $(OBJ)/main.o $(OBJ)/gramatica.tab.o

$(OBJ)/main.o: $(SRC)/main.c
	gcc -o $@ -c $(SRC)/main.c -I$(INCLUDE)

$(OBJ)/gramatica.tab.o: $(SRC)/gramatica.tab.c
	gcc -o $@ -c $(SRC)/gramatica.tab.c -I$(INCLUDE)

$(SRC)/gramatica.tab.c: $(SRC)/gramatica.y $(SRC)/lex.yy.c
	bison -v -d -o $@ $(SRC)/gramatica.y

$(SRC)/lex.yy.c: $(SRC)/tokens.l
	flex $(SRC)/tokens.l
	mv lex.yy.c $(SRC)

$(OBJ)/semantic.o: $(SRC)/semantic.c
	gcc -o $@ -c $(SRC)/semantic.c -I$(INCLUDE)

all:
	make practica5

clean:
	rm -rf $(BIN)/practica5 $(OBJ)/* $(SRC)/gramatica.tab.c $(SRC)/lex.yy.c
	rm -rf $(BIN)/practica5.exe