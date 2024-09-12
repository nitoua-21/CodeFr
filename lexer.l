%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"

%}

%option noyywrap

%%
[ \t\n]         ; /* Ignore whitespace */
"Algorithme"    { return ALGORITHME; }
"Debut"         { return DEBUT; }
"Fin"           { return FIN; }
"Variable"      { return VARIABLE; }
"Ecrire"        { return ECRIRE; }
"Entier"        { return ENTIER; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"="             { return ASSIGN; }
[0-9]+          { yylval.ival = atoi(yytext); return NUMBER; }
[a-zA-Z][a-zA-Z0-9]* { yylval.sval = strdup(yytext); return IDENTIFIER; }
\"[^\"]+\"      { yylval.str = strdup(yytext); return STRING; }
":"             { return COLON; }
","             { return COMMA; }
.               { printf("Unexpected character: %s\n", yytext); }
%%
