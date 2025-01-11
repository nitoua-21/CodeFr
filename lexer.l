/* This file defines the lexical analyzer for the  language using Flex. 
   It tokenizes the input into reserved keywords, identifiers, operators, 
   and other symbols. Token values are passed to the parser for syntactic 
   analysis. 
*/
%{
#include "ast.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void yyerror(const char *s);
%}

%option noyywrap
%x COMMENT
%option yylineno

%%
[ \t\n]+        ; /* Ignore whitespace */
"//".*          { /* Ignore single-line comments */ }

"Module"        { return MODULE; }
"FinModule"     { return FINMODULE; }
"Importer"      { return IMPORTER; }
"Depuis"        { return DEPUIS; }
"."             { return DOT; }

"Algorithme"    { return ALGORITHME; }
"Debut"         { return DEBUT; }
"Variable"      { return VARIABLE_KWRD; }
"Variables"     { return VARIABLES; }
"Fonction"      { return FONCTION; }
"Retourner"     { return RETOURNER; }
"FinFonction"   { return FINFONCTION; }
"Ecrire"        { return ECRIRE; }
"Lire"          { return LIRE; }
"Entier"        { return ENTIER_KWRD; }
"Decimal"       { return DECIMAL_KWRD; }
"Logique"       { return LOGIQUE_KWRD; }
"Chaine"        { return CHAINE_KWRD; }
"Si"            { return SI; }
"Alors"         { return ALORS; }
"Constante"     { return CONSTANT; }
"Sinon"         { return SINON; }
"SinonSi"       { return SINONSI; }
"FinSi"         { return FINSI; }
"TantQue"       { return TANTQUE; }
"Faire"         { return FAIRE; }
"FinTantQue"    { return FINTANTQUE; }
"Fin"           { return FIN; }
"Pour"          { return POUR; }
"De"            { return DE; }
"A"             { return A; }
"FinPour"       { return FINPOUR; }
"Selon"         { return SELON; }
"Cas"           { return CAS; }
"FinSelon"      { return FINSELON; }
"^"             { return POWER; }
"Mod"           { return MODULO; }
"Racine"        { return SQUARE_ROOT; }
"Sin"           { return SINE; }
"Cos"           { return COSINE; }
"Tan"           { return TANGENT; }
"Log"           { return LOG; }
"Log10"         { return LOG10; }
"Arrondi"       { return ROUND; }
"Abs"           { return ABS; }
"Alea"          { return RANDOM; }
"Ent"           { return INT; }
"Longueur"      { return LENGTH; }
"Concatener"    { return CONCATENATE; }
"Copie"         { return COPY; }
"Comparer"      { return COMPARE; }
"Recherche"     { return SEARCH; }
"Tableau"       { return TABLEAU; }
"Type"          { return TYPE_KWRD; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"="             { return EQUALS; }
"Et"            { return AND; }
"Ou"            { return OR; }
"Non"           { return NOT; }
"Oux"           { return XOR; }
"<"             { return LT; }
">"             { return GT; }
"<="            { return LE; }
">="            { return GE; }
"=="            { return EQ; }
"!="            { return NE; }
"&"             { return CONCAT; }
":"             { return COLON; }
","             { return COMMA; }

[-+]?[0-9]+          { yylval.int_value = atoi(yytext); return ENTIER_VAL; }
[-+]?[0-9]+\.[0-9]+  { yylval.double_value = atof(yytext); return DECIMAL_VAL; }
"Vrai"          { yylval.bval = true; return LOGIQUE_VAL; }
"Faux"          { yylval.bval = false; return LOGIQUE_VAL; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.var_name = strdup(yytext); return IDENTIFIANT; }
\"([^"]|\\.)*\"  {
    yylval.string_value = process_string(yytext + 1);
    return STRING_VAL;
}

 /* Multi-line comment */
"/*"            { BEGIN(COMMENT); }
<COMMENT>"*/"   { BEGIN(INITIAL); }
<COMMENT>.|\n   ;

.               { printf("Caractère inattendu: %s\n", yytext); }
%%
