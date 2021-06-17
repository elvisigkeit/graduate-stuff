%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;

#define YYSTYPE Atributos

int linha = 1;
int coluna = 1;

typedef string Tipo;

struct Atributos {
  string v;
  string c;
  unsigned d1, d2, d3;
  Tipo t;
  int linha;
};

struct DimV {
  string nome;
  unsigned nDim;
  Tipo tipo;
  unsigned d1, d2, d3;
};

map<string,Tipo> tsVar = {
{"int","int"}, {"char","char"}, {"string","string"},
{"boolean","int"}, {"real", "double"},
{"I","int "}, {"C","char "}, 
{"D", "double "}, {"S", "string "}
};
map<string,Tipo> untsVar = {
{"int","I"}, {"char","C"}, {"string","S"},
{"boolean","C"}, {"real", "D"},
};
map<string,Tipo> tsLeitura = {
{"I","int"}, {"C","char"}, 
{"D", "real"}, {"S", "string"}
};
map<string,Tipo> resOpr = {
{ "+II", "I" }, { "+ID", "D" }, { "+DI", "D" }, { "+DD", "D" },
{ "+CC", "C" }, { "+CS", "S" }, { "+SC", "S" }, { "+SS", "S" },
{ "+CI", "I" }, { "+IC", "I" }, 

{ "-II", "I" }, { "-ID", "D" }, { "-DI", "D" }, { "-DD", "D" },
{ "-CC", "C" }, { "-CI", "I" }, { "-IC", "I" }, 

{ "/II", "I" }, { "/ID", "D" }, { "/DI", "D" }, { "/DD", "D" },
{ "/CC", "C" }, { "/CI", "I" }, { "/IC", "I" }, 

{ "*II", "I" }, { "*ID", "D" }, { "*DI", "D" }, { "*DD", "D" },
{ "*CC", "C" }, { "*CI", "I" }, { "*IC", "I" }, 

{ "%II", "I" }, { "%ID", "D" }, { "%DI", "D" }, { "%DD", "D" },
{ "%CC", "C" }, { "%CI", "I" }, { "%IC", "I" },

{ ">II", "I" }, { ">ID", "I" }, { ">DI", "I" }, { ">DD", "I" },
{ ">CC", "I" }, { ">CI", "I" }, { ">IC", "I" }, { ">SS", "I" }, 
{ ">SC", "I" }, { ">CS", "I" },

{ ">=II", "I" }, { ">=ID", "I" }, { ">=DI", "I" }, { ">=DD", "I" },
{ ">=CC", "I" }, { ">=CI", "I" }, { ">=IC", "I" }, { ">=SS", "I" },
{ ">=SC", "I" }, { ">=CS", "I" },

{ "<II", "I" }, { "<ID", "I" }, { "<DI", "I" }, { "<DD", "I" },
{ "<CC", "I" }, { "<CI", "I" }, { "<IC", "I" }, { "<SS", "I" },
{ "<SC", "I" }, { "<CS", "I" },

{ "<=II", "I" }, { "<=ID", "I" }, { "<=DI", "I" }, { "<=DD", "I" },
{ "<=CC", "I" }, { "<=CI", "I" }, { "<=IC", "I" }, { "<=SS", "I" },
{ "<=SC", "I" }, { "<=CS", "I" },

{ "==II", "I" }, { "==ID", "I" }, { "==DI", "I" }, { "==DD", "I" },
{ "==CC", "I" }, { "==CI", "I" }, { "==IC", "I" }, { "==SS", "I" },
{ "==SC", "I" }, { "==CS", "I" },

{ "!=II", "I" }, { "!=ID", "I" }, { "!=DI", "I" }, { "!=DD", "I" },
{ "!=CC", "I" }, { "!=CI", "I" }, { "!=IC", "I" }, { "!=SS", "I" },
{ "!=SC", "I" }, { "!=CS", "I" }
};


int yylex();
int yyparse();
string declTemps();
void yyerror(const char *);

Atributos geraAtribuicao(Atributos id, Atributos var);
string geraNomeVar(Tipo t);
string geraLFim();
string geraLInicio();
string geraLMeio();
string declaraVariavel(string tipo, string vars);
Atributos geraCodigoOperador( Atributos a, string operador, Atributos b );
Atributos geraCodigoComparacao( Atributos a, string operador, Atributos b );
string pegaTipo(string nome);
string pegaTipoVetor(string nome);
string registraDimensoes(string nome, unsigned nDim, unsigned d1, unsigned d2, unsigned d3);
string gera_indice_vetor(Atributos recebido, Tipo tipo_direita, unsigned nrDim, unsigned d1, unsigned d2, unsigned d3);

map<Tipo,int> nVar;
map<string,Tipo> tabelaVars;
map<string,DimV> tabelaVetores;
string ultimoCondIf;
int lMeio = 0;
int lInicio = 0;
int lFim = 0;

%}

%start S
%token CINT CDOUBLE TK_ID TK_VAR TK_CONSOLE TK_SHIFTR TK_SHIFTL TK_TRUE TK_FALSE
%token TK_FOR TK_IN TK_2PT TK_IF TK_THEN TK_ELSE TK_STR TK_ENDL CCHAR
%token TK_CMP TK_CMP_OR TK_CMP_AND TK_UN_NOT TK_END TK_BEGIN TK_OPER

%left TK_CMP_AND TK_CMP_OR TK_UN_NOT
%left TK_CMP
%left '+' '-' 
%left '*' '/' '%'

%%

S: CMDS
    { cout << "#include <string>\n#include <cstring>\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n"
           << declTemps()
           << $1.c
           << "fflush(stdout);\nreturn 0;\n}" << endl; 
    }
 ;  

CMDS: CMDS CMD ';' { $$.c = $1.c + $2.c; }
    | CMD ';' 
    ;
  
CMD: DECLVAR 
   | ENTRADA
   | SAIDA
   | ATR
   | FOR
   | IF
   ;
    
DECLVAR: TK_VAR VARS 
       { $$.c = declaraVariavel($1.v, $2.c); }
       ;
    
VARS: VARS ',' VAR  { $$.c = $1.c + "," + $3.c; }
    | VAR
    ;
     
VAR: TK_ID '[' CINT ']'  
     { registraDimensoes($1.v, 1, stoul($3.v), 0, 0); 
       $$.c = $1.v + "[" + $3.v + "]";  }
   | TK_ID '[' CINT ']' '[' CINT ']'  
     { string largura = registraDimensoes($1.v, 2, stoul($3.v), stoul($6.v), 0); 
       $$.c = $1.v + "[" + largura + "]";  }
   | TK_ID '[' CINT ']' '[' CINT ']' '[' CINT ']'  
     { string largura = registraDimensoes($1.v, 3, stoul($3.v), stoul($6.v), stoul($9.v)); 
       $$.c = $1.v + "[" + largura + "]"; }
   | TK_ID                
     { $$.c = $1.v; }
   ;
    
ENTRADA: TK_CONSOLE ENTRADA_EXT
         { $$.c = $2.c; }
       ;

ENTRADA_EXT: TK_SHIFTR TK_ID
             { $$.c = "cin >> " + $2.v + ";\n"; }
           | TK_SHIFTR TK_ID '[' E ']'
             { $$.v = geraNomeVar(pegaTipoVetor($2.v));
               $$.c = $4.c 
                    + "cin >> " + $$.v + ";\n"
                    + $2.v + "[" + $4.v + "] = " + $$.v + ";\n"; } 
           | TK_SHIFTR TK_ID '[' E ']' '[' E ']'
             { $$.v = geraNomeVar(pegaTipoVetor($2.v));
               string indice = gera_indice_vetor($2, $2.t, 2, stoul($4.v), stoul($7.v), 0);
               $$.c = $4.c + $7.c 
                     + "cin >> " + $$.v + ";\n"
                     + $2.v + "[" + indice + "] = " + $$.v + ";\n";
             }
           | TK_SHIFTR TK_ID '[' E ']' '[' E ']' '[' E ']'
             { $$.v = geraNomeVar(pegaTipoVetor($2.v));
               string indice = gera_indice_vetor($2, $2.t, 3, stoul($4.v), stoul($7.v), stoul($10.v));
               $$.c = $4.c + $7.c + $10.c
                     + "cin >> " + $$.v + ";\n"
                     + $2.v + "[" + indice + "] = " + $$.v + ";\n";
            }
           | TK_SHIFTR TK_ID ENTRADA_EXT
             { $$.c = "cin >> " + $2.v + ";\n" + $3.c; }
           | TK_SHIFTR TK_ID '[' E ']' ENTRADA_EXT
             { $$.v = geraNomeVar(pegaTipoVetor($2.v));
               $$.c = $4.c 
                    + "cin >> " + $$.v + ";\n"
                    + $2.v + "[" + $4.v + "] = " + $$.v + ";\n"
                    + $6.c; }
           | TK_SHIFTR TK_ID '[' E ']' '[' E ']' ENTRADA_EXT
             { $$.v = geraNomeVar(pegaTipoVetor($2.v));
               string indice = gera_indice_vetor($2, $2.t, 2, stoul($4.v), stoul($7.v), 0);
               $$.c = $4.c + $7.c 
                     + "cin >> " + $$.v + ";\n"
                     + $2.v + "[" + indice + "] = " + $$.v + ";\n"
                     + $9.c;
             }
           | TK_SHIFTR TK_ID '[' E ']' '[' E ']' '[' E ']' ENTRADA_EXT
             { $$.v = geraNomeVar(pegaTipoVetor($2.v));
               string indice = gera_indice_vetor($2, $2.t, 3, stoul($4.v), stoul($7.v), stoul($10.v));
               $$.c = $4.c + $7.c + $10.c
                     + "cin >> " + $$.v + ";\n"
                     + $2.v + "[" + indice + "] = " + $$.v + ";\n"
                     + $12.c;
            }
           ;

SAIDA: TK_CONSOLE SAIDA_EXT
       { $$.c = $2.c; }
     ;

SAIDA_EXT: TK_SHIFTL TK_STR
           { $$.c = "cout << " + $2.v + ";\n"; }
         | TK_SHIFTL E
           { $$.c = $2.c + "cout << " + $2.v + ";\n"; }
         | TK_SHIFTL TK_ENDL
           { $$.c = "cout << " + $2.v + ";\n"; }
         | TK_SHIFTL TK_STR SAIDA_EXT
           { $$.c = "cout << " + $2.v + ";\n" + $3.c; }
         | TK_SHIFTL E SAIDA_EXT
           { $$.c = $2.c + "cout << " + $2.v + ";\n" + $3.c; }
         | TK_SHIFTL TK_ENDL SAIDA_EXT
           { $$.c = "cout << " + $2.v + ";\n" + $3.c; }
         ;
       
FOR: TK_FOR TK_ID TK_IN '[' E TK_2PT E ']' BLK  
    {  string cond = geraNomeVar("I");
        string inicio = geraLInicio();
        string fim = geraLFim();
        
        $$.c = $5.c + $7.c 
            + $2.v + " = " + $5.v + ";\n"
            + inicio + ":\n" + cond + " = " + $2.v + " > " + $7.v + ";\n"
            + "if( " + cond + " ) goto " + fim + ";\n"
            + $9.c
            + $2.v + " = " + $2.v + " + 1;\n"
            + "goto " + inicio + ";\n"
            + fim + ":\n";
    }      
   | TK_FOR TK_ID TK_IN '[' E TK_2PT E ']' CMD  
    {  string cond = geraNomeVar("I");
        string inicio = geraLInicio();
        string fim = geraLFim();
        
        $$.c = $5.c + $7.c 
            + $2.v + " = " + $5.v + ";\n"
            + inicio + ":\n" + cond + " = " + $2.v + " > " + $7.v + ";\n"
            + "if( " + cond + " ) goto " + fim + ";\n"
            + $9.c
            + $2.v + " = " + $2.v + " + 1;\n"
            + "goto " + inicio + ";\n"
            + fim + ":\n";
    }        
   ;
   
IF: TK_ELSE BLK
    { 
      string cond = geraNomeVar("I"); string meio = geraLMeio(); string fim = geraLFim();
      $$.c = cond + " = !" + ultimoCondIf + ";\n"
           + "if( " + cond + " ) \n\tgoto " + meio + ";\n"
           + "\tgoto " + fim + ";\n" + meio + ":\n"
           + $2.c + "\n" + fim + ":\n";
    }
  | TK_ELSE CMD
    { string cond = geraNomeVar("I"); string meio = geraLMeio(); string fim = geraLFim();
      ultimoCondIf = cond;
      $$.c = "if( " + cond + " ) \n\tgoto " + meio + ";\n"
           + "\tgoto " + fim + ";\n" + meio + ":\n"
           + $2.c + "\n" + fim + ":\n";}
  | TK_IF E TK_THEN BLK ';' error
  | TK_IF E TK_THEN CMD
    { string cond = geraNomeVar("I"); ultimoCondIf = cond;
      string fim = geraLFim(); string inicio = geraLInicio();
      $$.c = $2.c
           + cond + " = " + $2.v + ";\n"
           + "if( " + cond + " ) \n\tgoto " + inicio + ";\n"
           + "\tgoto " + fim + ";\n" + inicio + ":\n"
           + $4.c + "\n" 
           + fim + ":\n"
           + ultimoCondIf + " = !" + cond + ";\n"; }
  | TK_IF E TK_THEN BLK TK_ELSE BLK
    { string cond = geraNomeVar("I"); string meio = geraLMeio(); string fim = geraLFim();
      $$.c = $2.c
           + cond + " = " + $2.v + ";\n"
           + "if( " + cond + " ) \n\tgoto " + meio + ";\n"
           + $6.c + "\n\tgoto " + fim + ";\n" + meio + ":\n"
           + $4.c + "\n" + fim + ":\n"; }
  ;

BLK: TK_BEGIN CMDS TK_END
     { $$.c = $2.c; }
   | TK_BEGIN TK_END
     { $$.c = " "; }
   ;
  
ATR: TK_ID '=' E
     { $$ = geraAtribuicao($1, $3); }
   | TK_ID '[' E ']' '=' E
     { $$.c = $3.c + $6.c 
            + $1.v + "[" + $3.v + "] = " + $6.v + ";\n";
       $$.v = $6.v;
     }
   | TK_ID '[' E ']' '[' E ']' '=' E
     { string indice = gera_indice_vetor($1, $9.t, 2, stoul($3.v), stoul($6.v), 0);
       $$.c = $3.c + $6.c + $9.c
            + $1.v + "[" + indice + "] = " + $6.v + ";\n";
       $$.v = $6.v;
     }
   | TK_ID '[' E ']' '[' E ']' '[' E ']' '=' E
     { string indice = gera_indice_vetor($1, $12.t, 3, stoul($3.v), stoul($6.v), stoul($9.v));
       $$.c = $3.c + $6.c + $9.c + $12.c
            + $1.v + "[" + indice + "] = " + $6.v + ";\n";
       $$.v = $6.v;
     }
   ;
  
E: E '+' E
  { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
 | E '-' E
   { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
 | E '*' E
   { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
 | E '/' E
   { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
 | E '%' E
   { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
 | TK_UN_NOT E
   { 
     $$.v = geraNomeVar("I");
     $$.c = $2.c + $$.v + " = " + "!" + $2.v + ";\n";
   }
 | E TK_CMP E
   { $$ = geraCodigoComparacao( $1, $2.v, $3 ); }
 | E TK_CMP_AND E
   { 
     $$.v = geraNomeVar("I");
     $$.c = $1.c + $3.c + $$.v + " = " + $1.v + " && " + $3.v + ";\n"; 
   }
 | E TK_CMP_OR E
   { 
     $$.v = geraNomeVar("I");
     $$.c = $1.c + $3.c + $$.v + " = " + $1.v + " || " + $3.v + ";\n";
   }
 | V
 ;

V: TK_ID '[' E ']' 
             { 
               $$.v = geraNomeVar($1.t);
               $$.c = $3.c + $$.v + " = " + $1.v + "[" + $3.v + "];\n";    
               $$.t = pegaTipoVetor($1.v);                
             }
 | TK_ID '[' E ']' '[' E ']' 
             { $$.v = geraNomeVar($2.t);
               string indice = gera_indice_vetor($1, $1.t, 2, stoul($3.v), stoul($6.v), 0);
               $$.c = $3.c + $$.v + $6.c 
                     + $1.v + "[" + indice + "] = " + $$.v + ";\n";
               $$.t = pegaTipoVetor($1.v);
            }
 | TK_ID '[' E ']' '[' E ']' '[' E ']' 
             { $$.v = geraNomeVar($2.t);
               string indice = gera_indice_vetor($1, $1.t, 3, stoul($3.v), stoul($6.v), stoul($9.v));
               $$.c = $3.c + $$.v + $6.c + $9.c
                     + $1.v + "[" + indice + "] = " + $$.v + ";\n";
               $$.t = pegaTipoVetor($1.v);
            }
 | TK_ID     { $$.c = ""; $$.v = $1.v; $$.t = pegaTipo($1.v); }
 | CINT      { $$.c = ""; $$.v = $1.v; $$.t = "I"; } 
 | CDOUBLE   { $$.c = ""; $$.v = $1.v; $$.t = "D"; } 
 | CCHAR     {
               $$.v = geraNomeVar("C"); 
               $$.c = $$.v + " = " + $1.v + ";\n";
               $$.t = "C"; 
             } 
 | TK_STR    { $$.c = ""; $$.v = $1.v; $$.t = "S"; }  
 | TK_TRUE   { $$.c = ""; $$.v = "1"; $$.t = "I"; }
 | TK_FALSE  { $$.c = ""; $$.v = "0"; $$.t = "I"; }
 | '(' E ')' { $$ = $2; }
 ;

%%

#include "lex.yy.c"

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Linha %d, coluna %d, proximo a: %s\n", linha, coluna, yytext );
   exit( 0 );
}

string geraLInicio() {
  char buf[20] = "";
  
  sprintf( buf, "inicio%d", lInicio++ );
  
  return buf;
}

string geraLMeio() {
  char buf[20] = "";
  
  sprintf( buf, "meio%d", lMeio++ );
  
  return buf;
}

string geraLFim() {
  char buf[20] = "";
  
  sprintf( buf, "fim%d", lFim++ );
  
  return buf;
}

string toString( int n ) {
  char buf[20] = "";
  
  sprintf( buf, "%d", n );
  
  return buf;
}

string geraNomeVar( Tipo t ) {
  return "t_" + t + "_" + toString( nVar[t]++ );
}

Tipo buscaTipoOperacao( Tipo a, string operador, Tipo b ) {
  return resOpr[operador + a + b];
}

Atributos geraCodigoComparacao(Atributos a, string operador, Atributos b) {
  Atributos r;
  if(operador == "<>")
    operador = "!=";
  
  r.t = buscaTipoOperacao( a.t, operador, b.t );
  if( r.t == "" ) {
    string temp = "Operacao '" + operador + "' invalida entre " + tsLeitura[a.t] + " e " + tsLeitura[b.t]; 
    yyerror( temp.c_str() );
  }

  if (a.t == "S" || b.t == "S") {
    r.v = geraNomeVar("I"); string strCmp = geraNomeVar("I");
    r.c = a.c + b.c;
    if(a.t == "C") {
      string var = geraNomeVar("S");
      r.c += var + "[0] = " + a.v + ";\n" + var + "[1] = 0;\n";
      a.v = var;
    }
    if(b.t == "C") {
      string var = geraNomeVar("S");
      r.c += var + "[0] = " + b.v + ";\n" + var + "[1] = 0;\n";
      b.v = var;
    }
    r.c += strCmp + " = strncmp (" + a.v + ", " + b.v + ", 255);\n";
    r.c += r.v + " = " + strCmp + " " + operador + " 0;\n";
    return r;
  }
  r.v = geraNomeVar("I");
  r.c = a.c + b.c + r.v + " = " + a.v + operador + b.v + ";\n"; 
  return r;
}

Atributos geraCodigoOperador( Atributos a, string operador, Atributos b ) {
  Atributos r;
  
  r.t = buscaTipoOperacao( a.t, operador, b.t );
  if( r.t == "" ) {
    string temp = "Operacao '" + operador + "' invalida entre " + tsLeitura[a.t] + " e " + tsLeitura[b.t]; 
    yyerror( temp.c_str() );
  }

  if(r.t == "S" && operador == "+") {
    string lenTemp = geraNomeVar("I");
    r.v = geraNomeVar("S"); string varB = geraNomeVar("S");
    r.c = a.c + b.c;
    r.c += r.v + "[255] = 0;\n";
    r.c += varB + "[255] = 0;\n";
    if(a.t == "C")
      r.c += r.v + "[0] = " + a.v + ";\n" + r.v + "[1] = 0;\n";
    else
      r.c += "strncpy(" + r.v + ", " + a.v + ", 255);\n";
    if(b.t == "C")
      r.c += varB + "[0] = " + b.v + ";\n" + varB + "[1] = 0;\n";
    else
      r.c += "strncpy(" + varB + ", " + b.v + ", 255);\n";
    r.c += lenTemp + " = strlen(" + varB + ");\n";
    r.c += lenTemp + " = 255 - " + lenTemp + ";\n";
    r.c += "strncat(" + r.v + ", " + varB + ", " + lenTemp + ");\n";
    return r;
  }
  
  r.v = geraNomeVar( r.t );
  r.c = a.c + b.c + 
        "  " + r.v + " = " + a.v + operador + b.v + ";\n";
  return r;
}

string pegaTipo(string nome) {
  map<string,Tipo>::iterator it = tabelaVars.find(nome);
  if (it == tabelaVars.end()){
    string temp = "Variavel " + nome + " nao foi definida anteriormente."; 
    yyerror( temp.c_str() );
  }
  return it->second;
}

string pegaTipoVetor(string nome) {
  map<string,DimV>::iterator itv = tabelaVetores.find(nome);
  if (itv == tabelaVetores.end()){
    string temp = "Variavel " + nome + " nao foi definida anteriormente."; 
    yyerror( temp.c_str() );
  }

  DimV vet = itv->second;
  string vet_nome;
  
  if (vet.nDim == 1)
    vet_nome = vet.nome + "[" + to_string(vet.d1) + "]";
  if (vet.nDim == 2)
    vet_nome = vet.nome + "[" + to_string(vet.d1*vet.d2) + "]";
  else 
    vet_nome = vet.nome + "[" + to_string(vet.d1*vet.d2*vet.d3) + "]";

  map<string,Tipo>::iterator it = tabelaVars.find(vet_nome);
  if (it == tabelaVars.end()){
    string temp = "Variavel " + nome + " nao foi definida anteriormente."; 
    yyerror( temp.c_str() );
  }
  return it->second;
}

void registraVariavel(string nome, string tipo){
  tabelaVars[nome] = untsVar[tipo];
}

string registraDimensoes(string nome, unsigned nDim, unsigned d1, unsigned d2, unsigned d3){
  DimV novo; 
  novo.nome = nome;
  novo.nDim = nDim; novo.d1 = d1; novo.d2 = d2; novo.d3 = d3;
  tabelaVetores[nome] = novo;
  if (nDim == 1)
    return to_string(d1);
  if (nDim == 2)
    return to_string(d1*d2);
  return to_string(d1*d2*d3); 
}

Atributos geraAtribuicao(Atributos id, Atributos var) {
  Atributos saida;
  if (var.t == "S") {
    saida.v = var.v;
    saida.c += var.c + id.v + "[255] = 0;\n";
    saida.c += "strncpy(" + id.v + ", " + var.v + ", 255);\n";
    return saida;
  }
  saida.v = var.v;
  saida.c = var.c + id.v + " = " + var.v + ";\n";
  return saida;
}

string gera_indice_vetor(Atributos recebido, Tipo tipo_direita, unsigned nrDim, unsigned d1, unsigned d2, unsigned d3) {
  if(recebido.t != tipo_direita) {
    string temp = "Operacao '=' invalida entre ";
           temp += recebido.t + " e " + tipo_direita; 
    yyerror(temp.c_str());
  }

  map<string,DimV>::iterator it = tabelaVetores.find(recebido.v);
  if (it == tabelaVetores.end()){
    string temp = "Variavel " + recebido.v + " nao foi definida anteriormente."; 
    yyerror( temp.c_str() );
  }
  
  DimV dimensoes = it->second;
  if(dimensoes.nDim != nrDim) {
    string temp = "Número errado de parâmetros: ";
           temp += nrDim + ", deveria ser " + dimensoes.nDim; 
    yyerror(temp.c_str());
  }
  if(dimensoes.nDim == 3)
    return to_string(dimensoes.d1*d1+dimensoes.d2*d2+d3);
  if(dimensoes.nDim == 2)
    return to_string(dimensoes.d1*d1+d2);
  return to_string(d1);  
}

string declaraVariavel(string tipo, string vars) {
  size_t posf;
  string retorno;
  string restante = vars;
  do {
    posf = restante.find(",");

    string nome = restante.substr (0, posf);

    registraVariavel(nome, tipo);

    restante = restante.substr (posf+1);

    if (tipo == "string")
      retorno += "char " + nome + "[257];\n";
  } while (posf != string::npos);
  
  if (tipo == "string")
    return retorno;
  return tsVar[tipo] + " " + vars + ";\n";
}

string declTemps() {
  if (nVar.empty())
    return "";
  string vars;

  for(const auto& varAtual : nVar) {
    string temps;
    if(varAtual.first == "S") {
      for (int i=0; i<varAtual.second; i++) 
        temps += "char t_" + varAtual.first + "_" + to_string(i) + "[257];\n";
    } else {
      temps = tsVar[varAtual.first];
      for(int i=0; i<varAtual.second; i++) {
        temps = temps + "t_" + varAtual.first + "_" + to_string(i);
        if(i+1 != varAtual.second)
          temps+=", ";
      }
      temps += ";\n";
    }
    vars = vars + temps;
  }

  return vars;
}

int main( int argc, char* st[]) {
  yyparse();
  
  return 0;
}