# .SUFFIXES:
#
# prueba: main.o gramatica.tab.o
# 	gcc -o prueba main.o gramatica.tab.o
#
# main.o: main.c
# 	gcc -c -o main.o main.c -I.
#
# gramatica.tab.o: gramatica.tab.c
# 	gcc -o gramatica.tab.o gramatica.tab.c
#
# gramatica.tab.c: tokens.l lex.yy.c
# 	bison -v -d -o gramatica.tab.c gramatica.y
#
# lex.yy.c: tokens.l
# 	flex tokens.l
#
# limpia:
# 	rm -f prueba main.o gramatica.tab.o gramatica.tab.c lex.yy.c
#
# todo:
# 	make limpia
# 	make prueba

# compiler: lex.yy.o gramatica.tab.o
# 	gcc -o compiler $^
#
# gramatica.tab.h: gramatica.y
# 	bison --debug --verbose -d gramatica.y
#
# gramatica.tab.c: gramatica.y
# 	bison -d gramatica.y
#
# lex.yy.c: tokens.l gramatica.tab.h
# 	flex tokens.l


all: gramatica

gramatica.tab.c gramatica.tab.h: gramatica.y
	bison -d gramatica.y

lex.yy.c: tokens.l gramatica.tab.h
	flex tokens.l

gramatica: lex.yy.c gramatica.tab.c gramatica.tab.h
	gcc -o gramatica gramatica.tab.c lex.yy.c

clean:
	rm gramatica gramatica.tab.c lex.yy.c gramatica.tab.h