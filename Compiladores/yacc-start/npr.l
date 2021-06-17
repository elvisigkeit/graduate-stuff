D	[0-9]
L	[a-zA-Z_]

/* whitespace: espaco, tab ou \n */
WS	[ \t\n]

STRING	\"(\"\"|\\\"|[^\"])*\"

INT	{D}+
NUM	{INT}("."{INT})?([Ee]("+"|"-")?{INT})?
ID	{L}({L}|{D})*
PRINT	[Pp][Rr][Ii][Nn][Tt]

%option noyywrap

%%

{WS}		{ /* ignora espaços, tabs e '\n' */ }

{STRING} 	{ yylval.v = yytext; return STRING; }
{NUM}   	{ yylval.v = yytext; return NUM; }
{PRINT} 	{ yylval.v = yytext; return PRINT; }

{ID}		{ yylval.v = yytext; return ID; }

.       	{ yylval.v = yytext; return *yytext; }

%%
