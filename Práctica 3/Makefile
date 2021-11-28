OBJ = obj
SRC = src
BIN = bin

syntactic: $(OBJ)/main.o $(OBJ)/gramatica.tab.o
	@echo ""
	@echo Generando ejecutable...
	@echo ""
	gcc -o $(BIN)/syntactic $(OBJ)/main.o $(OBJ)/gramatica.tab.o
	@echo ""
	@echo Ejecutable generado con éxito
	@echo ""

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
	make syntactic

clean:
	@echo ""
	@echo Limpiando los ficheros...
	@echo ""
	rm -rf $(BIN)/syntactic $(OBJ)/* $(SRC)/gramatica.tab.c $(SRC)/lex.yy.c
	@echo ""
	@echo Limpieza finalizada
	@echo ""