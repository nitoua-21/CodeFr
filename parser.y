%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 100

int yylex(void);
void yyerror(const char *s);

/**
 * struct variable - Structure to hold variable information
 * @name: Name of the variable
 * @value: Value of the variable
 */
struct variable {
	char *name;
	int value;
};

struct variable variables[MAX_VARS];
int var_count = 0;

int get_variable(const char *name);
void set_variable(const char *name, int value);
%}

%union {
	int ival;
	char *sval;
}

%token <ival> NUMBER
%token <sval> IDENTIFIER
%token PLUS MINUS TIMES DIVIDE
%token LPAREN RPAREN
%token ASSIGN VARIABLE WRITE
%token COLON INTEGER COMMA
%token ALGORITHME DEBUT FIN

%type <ival> expr
%type <str> string

%%

program:
	statement_list
	;

statement_list:
	statement
	| statement_list statement
	;

statement:
	variable_declaration
	| assignment
	| write_statement
	| expr { printf("%d\n", $1); }
	;

variable_declaration:
	VARIABLE IDENTIFIER COLON INTEGER { set_variable($2, 0); }
	;

assignment:
	IDENTIFIER ASSIGN expr { set_variable($1, $3); }
	;

write_statement:
	WRITE LPAREN expr RPAREN { printf("%d\n", $3); }
	| WRITE LPAREN IDENTIFIER RPAREN { printf("%d\n", get_variable($3)); }
	;

expr:
	NUMBER { $$ = $1; }
	| IDENTIFIER { $$ = get_variable($1); }
	| expr PLUS expr { $$ = $1 + $3; }
	| expr MINUS expr { $$ = $1 - $3; }
	| expr TIMES expr { $$ = $1 * $3; }
	| expr DIVIDE expr {
		if ($3 == 0) {
			yyerror("Division par zero");
			YYABORT;
		}
		$$ = $1 / $3;
	}
	| LPAREN expr RPAREN { $$ = $2; }
	;

%%

/**
 * yyerror - Print error message
 * @s: Error message
 */
void yyerror(const char *s)
{
	fprintf(stderr, "Error: %s\n", s);
}

/**
 * get_variable - Get value of a variable
 * @name: Name of the variable
 * Return: Value of the variable
 */
int get_variable(const char *name)
{
	int i;

	for (i = 0; i < var_count; i++)
	{
		if (strcmp(variables[i].name, name) == 0)
			return (variables[i].value);
	}
	fprintf(stderr, "Error: Undeclared variable %s\n", name);
	exit(1);
}

/**
 * set_variable - Set value of a variable
 * @name: Name of the variable
 * @value: Value to set
 */
void set_variable(const char *name, int value)
{
	int i;

	for (i = 0; i < var_count; i++)
	{
		if (strcmp(variables[i].name, name) == 0)
		{
			variables[i].value = value;
			return;
		}
	}
	if (var_count >= MAX_VARS)
	{
		fprintf(stderr, "Error: Too many variables\n");
		exit(1);
	}
	variables[var_count].name = strdup(name);
	variables[var_count].value = value;
	var_count++;
}
