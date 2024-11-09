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

void add_array_symbol(const char *name, SymbolType type, ArrayDimensions dims) {
    if (symbol_count >= MAX_SYMBOLS) {
        printf("Erreur ligne %d: Too many symbols\n", yylineno);
        exit(1);
    }

    Symbol *sym = &symbols[symbol_count];
    sym->name = strdup(name);
    sym->type = type;
    sym->is_array = true;
    sym->is_constant = false;
    sym->dimensions = dims;

    // Calculate total size needed
    int total_size = dims.sizes[0];
    if (dims.num_dimensions > 1) {
        total_size *= dims.sizes[1];
    }

    // Allocate array memory based on type
    switch (type) {
        case TYPE_ENTIER:
            sym->value.array_val = calloc(total_size, sizeof(int));
            break;
        case TYPE_DECIMAL:
            sym->value.array_val = calloc(total_size, sizeof(double));
            break;
        case TYPE_LOGIQUE:
            sym->value.array_val = calloc(total_size, sizeof(bool));
            break;
        case TYPE_CHAINE:
            sym->value.array_val = calloc(total_size, sizeof(char*));
            break;
    }

    if (!sym->value.array_val) {
        printf("Erreur ligne %d: Memory allocation failed for array\n", yylineno);
        exit(1);
    }

    symbol_count++;
}

Statement *new_array_declaration(char *name, ArrayDimensions dims, SymbolType type) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = ARRAY_DECL;
    stmt->data.array_decl.array_name = strdup(name);
    stmt->data.array_decl.dimensions = dims;
    stmt->data.array_decl.element_type = type;
    return stmt;
}

Expression *new_array_access(char *array_name, Expression *index, Expression *index2) {
    Expression *expr = malloc(sizeof(Expression));
    expr->type = ARRAY_ACCESS;
    expr->data.array_access.array_name = strdup(array_name);
    expr->data.array_access.index = index;
    expr->data.array_access.index2 = index2;
    return expr;
}

static int get_array_offset(Symbol *sym, Expression *index1, Expression *index2) {
    Expression *idx1 = evaluate_expression(index1);
    int i1 = idx1->data.int_value;
    free(idx1);

    if (i1 < 0 || i1 >= sym->dimensions.sizes[0]) {
        printf("Erreur ligne %d: Array index out of bounds\n", yylineno);
        exit(1);
    }

    if (sym->dimensions.num_dimensions == 1) {
        return i1;
    }

    Expression *idx2 = evaluate_expression(index2);
    int i2 = idx2->data.int_value;
    free(idx2);

    if (i2 < 0 || i2 >= sym->dimensions.sizes[1]) {
        printf("Erreur ligne %d: Array index out of bounds\n", yylineno);
        exit(1);
    }

    return i1 * sym->dimensions.sizes[1] + i2;
}

void set_array_element(const char *name, Expression *indices, Expression *value) {
    Symbol *sym = get_symbol(name);
    if (!sym || !sym->is_array) {
        printf("Erreur ligne %d: Invalid array access\n", yylineno);
        exit(1);
    }

    Expression *eval_value = evaluate_expression(value);
    int offset = get_array_offset(sym, indices->data.array_access.index,
                                indices->data.array_access.index2);

    switch (sym->type) {
        case TYPE_ENTIER: {
            int *arr = (int*)sym->value.array_val;
            arr[offset] = eval_value->data.int_value;
            break;
        }
        case TYPE_DECIMAL: {
            double *arr = (double*)sym->value.array_val;
            arr[offset] = eval_value->data.double_value;
            break;
        }
        case TYPE_LOGIQUE: {
            bool *arr = (bool*)sym->value.array_val;
            arr[offset] = eval_value->data.bool_value;
            break;
        }
        case TYPE_CHAINE: {
            char **arr = (char**)sym->value.array_val;
            if (arr[offset]) free(arr[offset]);
            arr[offset] = strdup(eval_value->data.string_value);
            break;
        }
    }
    free(eval_value);
}

Expression *get_array_element(const char *name, Expression *indices) {
    Symbol *sym = get_symbol(name);
    if (!sym || !sym->is_array) {
        printf("Erreur ligne %d: Invalid array access\n", yylineno);
        exit(1);
    }

    int offset = get_array_offset(sym, indices->data.array_access.index,
                                indices->data.array_access.index2);

    Expression *result = malloc(sizeof(Expression));
    result->type = sym->type == TYPE_ENTIER ? INTEGER :
                   sym->type == TYPE_DECIMAL ? DECIMAL :
                   sym->type == TYPE_LOGIQUE ? BOOLEAN : STRING;

    switch (sym->type) {
        case TYPE_ENTIER: {
            int *arr = (int*)sym->value.array_val;
            result->data.int_value = arr[offset];
            break;
        }
        case TYPE_DECIMAL: {
            double *arr = (double*)sym->value.array_val;
            result->data.double_value = arr[offset];
            break;
        }
        case TYPE_LOGIQUE: {
            bool *arr = (bool*)sym->value.array_val;
            result->data.bool_value = arr[offset];
            break;
        }
        case TYPE_CHAINE: {
            char **arr = (char**)sym->value.array_val;
            result->data.string_value = strdup(arr[offset]);
            break;
        }
    }
    return result;
}