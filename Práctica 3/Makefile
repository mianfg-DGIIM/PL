.SUFFIXES:

lex: main.o y.tab.o
	gcc -o lex main.o y.tab.o

y.tab.o: y.tab.c
	gcc -c y.tab.c

main.o: main.c
	gcc -c main.c

y.tab.c: gramatica.y lex.yy.c
	bison -o y.tab.c gramatica.y

lex.yy.c: lex.l
	flex lex.l

clean:
	rm -f lex main.o y.tab.o y.tab.c lex.yy.c

all:
	make clean
	make lex