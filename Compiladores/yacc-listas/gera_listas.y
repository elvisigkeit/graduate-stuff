%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define YYSTYPE Atributos

using namespace std;

int linha = 1;
int coluna = 1;
int numero_de_nos = 0;

struct Atributos {
  string head;
  string codigo;
};

struct Lista {
  bool sublista; 
  string valorString;
  Lista* valorSublista;
  Lista* proximo;  
};

int yylex();
int yyparse();
void yyerror(const char *);
%}

%start S
%token ATOMO 

%%

S: ITEM  { 
        cout << "#include <string>\n\nusing namespace std;\n\nstruct Lista {\n  bool sublista;\n  string valorString;\n  Lista* valorSublista;\n  Lista* proximo;\n};\n\nLista* geraLista() {\n";
        for( int i = 0; i < numero_de_nos; i++ )
          cout << "\tLista* " << "l" << i << " = new Lista();\n";
        cout << "\n" + $1.codigo << endl; 
        cout << "\treturn " << $$.head << ";\n}\n" << endl;
      }
 ;
  
/* L : '(' LE ')' { $$ = $2; }
 | '(' ')'    { $$.head = "nullptr"; $$.codigo = ""; }
 ; 
*/

ITEM: E ',' ITEM
      {
        $$.codigo = $1.codigo 
                  + $1.head + "->proximo = " + $3.head + ";\n\n"
                  + $3.codigo;
        $$.head = $1.head;
      }
    | E
      { 
        $$.codigo = $1.codigo + $1.head + "->proximo = nullptr;\n"; 
        $$.head = $1.head; 
      }
    ;
  
E: ATOMO 
    { 
	    string nome_no = "\tl" + to_string( numero_de_nos );
	     
	    $$.head = nome_no;
      $$.codigo = nome_no + "->sublista = false;\n"
                + nome_no + "->valorString = \"" + $1.head + "\";\n"
                + nome_no + "->valorSublista = nullptr;\n";
      numero_de_nos++; 
    }
  | '(' ')'
    {
      string nome_no = "\tl" + to_string( numero_de_nos );
      
      $$.head = nome_no;
      $$.codigo = nome_no + "->sublista = true;\n"
                + nome_no + "->valorSublista = nullptr;\n";
      numero_de_nos++; 
    }
  | '(' ITEM ')'
    {
      string nome_no = "\tl" + to_string( numero_de_nos );
      
      $$.head = nome_no;
      $$.codigo = $2.codigo
                + nome_no + "->sublista = true;\n"
                + nome_no + "->valorSublista = " + $2.head + ";\n";
      numero_de_nos++; 
    }
 ;  
%%

#include "lex.yy.c"

int main( int argc, char* argv[] ) {
  yyparse();
}

void yyerror( const char* st ) {
  puts( st ); 
  cout << "Linha " << linha 
       << " , coluna " << coluna - yyleng 
       << ", proximo a: " << yytext<< endl;
        
  exit( 0 );
}