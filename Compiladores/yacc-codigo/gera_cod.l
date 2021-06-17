%{
int token( int );
%}

DIGITO  [0-9]
LETRA   [A-Za-z_]
INT     {DIGITO}+
DOUBLE  {DIGITO}+("."{DIGITO}+)?
CMP     ("<"|">"|"<="|">="|"=="|"<>")
ID      {LETRA}({LETRA}|{DIGITO})*
STR     (\"([^"]|\\\")*\")
VAR     ("int"|"char"|"string"|"boolean"|"real")
CHAR    \'.\'

%option noyywrap

%%

"\t"       { coluna += 4; }
" "        { coluna++; }
"\n"	     { linha++; coluna = 1; }
{CHAR}     { return token( CCHAR ); }
{INT} 	   { return token( CINT ); }
{DOUBLE}   { return token( CDOUBLE ); }
{STR}      { return token( TK_STR ); }
{CMP}      { return token( TK_CMP ); }
"not"      { return token( TK_UN_NOT ); }
"and"      { return token( TK_CMP_AND ); }
"or"       { return token( TK_CMP_OR ); }
{VAR}	     { return token( TK_VAR ); }
"console"  { return token( TK_CONSOLE ); }
">>"       { return token( TK_SHIFTR ); }
"<<"       { return token( TK_SHIFTL ); }
"for"      { return token( TK_FOR ); }
"in"       { return token( TK_IN ); }
".."       { return token( TK_2PT ); }
"if"       { return token( TK_IF ); }
"then"     { return token( TK_THEN ); }
"else"     { return token( TK_ELSE ); }
"endl"     { return token( TK_ENDL ); }
"end"      { return token( TK_END ); }
"begin"    { return token( TK_BEGIN ); }
"true"     { return token( TK_TRUE ); }
"false"    { return token( TK_FALSE ); }
{ID}       { return token( TK_ID ); }
.          { return token( *yytext ); }

%%

int token( int tk ) {
  yylval.v = yytext;
  coluna += strlen(yytext);
  yylval.linha = linha;
  yylval.c = "";
  return tk;
}

