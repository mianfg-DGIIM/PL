OBJ = obj
SRC = src
BIN = bin

practica3: $(OBJ)/main.o $(OBJ)/gramatica.tab.o
	gcc -o $(BIN)/practica3 $(OBJ)/main.o $(OBJ)/gramatica.tab.o

$(OBJ)/main.o: $(SRC)/main.c
	gcc -o $@ -c $(SRC)/main.c

$(OBJ)/gramatica.tab.o: $(SRC)/gramatica.tab.c
	gcc -o $@ -c $(SRC)/gramatica.tab.c

$(SRC)/gramatica.tab.c: $(SRC)/gramatica.y $(SRC)/lex.yy.c
	bison -v -d -o $@ $(SRC)/gramatica.y

$(SRC)/lex.yy.c: $(SRC)/tokens.l
	flex $(SRC)/tokens.l
	mv lex.yy.c $(SRC)

all:
	make practica3

clean:
	rm -rf $(BIN)/practica3 $(OBJ)/* $(SRC)/gramatica.tab.c $(SRC)/lex.yy.c
	rm -rf $(BIN)/practica3.exe