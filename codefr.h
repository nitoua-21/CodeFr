#ifndef CODEFR_H
#define CODEFR_H

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

#endif /* CODEFR_H */
