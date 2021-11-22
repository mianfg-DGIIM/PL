# .SUFFIXES:
#
# prueba: main.o y.tab.o
# 	gcc -o prueba main.o y.tab.o
#
# main.o: main.c
# 	gcc -c -o main.o main.c -I.
#
# y.tab.o: y.tab.c
# 	gcc -o y.tab.o y.tab.c -lfl -I.
#
# y.tab.c: tokens.l lex.yy.c
# 	bison -v -d -o y.tab.c gramatica.y
#
# lex.yy.c: tokens.l
# 	flex -o lex.yy.c tokens.l
#
# limpia:
# 	rm -f prueba main.o y.tab.o y.tab.c lex.yy.c
#
# todo:
# 	make limpia
# 	make prueba

compiler: lex.yy.o gramatica.tab.o
	gcc -o compiler $^

gramatica.tab.h: gramatica.y
	bison --debug --verbose -d gramatica.y

gramatica.tab.c: gramatica.y
	bison -d gramatica.y

lex.yy.c: tokens.l gramatica.tab.h
	flex tokens.l
