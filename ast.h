#ifndef AST_H
#define AST_H

#include <stdbool.h>

#define MAX_SYMBOLS 100

typedef enum {
    TYPE_ENTIER,
    TYPE_DECIMAL,
    TYPE_LOGIQUE,
    TYPE_CHAINE
} SymbolType;

typedef struct {
    char *name;
    union {
        int int_val;
        double float_val;
        bool bool_val;
        char *string_val;
    } value;
    SymbolType type;
} Symbol;




typedef struct Expression {
    enum { INTEGER, DECIMAL, STRING, VARIABLE, BINARY_OP } type;
    union {
        int int_value;
        double double_value;
        char *var_name;
        char *string_value;
        struct {
            char op;
            struct Expression *left;
            struct Expression *right;
        } binary_op;
    } data;
} Expression;

typedef struct Statement {
    enum { ASSIGN, PRINT, IF_STATEMENT, READ } type;
    union {
        struct { char *var_name; Expression *value; } assign;
        Expression *print_expr;
        struct { Expression *condition; struct StatementList *then_branch; struct StatementList *else_branch; } if_stmt;
        char *read_var_name;
    } data;
} Statement;

typedef struct StatementList {
    Statement *statement;
    struct StatementList *next;
} StatementList;

void add_symbol(const char *name, SymbolType type);
Symbol *get_symbol(const char *name);
void set_symbol_value(const char *name, Expression *value);

StatementList *new_statement_list(Statement *statement, StatementList *next);
Statement *new_assign(char *var_name, Expression *value);
Statement *new_print(Expression *expr);
Statement *new_if(Expression *condition, StatementList *then_branch, StatementList *else_branch);
Statement *new_read(char *var_name);

Expression *new_integer(int value);
Expression *new_decimal(double value);
Expression *new_variable(char *var_name);
Expression *new_string(char *string_value);
Expression *new_binary_op(char op, Expression *left, Expression *right);

void execute_statement_list(StatementList *list);
Expression* evaluate_expression(Expression *expr);

char* process_string(const char* str);

#endif
