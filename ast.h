#ifndef AST_H
#define AST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SYMBOLS 100
extern int yylineno;


/**
 * enum SymbolType - Enumerates the possible types of symbols
 * @TYPE_ENTIER: Represents an integer type
 * @TYPE_DECIMAL: Represents a decimal (floating-point) type
 * @TYPE_LOGIQUE: Represents a logical (boolean) type
 * @TYPE_CHAINE: Represents a string type
 *
 * This enumeration defines the possible data types that can be
 * represented in the language being interpreted.
 */
typedef enum {
    TYPE_ENTIER,
    TYPE_DECIMAL,
    TYPE_LOGIQUE,
    TYPE_CHAINE
} SymbolType;

/**
 * struct Symbol - Represents a symbol in the symbol table
 * @name: The name of the symbol (variable name)
 * @value: Union containing the value of the symbol
 * @type: The type of the symbol (from SymbolType enum)
 *
 * This structure represents a symbol in the symbol table, which
 * stores information about variables in the program.
 */
typedef struct {
    char *name;
    bool is_constant;
    union {
        int int_val;
        double float_val;
        bool bool_val;
        char *string_val;
    } value;
    SymbolType type;
} Symbol;



/**
 * struct Expression - Represents an expression in the AST
 * @type: The type of the expression
 * @data: Union containing the data specific to each expression type
 *
 * This structure represents various types of expressions in the
 * abstract syntax tree, including literals, variables, and operations.
 */
typedef struct Expression {
    enum { INTEGER, DECIMAL, BOOLEAN, STRING, VARIABLE, BINARY_OP, UNARY_OP } type;
    union {
        int int_value;
        double double_value;
        bool bool_value;
        char *var_name;
        char *string_value;
        struct {
            char op;
            struct Expression *left;
            struct Expression *right;
        } binary_op;
         struct {
            char op;
            struct Expression *operand;
        } unary_op;       
    } data;
} Expression;

typedef struct CaseList {
    Expression *condition;
    struct StatementList *body;
    struct CaseList *next;
} CaseList;

/**
 * struct Statement - Represents a statement in the AST
 * @type: The type of the statement
 * @data: Union containing the data specific to each statement type
 *
 * This structure represents various types of statements in the
 * abstract syntax tree, including assignments, print statements,
 * if statements, and read statements.
 */
typedef struct Statement {
    enum { ASSIGN, PRINT, IF_STATEMENT, READ, WHILE_STATEMENT, FOR_STATEMENT, SWITCH_STATEMENT } type;
    union {
        struct { char *var_name; Expression *value; } assign;
        Expression *print_expr;
        struct { Expression *condition; struct StatementList *then_branch; struct StatementList *else_branch; } if_stmt;
        char *read_var_name;
        struct { Expression *condition; struct StatementList *body; } while_stmt;
        struct { char *counter; Expression *start; Expression *end; struct StatementList *body; } for_stmt;
        struct { Expression *value; CaseList *cases; struct StatementList *default_case; } switch_stmt;
    } data;
} Statement;


/**
 * struct StatementList - Represents a list of statements in the AST
 * @statement: Pointer to the current Statement
 * @next: Pointer to the next StatementList node
 *
 * This structure represents a linked list of statements, allowing
 * for the representation of sequences of statements in the program.
 */
typedef struct StatementList {
    Statement *statement;
    struct StatementList *next;
} StatementList;

void add_symbol(const char *name, SymbolType type, bool is_constant);
Symbol *get_symbol(const char *name);
void set_symbol_value(const char *name, Expression *value);

StatementList *new_statement_list(Statement *statement, StatementList *next);
Statement *new_assign(char *var_name, Expression *value);
Statement *new_print(Expression *expr);
Statement *new_if(Expression *condition, StatementList *then_branch, StatementList *else_branch);
Statement *new_read(char *var_name);
Statement *new_while(Expression *condition, StatementList *body);
Statement *new_for(char *counter, Expression *start, Expression *end, StatementList *body);
Statement *new_switch(Expression *value, CaseList *cases, StatementList *default_case);
CaseList *new_case_list(Expression *condition, StatementList *body, CaseList *next);
void execute_statement_list(StatementList *list);

Expression *new_integer(int value);
Expression *new_decimal(double value);
Expression *new_variable(char *var_name);
Expression *new_string(char *string_value);
Expression *new_binary_op(char op, Expression *left, Expression *right);
Expression *new_boolean(bool value);
Expression *new_unary_op(char op, Expression *operand);
Expression* evaluate_expression(Expression *expr);

char* process_string(const char* str);

#endif
