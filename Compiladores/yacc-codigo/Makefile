all: main
	./main

main: codigo.cc
	g++ -std=c++17 -fpermissive codigo.cc -o main 

codigo.cc: compilador entrada.txt
	./compilador < entrada.txt > codigo.cc
	./gabarito < codigo.cc

lex.yy.c: gera_cod.l
	flex gera_cod.l

y.tab.c: gera_cod.y
	yacc --debug --verbose gera_cod.y

compilador: lex.yy.c y.tab.c
	g++ y.tab.c -std=c++11 -Wall -Wno-unused -Wno-deprecated -Wno-write-strings -o compilador

gab-lex.yy.c: gab.l
	flex gab.l

gab-y.tab.c: gab.y
	yacc gab.y

gab: gab-lex.yy.c gab-y.tab.c
	g++ y.tab.c -std=c++11 -Wall -Wno-unused -Wno-deprecated -Wno-write-strings -o gabarito

clean:
	rm main y.tab.c lex.yy.c compilador codigo.cc