%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codefr.h"

int yylex(void);
void yyerror(const char *s);
extern int yylineno;
%}

%union {
    int ival;
    double fval;
    char *sval;
    bool bval;
    char **str_list;
    SymbolType type;
}

%token <ival> ENTIER_VAL
%token <fval> DECIMAL_VAL
%token <sval> IDENTIFIER STRING_VAL
%token <bval> LOGIQUE_VAL

%token PLUS MINUS TIMES DIVIDE
%token LPAREN RPAREN
%token ASSIGN VARIABLE VARIABLES ECRIRE LIRE
%token COLON COMMA
%token ALGORITHME DEBUT FIN
%token ENTIER DECIMAL LOGIQUE CHAINE

%type <fval> expr
%type <str_list> var_list
%type <type> type

%%

program:
    ALGORITHME IDENTIFIER var_decl_list DEBUT statement_list FIN
    ;

var_decl_list:
    /* empty */
    | var_decl_list var_decl
    ;

var_decl:
    VARIABLE IDENTIFIER COLON type { add_symbol($2, $4); }
    | VARIABLES var_list COLON type { 
        for (int i = 0; $2[i] != NULL; i++) {
			add_symbol($2[i], $4);
        }
        free_var_list($2);
    }
    ;

var_list:
    IDENTIFIER { $$ = create_var_list($1); }
    | var_list COMMA IDENTIFIER { add_var_to_list($1, $3); $$ = $1; }
    ;

statement_list:
    statement
    | statement_list statement
    ;

statement:
    assignment
    | io_operation
    | expr { printf("%f\n", $1); }
    ;

assignment:
    IDENTIFIER ASSIGN expr { 
        Symbol *sym = get_symbol($1);
        if (sym) {
			set_symbol_value($1, &$3);
        } else {
            report_error("Variable non déclarée");
        }
    }
    ;

io_operation:
    ECRIRE LPAREN expr RPAREN { printf("%f\n", $3); }
    | ECRIRE LPAREN IDENTIFIER RPAREN { 
        Symbol *sym = get_symbol($3);
        if (sym) {
            switch (sym->type) {
                case TYPE_ENTIER:
                    printf("%d\n", sym->value.int_val);
                    break;
                case TYPE_DECIMAL:
                    printf("%f\n", sym->value.float_val);
                    break;
                case TYPE_LOGIQUE:
                    printf("%s\n", sym->value.bool_val ? "Vrai" : "Faux");
                    break;
                case TYPE_CHAINE:
                    printf("%s\n", sym->value.string_val);
                    break;
            }
        } else {
            report_error("Variable non déclarée");
        }
    }
    | LIRE LPAREN IDENTIFIER RPAREN {
        Symbol *sym = get_symbol($3);
        if (sym) {
            switch (sym->type) {
                case TYPE_ENTIER:
                    printf("Entrez une valeur entière pour %s: ", $3);
                    scanf("%d", &sym->value.int_val);
                    break;
                case TYPE_DECIMAL:
                    printf("Entrez une valeur décimale pour %s: ", $3);
                    scanf("%lf", &sym->value.float_val);
                    break;
                case TYPE_LOGIQUE:
                    printf("Entrez une valeur logique pour %s (0 pour Faux, 1 pour Vrai): ", $3);
                    scanf("%d", (int*)&sym->value.bool_val);
                    break;
                case TYPE_CHAINE:
                    printf("Entrez une chaîne pour %s: ", $3);
                    sym->value.string_val = malloc(100); // Allocate space for string
                    scanf("%99s", sym->value.string_val);
                    break;
            }
        } else {
            report_error("Variable non déclarée");
        }
    }
    ;

expr:
    ENTIER_VAL { $$ = (double)$1; }
    | DECIMAL_VAL { $$ = $1; }
    | IDENTIFIER { 
        Symbol *sym = get_symbol($1);
        if (sym) {
            switch (sym->type) {
                case TYPE_ENTIER:
                    $$ = (double)sym->value.int_val;
                    break;
                case TYPE_DECIMAL:
                    $$ = sym->value.float_val;
                    break;
                default:
                    report_error("Type incompatible dans l'expression");
                    $$ = 0;
            }
        } else {
            report_error("Variable non déclarée");
            $$ = 0;
        }
    }
    | expr PLUS expr { $$ = evaluate_expression($1, '+', $3); }
    | expr MINUS expr { $$ = evaluate_expression($1, '-', $3); }
    | expr TIMES expr { $$ = evaluate_expression($1, '*', $3); }
    | expr DIVIDE expr { 
        if ($3 == 0) {
            report_error("Division par zéro");
            $$ = 0;
        } else {
            $$ = evaluate_expression($1, '/', $3);
        }
    }
    | LPAREN expr RPAREN { $$ = $2; }
    ;

type:
    ENTIER { $$ = TYPE_ENTIER; }
    | DECIMAL { $$ = TYPE_DECIMAL; }
    | LOGIQUE { $$ = TYPE_LOGIQUE; }
    | CHAINE { $$ = TYPE_CHAINE; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erreur à la ligne %d: %s\n", yylineno, s);
}
