%{ 
#include<stdio.h> 
#include<string.h> 
int i = 0; 
enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _COMENTARIO };
%} 

WS	[ \t\n]
 

%%
    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{WS}	{ /* ignora espaços, tabs e '\n' */ } 

"if"																	{ return _IF; }
"for"																	{ return _FOR; }
([a-z]|[A-Z]|_)+([a-z]|[A-Z]|[0-9]|_)*									{ return _ID; }
(([0-9])+\.([0-9])+((e|E)[+|-]?([0-9])+)?|([0-9])+(e|E)[+|-]?([0-9])+)	{ return _FLOAT; }
([0-9])+																{ return _INT; }
">="																	{ return _MAIG; }
"<="																	{ return _MEIG; }
"==" 																	{ return _IG; }
"!="																	{ return _DIF; }
"\""([a-z]|[0-9]|[A-Z]|" "|"\\\""|\"\")+"\"" 							{ return _STRING; }
"/*"([^*]|\*+[^*/])*\*"/"												{ return _COMENTARIO; }

.       { return *yytext; }

%%

int yywrap(void){} 

int main() 
{ 
	int tok = yylex();
	// The function that starts the analysis
	while(tok != EOF)  {
		printf("%d\n", tok); 
		tok = yylex();
	}

	return 0; 
} 
