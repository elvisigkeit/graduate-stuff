all: main
	./main

main: codigo.cc
	g++ -std=c++17 main.cc codigo.cc -o main 

codigo.cc: compilador entrada.txt
	./compilador < entrada.txt > codigo.cc

lex.yy.c: gera_listas.l
	flex gera_listas.l

y.tab.c: gera_listas.y
	yacc gera_listas.y

compilador: lex.yy.c y.tab.c
	g++ y.tab.c -std=c++11 -Wall -Wno-unused -Wno-deprecated -Wno-write-strings -o compilador

clean:
	rm main y.tab.c lex.yy.c compilador codigo.cc