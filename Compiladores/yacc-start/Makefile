all: saida entrada.txt
	./saida < entrada

saida: lex.yy.c y.tab.c
	g++ y.tab.c -o saida 
	
lex.yy.c: npr.l
	lex npr.l
	
y.tab.c: npr.y
	yacc npr.y
	
clean: 
	rm -f lex.yy.c y.tab.c saida
