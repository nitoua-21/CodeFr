%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codefr.h"
#include "parser.tab.h"
%}

%option noyywrap
%option yylineno

%%
[ \t\n]         ; /* Ignore whitespace */
"Algorithme"    { return ALGORITHME; }
"Debut"         { return DEBUT; }
"Fin"           { return FIN; }
"Variable"      { return VARIABLE; }
"Variables"     { return VARIABLES; }
"Ecrire"        { return ECRIRE; }
"Lire"          { return LIRE; }
"Entier"        { return ENTIER; }
"Decimal"       { return DECIMAL; }
"Logique"       { return LOGIQUE; }
"Chaine"        { return CHAINE; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"="             { return ASSIGN; }
[0-9]+          { yylval.ival = atoi(yytext); return ENTIER_VAL; }
[0-9]+\.[0-9]+  { yylval.fval = atof(yytext); return DECIMAL_VAL; }
"Vrai"          { yylval.bval = true; return LOGIQUE_VAL; }
"Faux"          { yylval.bval = false; return LOGIQUE_VAL; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return IDENTIFIER; }
\"([^"]|\\.)*\"  {
    yylval.sval = process_string(yytext + 1);
    return STRING_VAL;
}
":"             { return COLON; }
","             { return COMMA; }
.               { printf("Caractère inattendu: %s\n", yytext); }
%%
