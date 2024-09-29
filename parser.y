/* This file defines the parser for the language using Bison. 
   It constructs the abstract syntax tree (AST) by analyzing the token 
   sequence generated by the lexical analyzer (lexer.l). The parser 
   enforces the grammar rules of the language, handling control flow 
   constructs, expressions, and assignments. 
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"

void yyerror(const char *s);
int yylex(void);

StatementList *parsed_program = NULL;
%}
%define parse.trace


%union {
    int int_value;
    double double_value;
    char *string_value;
    char *var_name;
    bool bval;
    SymbolType type;
    Expression *expression;
    Statement *statement;
    StatementList *statement_list;
    CaseList *case_list;
}

%token <int_value> ENTIER_VAL
%token <double_value> DECIMAL_VAL
%token <string_value> CHAINE STRING_VAL
%token <bval> LOGIQUE_VAL
%token <var_name> IDENTIFIANT
%token PLUS MINUS TIMES DIVIDE SI ALORS SINON SINONSI FINSI EQUALS LPAREN RPAREN VARIABLE_KWRD ECRIRE
%token ALGORITHME DEBUT FIN COLON LIRE ENTIER_KWRD DECIMAL_KWRD LOGIQUE_KWRD CHAINE_KWRD COMMA
%token COMMENT AND OR NOT XOR CONCAT
%token LT GT LE GE EQ NE
%token TANTQUE FAIRE FINTANTQUE
%token POUR DE A FINPOUR POWER MODULO CONSTANT
%token SELON FINSELON CAS
%token SQUARE_ROOT SINE COSINE TANGENT LOG LOG10 ROUND

%type <statement> statement
%type <statement_list> statement_list
%type <expression> expression
%type <type> type
%type <case_list> case_list

%left OR XOR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left TIMES DIVIDE
%left MODULO
%left POWER
%right NOT

%%

program:
    ALGORITHME IDENTIFIANT Declarations DEBUT statement_list FIN { printf("*********************\nAlgorithme %s\n\n*********************\n\n", $2); parsed_program = $5; }
;

Declarations:
    /*Empty*/
    | Declarations Declaration
    ;
Declaration:    
    VARIABLE_KWRD IDENTIFIANT COLON type { add_symbol($2, $4, false); }
    | CONSTANT IDENTIFIANT COLON ENTIER_VAL { add_symbol($2, TYPE_ENTIER, true); set_symbol_value($2, new_integer($4)); }
    | CONSTANT IDENTIFIANT EQUALS DECIMAL_VAL { add_symbol($2, TYPE_DECIMAL, true); set_symbol_value($2, new_decimal($4)); }
    | CONSTANT IDENTIFIANT EQUALS STRING_VAL { add_symbol($2, TYPE_CHAINE, true); set_symbol_value($2, new_string($4));}
    | CONSTANT IDENTIFIANT EQUALS LOGIQUE_VAL { add_symbol($2, TYPE_LOGIQUE, true); set_symbol_value($2, new_boolean($4)); }
    ;

statement_list:
    statement { $$ = new_statement_list($1, NULL); }
    | statement statement_list { $$ = new_statement_list($1, $2); }
    ;

statement:
    IDENTIFIANT EQUALS expression { $$ = new_assign($1, $3); }
    | SI expression ALORS statement_list FINSI { $$ = new_if($2, $4, NULL); }
    | SI expression ALORS statement_list SINON statement_list FINSI { $$ = new_if($2, $4, $6); }
    | ECRIRE LPAREN expression RPAREN { $$ = new_print($3); }
    | LIRE LPAREN IDENTIFIANT RPAREN { $$ = new_read($3); }
    | TANTQUE expression FAIRE statement_list FINTANTQUE { $$ = new_while($2, $4); }
    | POUR IDENTIFIANT DE expression A expression FAIRE statement_list FINPOUR { $$ = new_for($2, $4, $6, $8); }
    | SELON expression FAIRE case_list FINSELON { $$ = new_switch($2, $4, NULL); }
    | SELON expression FAIRE case_list SINON statement_list FINSELON { $$ = new_switch($2, $4, $6); }
    ;

case_list:
    CAS expression COLON statement_list { $$ = new_case_list($2, $4, NULL); }
    | CAS expression COLON statement_list case_list { $$ = new_case_list($2, $4, $5); }
    ;

expression:
    ENTIER_VAL { $$ = new_integer($1); }
    | DECIMAL_VAL { $$ = new_decimal($1); }
    | STRING_VAL { $$ = new_string($1); }
    | LOGIQUE_VAL { $$ = new_boolean($1); }
    | IDENTIFIANT { $$ = new_variable($1); }
    | expression PLUS expression { $$ = new_binary_op('+', $1, $3); }
    | expression MINUS expression { $$ = new_binary_op('-', $1, $3); }
    | expression TIMES expression { $$ = new_binary_op('*', $1, $3); }
    | expression DIVIDE expression { $$ = new_binary_op('/', $1, $3); }
    | expression AND expression { $$ = new_binary_op('&', $1, $3); }
    | expression CONCAT expression { $$ = new_binary_op('C', $1, $3); }
    | expression OR expression { $$ = new_binary_op('|', $1, $3); }
    | expression XOR expression { $$ = new_binary_op('^', $1, $3); }
    | expression POWER expression { $$ = new_binary_op('P', $1, $3); }
    | expression MODULO expression { $$ = new_binary_op('M', $1, $3); }
    | NOT expression { $$ = new_unary_op('!', $2); }
    | expression LT expression { $$ = new_binary_op('<', $1, $3); }
    | expression GT expression { $$ = new_binary_op('>', $1, $3); }
    | expression LE expression { $$ = new_binary_op('L', $1, $3); }
    | expression GE expression { $$ = new_binary_op('G', $1, $3); }
    | expression EQ expression { $$ = new_binary_op('=', $1, $3); }
    | expression NE expression { $$ = new_binary_op('!', $1, $3); }
    | LPAREN expression RPAREN { $$ = $2; }
    | SQUARE_ROOT LPAREN expression RPAREN {
        Expression *exp = evaluate_expression($3);
        $$ = new_decimal(exp->type == INTEGER ? sqrt(exp->data.int_value) : sqrt(exp->data.double_value));
        free(exp);
    }
    | SINE LPAREN expression RPAREN {
        Expression *exp = evaluate_expression($3);
        $$ = new_decimal(exp->type == INTEGER ? sin(exp->data.int_value) : sin(exp->data.double_value));
        free(exp);
    }
    | COSINE LPAREN expression RPAREN {
        Expression *exp = evaluate_expression($3);
        $$ = new_decimal(exp->type == INTEGER ? cos(exp->data.int_value) : cos(exp->data.double_value));
        free(exp);
    }
    | TANGENT LPAREN expression RPAREN {
        Expression *exp = evaluate_expression($3);
        $$ = new_decimal(exp->type == INTEGER ? tan(exp->data.int_value) : tan(exp->data.double_value));
        free(exp);
    }
    | LOG LPAREN expression RPAREN {
        Expression *exp = evaluate_expression($3);
        $$ = new_decimal(exp->type == INTEGER ? log(exp->data.int_value) : log(exp->data.double_value));
        free(exp);
    }
    | LOG10 LPAREN expression RPAREN {
        Expression *exp = evaluate_expression($3);
        $$ = new_decimal(exp->type == INTEGER ? log10(exp->data.int_value) : log10(exp->data.double_value));
        free(exp);
    }
    | ROUND LPAREN expression RPAREN {
        Expression *exp = evaluate_expression($3);
        $$ = new_decimal(exp->type == INTEGER ? round(exp->data.int_value) : round(exp->data.double_value));
        free(exp);
    }
    ;

type:
    ENTIER_KWRD { $$ = TYPE_ENTIER; }
    | DECIMAL_KWRD { $$ = TYPE_DECIMAL; }
    | CHAINE_KWRD { $$ = TYPE_CHAINE; }
    | LOGIQUE_KWRD { $$ = TYPE_LOGIQUE; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erreur ligne %d: %s\n", yylineno, s);
}