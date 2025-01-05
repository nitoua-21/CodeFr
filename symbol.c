#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

Symbol symbols[MAX_SYMBOLS];
int symbol_count = 0;

// Stack to store symbol counts for each scope
#define MAX_SCOPE_DEPTH 100
static int scope_stack[MAX_SCOPE_DEPTH];
static int scope_depth = 0;

/**
 * push_scope - Creates a new variable scope
 *
 * Description: This function saves the current symbol count
 * to allow restoration of the previous scope later.
 */
void push_scope(void) {
    if (scope_depth >= MAX_SCOPE_DEPTH) {
        printf("Error: Maximum scope depth exceeded\n");
        exit(1);
    }
    scope_stack[scope_depth++] = symbol_count;
}

/**
 * pop_scope - Restores the previous variable scope
 *
 * Description: This function restores the symbol table to its
 * state before the current scope was created, effectively
 * removing all symbols declared in the current scope.
 */
void pop_scope(void) {
    if (scope_depth <= 0) {
        printf("Error: Cannot pop global scope\n");
        exit(1);
    }
    
    // Free any string values in the symbols we're removing
    for (int i = scope_stack[scope_depth - 1]; i < symbol_count; i++) {
        if (symbols[i].type == TYPE_CHAINE && symbols[i].value.string_val) {
            free(symbols[i].value.string_val);
        }
        free(symbols[i].name);
    }
    
    // Restore symbol count to previous scope
    symbol_count = scope_stack[--scope_depth];
}

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
void set_symbol_value(const char *name, Expression *exp) {
    Symbol *sym = get_symbol(name);
    if (sym) {
        switch (sym->type) {
            case TYPE_ENTIER:
                sym->value.int_val = exp->type == INTEGER ? exp->data.int_value : 
                                   exp->type == DECIMAL ? (int)exp->data.double_value : 
                                   exp->type == BOOLEAN ? exp->data.bool_value : 0;
                break;
            case TYPE_DECIMAL:
                sym->value.float_val = exp->type == DECIMAL ? exp->data.double_value : 
                                     exp->type == INTEGER ? (double)exp->data.int_value :
                                     exp->type == BOOLEAN ? (double)exp->data.bool_value : 0.0;
                break;
            case TYPE_LOGIQUE:
                sym->value.bool_val = exp->data.bool_value;
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

/**
 * add_array_symbol - Adds a new array symbol to the symbol table
 * @name: The name of the array to be added
 * @type: The type of elements in the array (SymbolType)
 * @dims: Structure containing array dimensions information
 *
 * Description: This function creates a new symbol table entry for an array.
 * It allocates memory for the array based on its dimensions and type,
 * initializes the memory to zero, and adds the symbol to the table.
 *
 * Return: void
 *
 * Error conditions:
 * - Exits if symbol table is full (MAX_SYMBOLS reached)
 * - Exits if memory allocation for array fails
 */
void add_array_symbol(const char *name, SymbolType type, ArrayDimensions dims) {
    if (symbol_count >= MAX_SYMBOLS) {
        printf("Erreur ligne %d: Trop de symboles\n", yylineno);
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
        printf("Erreur ligne %d: Échec de l'allocation de mémoire pour le tableau\n", yylineno);
        exit(1);
    }

    symbol_count++;
}

/**
 * new_array_declaration - Creates a new array declaration statement
 * @name: The name of the array being declared
 * @dims: Structure containing array dimensions information
 * @type: The type of elements in the array (SymbolType)
 *
 * Description: This function allocates and initializes a new Statement
 * structure specifically for array declarations. It stores the array's
 * name, dimensions, and element type for later processing during execution.
 *
 * Return: Pointer to the newly created Statement structure
 *         NULL if memory allocation fails
 */
Statement *new_array_declaration(char *name, ArrayDimensions dims, SymbolType type) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = ARRAY_DECL;
    stmt->data.array_decl.array_name = strdup(name);
    stmt->data.array_decl.dimensions = dims;
    stmt->data.array_decl.element_type = type;
    return stmt;
}

/**
 * new_array_access - Creates a new array access expression
 * @array_name: Name of the array being accessed
 * @index: Expression representing the first dimension index
 * @index2: Expression representing the second dimension index (NULL for 1D arrays)
 *
 * Description: This function creates an Expression structure representing
 * an array access operation. It handles both single and multi-dimensional
 * array access, where index2 is only used for 2D arrays.
 *
 * Return: Pointer to the newly created Expression structure
 *         NULL if memory allocation fails
 */
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
        printf("Erreur ligne %d: Index de tableau hors limites\n", yylineno);
        exit(1);
    }

    if (sym->dimensions.num_dimensions == 1) {
        return i1;
    }

    Expression *idx2 = evaluate_expression(index2);
    int i2 = idx2->data.int_value;
    free(idx2);

    if (i2 < 0 || i2 >= sym->dimensions.sizes[1]) {
        printf("Erreur ligne %d: Index de tableau hors limites\n", yylineno);
        exit(1);
    }

    return i1 * sym->dimensions.sizes[1] + i2;
}


/**
 * set_array_element - Sets the value of an array element
 * @name: Name of the array
 * @indices: Expression containing array access indices
 * @value: Expression containing the value to be set
 *
 * Description: This function assigns a value to an array element at the
 * specified indices. It handles type checking and conversion, bounds
 * checking, and memory management for string types.
 *
 * Return: void
 *
 * Error conditions:
 * - Exits if array name is not found in symbol table
 * - Exits if indices are out of bounds
 * - Exits if type mismatch between value and array
 */
void set_array_element(const char *name, Expression *indices, Expression *value) {
    Symbol *sym = get_symbol(name);
    if (!sym || !sym->is_array) {
        printf("Erreur ligne %d: Accès au tableau invalide\n", yylineno);
        exit(1);
    }
    
    Expression *eval_value = evaluate_expression(value);
    int index1 = evaluate_expression(indices->data.array_access.index)->data.int_value;

    printf("Indice: %d\n", index1);
    
    // Validate index bounds
    if (index1 < 0 || index1 >= sym->dimensions.sizes[0]) {
        printf("Erreur ligne %d: Array index out of bounds\n", yylineno);
        exit(1);
    }

    int offset = index1;
    if (indices->data.array_access.index2) {
        int index2 = evaluate_expression(indices->data.array_access.index2)->data.int_value;
        if (index2 < 0 || index2 >= sym->dimensions.sizes[1]) {
            printf("Erreur ligne %d: Array index out of bounds\n", yylineno);
            exit(1);
        }
        offset = index1 * sym->dimensions.sizes[1] + index2;
    }

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

/**
 * get_array_element - Retrieves the value of an array element
 * @name: Name of the array
 * @indices: Expression containing array access indices
 *
 * Description: This function creates a new Expression containing the value
 * of the array element at the specified indices. It performs bounds checking
 * and handles all supported types (integer, decimal, boolean, string).
 *
 * Return: Pointer to a new Expression containing the array element's value
 *         NULL if array access is invalid
 *
 * Error conditions:
 * - Exits if array name is not found in symbol table
 * - Exits if indices are out of bounds
 * - Exits if memory allocation fails
 */
Expression *get_array_element(const char *name, Expression *indices) {
    Symbol *sym = get_symbol(name);
    if (!sym || !sym->is_array) {
        printf("Erreur ligne %d: Accès au tableau invalide\n", yylineno);
        exit(1);
    }
    int index1 = evaluate_expression(indices->data.array_access.index)->data.int_value;
    
    // Validate index bounds
    if (index1 < 0 || index1 >= sym->dimensions.sizes[0]) {
        printf("Erreur ligne %d: Array index out of bounds\n", yylineno);
        exit(1);
    }

    int offset = index1;
    if (indices->data.array_access.index2) {
        int index2 = evaluate_expression(indices->data.array_access.index2)->data.int_value;
        if (index2 < 0 || index2 >= sym->dimensions.sizes[1]) {
            printf("Erreur ligne %d: Array index out of bounds\n", yylineno);
            exit(1);
        }
        offset = index1 * sym->dimensions.sizes[1] + index2;
    }

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