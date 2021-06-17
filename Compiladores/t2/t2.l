%{ 
#include<stdio.h> 
#include<string.h> 
char fim;
char retorno[300];
char variavel[100];
enum TOKEN { _ID = 256, _PAR_INI, _PAR_FIM, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _COMENTARIO, _ATRB, _SOMA, _SUBT, _MULT, _DIVI, _FIM };
%} 

WS	[ \t\n]
 
%%

{WS}	{ /* ignora espaços, tabs e '\n' */ } 

";"																					  					                { snprintf(variavel, 100, "%s", yytext); return _FIM; }  
"if"																										                { snprintf(variavel, 100, "%s", yytext); return _IF; }
"for"					 												                                  { snprintf(variavel, 100, "%s", yytext); return _FOR; }
\(					 												                                    { snprintf(variavel, 100, "%s", yytext); return _PAR_INI; }
\)					 												                                    { snprintf(variavel, 100, "%s", yytext); return _PAR_FIM; }
"+"						  											                                  { snprintf(variavel, 100, "%s", yytext); return _SOMA; }
"-"							  										                                  { snprintf(variavel, 100, "%s", yytext); return _SUBT; }
"*"							  										                                  { snprintf(variavel, 100, "%s", yytext); return _MULT; }
"/"											   						                                  { snprintf(variavel, 100, "%s", yytext); return _DIVI; }
">="																										                { snprintf(variavel, 100, "%s", yytext); return _MAIG; }
"<="																										                { snprintf(variavel, 100, "%s", yytext); return _MEIG; }
"==" 																										                { snprintf(variavel, 100, "%s", yytext); return _IG; }
"!="																										                { snprintf(variavel, 100, "%s", yytext); return _DIF; }
"="																										                  { snprintf(variavel, 100, "%s", yytext); return _ATRB; }
([a-z]|[A-Z]|_)+([a-z]|[A-Z]|[0-9]|_)*									                { snprintf(variavel, 100, "%s", yytext); return _ID; }
(([0-9])+\.([0-9])+((e|E)[+|-]?([0-9])+)?|([0-9])+(e|E)[+|-]?([0-9])+)	{ snprintf(variavel, 100, "%s", yytext); return _FLOAT; }
([0-9])+																									              { snprintf(variavel, 100, "%s", yytext); return _INT; }
"\""([a-z]|[0-9]|[A-Z]|" "|","|"!"|"\\\""|\"\")+"\"" 		              	{ snprintf(variavel, 100, "%s", yytext); return _STRING; }
"/*"([^*]|\*+[^*/])*\*"/"												                        { snprintf(variavel, 100, "%s", yytext); return _COMENTARIO; }

.       { return *yytext; }

%%
int parse_token(int tok, int dir);
int yywrap(void){}

void one_step_parse() {
  int tok = yylex();
  int dir = 1;
  switch(tok){
    case _PAR_FIM:
    case _FIM:
      return;
    case _PAR_INI:
      parse_token(yylex(), dir);
    break;
    case _ID:
      printf("%s", variavel);
      if(dir)
        printf(" @");
      printf(" ");
    break;
    case _STRING:
    case _INT:
    case _FLOAT:
      printf("%s ", variavel);
    break;
    case _ATRB:
      printf("=\n");
    break;
  }
} 

int parse_token(int tok, int dir){
  if(!tok)
    return 0;
  switch(tok){
    case _PAR_FIM:
    case _FIM:
      return 1;
    case _PAR_INI:
      parse_token(yylex(), dir);
      parse_token(yylex(), dir);
    break;
    case _ID:
      // Caso onde o id é um print
      if(!strncmp(variavel, "print", 100)){
        parse_token(yylex(), dir);
        printf("@ ");
      } else {
        printf("%s", variavel);
        if(dir)
          printf(" @");
        printf(" ");
        parse_token(yylex(), dir);
      }
    break;
    case _STRING:
    case _INT:
    case _FLOAT:
      printf("%s ", variavel);
      parse_token(yylex(), dir);
    break;
    case _ATRB:
      parse_token(yylex(), 1);
      printf("=\n");
    break;
    case _SOMA:
      parse_token(yylex(), dir);
      printf("+ ");
    break;
    case _SUBT:
      parse_token(yylex(), dir);
      printf("- ");
    break;
    case _MULT:
      one_step_parse(); 
      printf("* ");
      parse_token(yylex(), dir);
    break;
    case _DIVI:
      one_step_parse();
      printf("/ ");
      parse_token(yylex(), dir);
    break;
  }
}

int main() 
{ 
	while(parse_token(yylex(), 0));
	return 0; 
} 
