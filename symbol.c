#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

Symbol symbols[MAX_SYMBOLS];
int symbol_count = 0;

/**
 * add_symbol - Adds a new symbol to the symbol table
 * @name: The name of the symbol to add
 * @type: The type of the symbol (from SymbolType enum)
 *
 * This function creates a new entry in the symbol table for a variable.
 * It allocates space for the symbol name, initializes its value based on
 * the type, and adds it to the global symbols array.
 *
 * Return: void
 */
void add_symbol(const char *name, SymbolType type, bool is_constant)
{
    if (symbol_count >= MAX_SYMBOLS)
    {
        printf("Erreur ligne %d: Trop de symboles", yylineno);
        return;
    }
    symbols[symbol_count].name = strdup(name);
    symbols[symbol_count].type = type;
    symbols[symbol_count].is_constant = is_constant;
    switch (type)
    {
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

/**
 * get_symbol - Retrieves a symbol from the symbol table
 * @name: The name of the symbol to retrieve
 *
 * This function searches the symbol table for a symbol with the given name.
 * It returns a pointer to the Symbol structure if found, or NULL if not found.
 *
 * Return: Pointer to the Symbol if found, NULL otherwise
 */
Symbol *get_symbol(const char *name)
{
    for (int i = 0; i < symbol_count; i++)
    {
        if (strcmp(symbols[i].name, name) == 0)
        {
            return &symbols[i];
        }
    }
    return NULL;
}

/**
 * set_symbol_value - Sets the value of a symbol in the symbol table
 * @name: The name of the symbol to update
 * @value: Pointer to an Expression containing the new value
 *
 * This function updates the value of an existing symbol in the symbol table.
 * It first retrieves the symbol, then sets its value based on its type and
 * the provided Expression.
 *
 * Return: void
 */
void set_symbol_value(const char *name, Expression *exp)
{
    Symbol *sym = get_symbol(name);
    if (sym)
    {
        switch (sym->type)
        {
        case TYPE_ENTIER:
            sym->value.int_val = exp->type == INTEGER ? exp->data.int_value : (int)exp->data.double_value;
            break;
        case TYPE_DECIMAL:
            sym->value.float_val = exp->type == DECIMAL ? exp->data.double_value : exp->data.int_value;
            break;
        case TYPE_LOGIQUE:
            sym->value.bool_val = exp->data.bool_value;
            break;
        case TYPE_CHAINE:
            if (sym->value.string_val)
            {
                free(sym->value.string_val);
            }
            sym->value.string_val = strdup(exp->data.string_value);
            break;
        }
    }
}