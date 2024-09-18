#ifndef CODEFR_H
#define CODEFR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

#define MAX_SYMBOLS 100
#define MAX_IF_NESTING 100
#define MAX_STRING_LENGTH 256

typedef enum {
    TYPE_ENTIER,
    TYPE_DECIMAL,
    TYPE_LOGIQUE,
    TYPE_CHAINE
} SymbolType;

typedef struct {
    bool condition;
    bool executed;
} IfBlockState;


typedef struct {
    enum { STMT_READ, STMT_WRITE, STMT_ASSIGN, STMT_IF } type;
    union {
        char var_name[MAX_STRING_LENGTH];
        double expression;
        struct {
            bool condition;
            Statement *then_block;
        } if_stmt;
    } data;
    Statement *next;
} Statement;

typedef struct {
    char *name;
    union {
        int int_val;
        double float_val;
        bool bool_val;
        char *string_val;
        char op;
    } value;
    SymbolType type;
} Symbol;

extern Symbol symbols[MAX_SYMBOLS];
extern int symbol_count;

// Symbol table functions
void add_symbol(const char *name, SymbolType type);
Symbol *get_symbol(const char *name);
void set_symbol_value(const char *name, void *value);

// Variable list functions
char **create_var_list(const char *name);
void add_var_to_list(char **list, const char *name);
void free_var_list(char **list);

// Expression evaluation
double evaluate_expression(double left, char operator, double right);

// Error handling
void report_error(const char *message);
char* process_string(const char* str);

// Statement functions
Statement *create_statement(int type);
void execute_statement(Statement *stmt);

// Conditional handling
void start_if_block();
void start_else_if_block();
void start_else_block();
void end_if_block();
bool evaluate_comparison(double left, char op, double right);
bool should_execute();
void write_statement(int arg_count, ...);
void read_statement(const char* variable_name);

#endif /* CODEFR_H */