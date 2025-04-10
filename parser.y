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
#include <time.h>
#include "ast.h"
#include "module.h"

void yyerror(const char *s);
int yylex(void);

StatementList *parsed_program = NULL;
Module *current_module = NULL;

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
    ExpressionList *expression_list;
    ArrayDimensions dims;
    ElseIfList *elseif_list;
    IdentifierList *identifier_list;
    Parameter *parameter;
    Function *function;
    struct Module *module;
    struct Import *import;
    char **function_names;
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
%token ABS INT RANDOM
%token LENGTH COMPARE CONCATENATE COPY SEARCH
%token BREAK CONTINUE
%token TABLEAU LBRACKET RBRACKET VARIABLES
%token FONCTION RETOURNER FINFONCTION TYPE_KWRD
%token MODULE FINMODULE IMPORTER DEPUIS DOT

%type <statement> statement Declaration
%type <statement_list> statement_list Declarations module_content
%type <expression> expression
%type <type> type
%type <case_list> case_list
%type <expression_list> expression_list args_list
%type <dims> array_dimensions
%type <elseif_list> elif_list
%type <identifier_list> identifier_list
%type <parameter> param_list param
%type <function> function_decl
%type <module> module_decl
%type <import> import_stmt
%type <function_names> function_name_list

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
    module_decl
    | import_stmt Declarations DEBUT statement_list FIN { parsed_program = $4; }
    | Declarations DEBUT statement_list FIN { parsed_program = $3; }
    | function_decl program
;

function_decl:
    FONCTION IDENTIFIANT LPAREN param_list RPAREN COLON type Declarations statement_list FINFONCTION {
        $$ = new_function($2, $4, $7, $8, $9);
        if (current_module) {
            add_function_to_module(current_module, $$);
        } else {
            add_function($$);
        }
    }
    | FONCTION IDENTIFIANT LPAREN param_list RPAREN Declarations statement_list FINFONCTION {
        $$ = new_function($2, $4, TYPE_VOID, $6, $7);
        if (current_module) {
            add_function_to_module(current_module, $$);
        } else {
            add_function($$);
        }
    }
;

param_list:
    /* empty */ { $$ = NULL; }
    | param { $$ = $1; }
    | param COMMA param_list { $$ = $1; $$->next = $3; }
;

param:
    IDENTIFIANT COLON type { $$ = new_parameter($1, $3, NULL); }
;

args_list:
    /* empty */ { $$ = NULL; }
    | expression { $$ = new_expression_list($1, NULL); }
    | expression COMMA args_list { $$ = new_expression_list($1, $3); }
;

Declarations:
    /*Empty*/ { $$ = NULL; }
    | Declarations Declaration { 
        if ($2 != NULL) {
            $$ = new_statement_list($2, $1);
        } else {
            $$ = $1;
        }
    }
    ;

Declaration:    
    VARIABLE_KWRD IDENTIFIANT COLON type { 
        Statement *stmt = malloc(sizeof(Statement));
        stmt->type = VAR_DECL;
        stmt->data.var_decl.name = $2;
        stmt->data.var_decl.type = $4;
        add_symbol($2, $4, false);
        $$ = stmt;
    }
    | VARIABLES identifier_list COLON type { 
        add_multiple_symbols($2, $4); 
        $$ = NULL; 
    }
    | CONSTANT IDENTIFIANT EQUALS ENTIER_VAL { 
        add_symbol($2, TYPE_ENTIER, true); 
        set_symbol_value($2, new_integer($4)); 
        $$ = NULL; 
    }
    | CONSTANT IDENTIFIANT EQUALS DECIMAL_VAL { 
        add_symbol($2, TYPE_DECIMAL, true); 
        set_symbol_value($2, new_decimal($4)); 
        $$ = NULL; 
    }
    | CONSTANT IDENTIFIANT EQUALS STRING_VAL { 
        add_symbol($2, TYPE_CHAINE, true); 
        set_symbol_value($2, new_string($4)); 
        $$ = NULL; 
    }
    | CONSTANT IDENTIFIANT EQUALS LOGIQUE_VAL { 
        add_symbol($2, TYPE_LOGIQUE, true); 
        set_symbol_value($2, new_boolean($4)); 
        $$ = NULL; 
    }
    | TABLEAU IDENTIFIANT array_dimensions COLON type {
        add_array_symbol($2, $5, $3);
        $$ = NULL;
    }
    ;

identifier_list:
    IDENTIFIANT { $$ = new_identifier_list($1, NULL); }
    | IDENTIFIANT COMMA identifier_list { $$ = new_identifier_list($1, $3); }
    ;

array_dimensions:
    LBRACKET expression RBRACKET {
        ArrayDimensions dims;
        Expression *size = evaluate_expression($2);
        dims.sizes[0] = size->data.int_value;
        dims.num_dimensions = 1;
        free(size);
        $$ = dims;
    }
    | LBRACKET expression RBRACKET LBRACKET expression RBRACKET {
        ArrayDimensions dims;
        Expression *size1 = evaluate_expression($2);
        Expression *size2 = evaluate_expression($5);
        dims.sizes[0] = size1->data.int_value;
        dims.sizes[1] = size2->data.int_value;
        dims.num_dimensions = 2;
        free(size1);
        free(size2);
        $$ = dims;
    }
    ;

statement_list:
    statement { $$ = new_statement_list($1, NULL); }
    | statement statement_list { $$ = new_statement_list($1, $2); }
    ;

statement:
    IDENTIFIANT LBRACKET expression RBRACKET EQUALS expression { 
        $$ = new_array_assign($1, $3, NULL, $6); 
        free($1);
    }
    | IDENTIFIANT LBRACKET expression RBRACKET LBRACKET expression RBRACKET EQUALS expression { 
        $$ = new_array_assign($1, $3, $6, $9); 
        free($1);
    }
    | IDENTIFIANT EQUALS expression { $$ = new_assign($1, $3); }
    | SI expression ALORS Declarations statement_list FINSI { $$ = new_if_elif($2, $5, NULL, NULL); }
    | SI expression ALORS Declarations statement_list elif_list FINSI { $$ = new_if_elif($2, $5, $6, NULL); }
    | SI expression ALORS Declarations statement_list elif_list SINON Declarations statement_list FINSI { $$ = new_if_elif($2, $5, $6, $9); }
    | SI expression ALORS Declarations statement_list SINON Declarations statement_list FINSI { $$ = new_if_elif($2, $5, NULL, $8); }
    | ECRIRE LPAREN expression_list RPAREN { $$ = new_print($3); }
    | LIRE LPAREN IDENTIFIANT RPAREN { $$ = new_read($3); }
    | TANTQUE expression FAIRE Declarations statement_list FINTANTQUE { $$ = new_while($2, $5); }
    | POUR IDENTIFIANT DE expression A expression FAIRE Declarations statement_list FINPOUR { $$ = new_for($2, $4, $6, $9); }
    | SELON expression FAIRE Declarations case_list FINSELON { $$ = new_switch($2, $5, NULL); }
    | SELON expression FAIRE Declarations case_list SINON Declarations statement_list FINSELON { $$ = new_switch($2, $5, $8); }
    | IDENTIFIANT LPAREN args_list RPAREN { $$ = new_function_call($1, $3); }
    | RETOURNER expression { $$ = new_return($2); }
    | BREAK { $$ = new_break(); }
    | CONTINUE { $$ = new_continue(); }
    ;

elif_list:
    SINONSI expression ALORS statement_list
        { $$ = new_elif_list($2, $4, NULL); }
    | SINONSI expression ALORS statement_list elif_list
        { $$ = new_elif_list($2, $4, $5); }
    ;

expression_list:
    expression { $$ = new_expression_list($1, NULL); }
    | expression COMMA expression_list { $$ = new_expression_list($1, $3); }
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
    | IDENTIFIANT LPAREN args_list RPAREN { 
        //Statement *call = new_function_call($1, $3);
        $$ = new_function_expression($1, $3);
    }
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
    | SQUARE_ROOT LPAREN expression RPAREN { $$ = new_unary_op('R', $3); }
    | SINE LPAREN expression RPAREN { $$ = new_unary_op('S', $3); }
    | COSINE LPAREN expression RPAREN { $$ = new_unary_op('C', $3); }
    | TANGENT LPAREN expression RPAREN { $$ = new_unary_op('T', $3); }
    | LOG LPAREN expression RPAREN {$$ = new_unary_op('L', $3); }
    | LOG10 LPAREN expression RPAREN { $$ = new_unary_op('l', $3);}
    | ROUND LPAREN expression RPAREN { $$ = new_unary_op('D', $3);}
    | ABS LPAREN expression RPAREN { $$ = new_unary_op('A', $3);}
    | INT LPAREN expression RPAREN { $$ = new_unary_op('E', $3);}
    | RANDOM LPAREN RPAREN {
        srand(time(0));
        double random_number = (double)rand() / (RAND_MAX + 1.0);
        $$ = new_decimal(random_number);
    }
    | RANDOM LPAREN expression COMMA expression RPAREN { $$ = new_binary_op('A', $3, $5); }
    | LENGTH LPAREN expression RPAREN { $$ = new_unary_op('H', $3); }
    | COMPARE LPAREN expression COMMA expression RPAREN { $$ = new_binary_op('p', $3, $5); }
    | COPY LPAREN expression COMMA expression  COMMA expression RPAREN {
        Expression *str_exp = evaluate_expression($3);
        Expression *pos_exp = evaluate_expression($5);
        Expression *n_exp = evaluate_expression($7);

        if (str_exp->type != STRING || pos_exp->type != INTEGER || n_exp->type != INTEGER)
        {
            printf("Erreur ligne %d: Type d'argument invalide pour 'Copie'\n", yylineno);
            exit(1);
        }

        char *new_str = malloc(sizeof(char*) * strlen(str_exp->data.string_value) + 1);

        strncpy(new_str, str_exp->data.string_value + pos_exp->data.int_value, n_exp->data.int_value);
        new_str[n_exp->data.int_value] = '\0';

        $$ = new_string(new_str);
        free(str_exp);
        free(pos_exp);
        free(n_exp);
        //free(new_str);
    }
    | SEARCH LPAREN expression COMMA expression RPAREN { $$ = new_binary_op('r', $3, $5); }
    | IDENTIFIANT LBRACKET expression RBRACKET {
        $$ = new_array_access($1, $3, NULL);
    }
    | IDENTIFIANT LBRACKET expression RBRACKET LBRACKET expression RBRACKET {
        $$ = new_array_access($1, $3, $6);
    }
    | TYPE_KWRD LPAREN expression RPAREN { 
        $$ = new_unary_op('t', $3);
    }
    | IDENTIFIANT DOT IDENTIFIANT LPAREN args_list RPAREN {
        // Module-qualified function call
        Function *func = get_module_function($1, $3);
        if (!func) {
            yyerror("Fonction introuvable dans le module");
            YYERROR;
        }
        $$ = new_function_expression($3, $5);
        //$$ = evaluate_function_call($3, $5);
    }
    | IDENTIFIANT DOT IDENTIFIANT {
        // Module-qualified variable access
        yyerror("Accès à une variable qualifiée par module non supporté");
        YYERROR;
    }
    ;

type:
    ENTIER_KWRD { $$ = TYPE_ENTIER; }
    | DECIMAL_KWRD { $$ = TYPE_DECIMAL; }
    | CHAINE_KWRD { $$ = TYPE_CHAINE; }
    | LOGIQUE_KWRD { $$ = TYPE_LOGIQUE; }
    ;

module_decl:
    MODULE IDENTIFIANT module_content FINMODULE {
        $$ = new_module($2);
        current_module = $$;
        module_table[module_count++] = $$;
        // Add all functions from module_content to module
        StatementList *list = $3;
        while (list) {
            if (list->statement && list->statement->type == FUNCTION_DECL) {
                add_function_to_module($$, list->statement->data.function_decl.function);
            }
            list = list->next;
        }
        current_module = NULL;
    }
;

module_content:
    function_decl { $$ = new_statement_list(new_function_statement($1), NULL); }
    | function_decl module_content { $$ = new_statement_list(new_function_statement($1), $2); }
;

import_stmt:
    IMPORTER IDENTIFIANT {
        $$ = new_import($2, NULL, 0);
        execute_import($$);
    }
    | DEPUIS IDENTIFIANT IMPORTER function_name_list {
        $$ = new_import($2, $4, count_function_names($4));
        execute_import($$);
    }
;

function_name_list:
    IDENTIFIANT {
        char **names = malloc(sizeof(char *));
        names[0] = $1;
        $$ = names;
    }
    | function_name_list COMMA IDENTIFIANT {
        int count = 0;
        char **names = $1;
        while (names[count]) count++;
        names = realloc(names, sizeof(char *) * (count + 2));
        names[count] = $3;
        names[count + 1] = NULL;
        $$ = names;
    }
;

%%

void yyerror(const char *s) {
    // Check if this is a lexical error (already formatted)
    if (strncmp(s, "Erreur lexicale", 15) == 0) {
        fprintf(stderr, "%s\n", s);
        return;
    }
    
    // Handle syntax errors with more context
    if (strcmp(s, "syntax error") == 0) {
        // Get the current token from yytext
        extern char *yytext;
        
        if (yytext && *yytext) {
            fprintf(stderr, "Erreur de syntaxe ligne %d: Élément inattendu '%s'\n", yylineno, yytext);
        } else {
            fprintf(stderr, "Erreur de syntaxe ligne %d: Structure incorrecte ou élément manquant\n", yylineno);
        }
        
        // Provide hints based on context
        if (strstr(yytext, "Fin") != NULL) {
            fprintf(stderr, "Conseil: Vérifiez que chaque bloc a une instruction de début et de fin correspondante\n");
        } else if (strstr(yytext, "Si") != NULL || strstr(yytext, "Alors") != NULL) {
            fprintf(stderr, "Conseil: La structure correcte est 'Si condition Alors ... FinSi'\n");
        } else if (strstr(yytext, "Pour") != NULL) {
            fprintf(stderr, "Conseil: La structure correcte est 'Pour variable De debut A fin Faire ... FinPour'\n");
        } else if (strstr(yytext, "Fonction") != NULL) {
            fprintf(stderr, "Conseil: La structure correcte est 'Fonction nom(params): Type ... FinFonction'\n");
        }
    }
    else {
        fprintf(stderr, "Erreur ligne %d: %s\n", yylineno, s);
    }
}