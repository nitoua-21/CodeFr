#ifndef MODULE_H
#define MODULE_H

#include <stdbool.h>
#include "ast.h"

// Structure to represent a module
typedef struct Module {
    char *name;
    Function **functions;
    int function_count;
    int function_capacity;
} Module;

// Structure to represent an import statement
typedef struct Import {
    char *module_name;
    char **function_names;  // NULL if importing whole module
    int function_count;
} Import;

// Global module table
#define MAX_MODULES 100
extern Module *module_table[MAX_MODULES];
extern int module_count;

// Function declarations
Module *new_module(const char *name);
void add_function_to_module(Module *module, Function *function);
Module *get_module(const char *name);
Function *get_module_function(const char *module_name, const char *function_name);
Import *new_import(const char *module_name, char **function_names, int function_count);
void execute_import(Import *import);

#endif // MODULE_H
