#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "codefr.h"

Symbol symbols[MAX_SYMBOLS];
int symbol_count = 0;

void add_symbol(const char *name, SymbolType type) {
    if (symbol_count >= MAX_SYMBOLS) {
        report_error("Trop de symboles");
        return;
    }
    symbols[symbol_count].name = strdup(name);
    symbols[symbol_count].type = type;
    symbol_count++;
}

Symbol *get_symbol(const char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbols[i].name, name) == 0) {
            return &symbols[i];
        }
    }
    return NULL;
}

void set_symbol_value(const char *name, void *value) {
    Symbol *sym = get_symbol(name);
    if (sym) {
        switch (sym->type) {
            case TYPE_ENTIER:
                sym->value.int_val = *((int*)value);
                break;
            case TYPE_DECIMAL:
                sym->value.float_val = *((double*)value);
                break;
            case TYPE_LOGIQUE:
                sym->value.bool_val = *((bool*)value);
                break;
            case TYPE_CHAINE:
                if (sym->value.string_val) {
                    free(sym->value.string_val);
                }
                sym->value.string_val = strdup((char*)value);
                break;
        }
    }
}

char **create_var_list(const char *name) {
    char **list = malloc(sizeof(char*) * 2);
    list[0] = strdup(name);
    list[1] = NULL;
    return list;
}

void add_var_to_list(char **list, const char *name) {
    int count = 0;
    while (list[count] != NULL) count++;
    list = realloc(list, sizeof(char*) * (count + 2));
    list[count] = strdup(name);
    list[count + 1] = NULL;
}

void free_var_list(char **list) {
    for (int i = 0; list[i] != NULL; i++) {
        free(list[i]);
    }
    free(list);
}

double evaluate_expression(double left, char operator, double right) {
    switch (operator) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': 
            if (right == 0) {
                report_error("Division par zéro");
                return 0;
            }
            return left / right;
        default:
            report_error("Opérateur inconnu");
            return 0;
    }
}

void report_error(const char *message) {
    fprintf(stderr, "Erreur: %s\n", message);
}
