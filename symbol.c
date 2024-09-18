#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

Symbol symbols[MAX_SYMBOLS];
int symbol_count = 0;

void add_symbol(const char *name, SymbolType type) {
    if (symbol_count >= MAX_SYMBOLS) {
        printf("Trop de symboles");
        return;
    }
    symbols[symbol_count].name = strdup(name);
    symbols[symbol_count].type = type;
    switch (type) {
        case TYPE_ENTIER:
            symbols[symbol_count].value.int_val = 0;
            break;
        case TYPE_DECIMAL:
            symbols[symbol_count].value.float_val = 0.0;
            break;
        case TYPE_LOGIQUE:
            symbols[symbol_count].value.bool_val = false;
            break;
        case TYPE_CHAINE:
            symbols[symbol_count].value.string_val = strdup("");
            break;
    }
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

void set_symbol_value(const char *name, Expression *exp) {
    Symbol *sym = get_symbol(name);
    if (sym) {
        switch (sym->type) {
            case TYPE_ENTIER:
                sym->value.int_val = exp->data.int_value;
                break;
            case TYPE_DECIMAL:
                sym->value.float_val = exp->data.double_value;
                break;
            case TYPE_CHAINE:
                if (sym->value.string_val) {
                    free(sym->value.string_val);
                }
                sym->value.string_val = strdup(exp->data.string_value);
                break;
        }
    }
}