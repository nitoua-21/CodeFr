#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module.h"

// Global module table
Module *module_table[MAX_MODULES];
int module_count = 0;

Module *new_module(const char *name) {
    Module *module = malloc(sizeof(Module));
    if (!module) {
        printf("Memory allocation failed for module\n");
        exit(1);
    }
    
    module->name = strdup(name);
    module->function_capacity = 10;
    module->functions = malloc(sizeof(Function *) * module->function_capacity);
    module->function_count = 0;
    
    return module;
}

void add_function_to_module(Module *module, Function *function) {
    if (module->function_count >= module->function_capacity) {
        module->function_capacity *= 2;
        module->functions = realloc(module->functions, 
                                  sizeof(Function *) * module->function_capacity);
        if (!module->functions) {
            printf("Memory reallocation failed for module functions\n");
            exit(1);
        }
    }
    
    module->functions[module->function_count++] = function;
}

Module *get_module(const char *name) {
    for (int i = 0; i < module_count; i++) {
        if (strcmp(module_table[i]->name, name) == 0) {
            return module_table[i];
        }
    }
    return NULL;
}

Function *get_module_function(const char *module_name, const char *function_name) {
    Module *module = get_module(module_name);
    if (!module) {
        printf("Module '%s' not found\n", module_name);
        return NULL;
    }
    
    for (int i = 0; i < module->function_count; i++) {
        if (strcmp(module->functions[i]->name, function_name) == 0) {
            return module->functions[i];
        }
    }
    
    printf("Function '%s' not found in module '%s'\n", function_name, module_name);
    return NULL;
}

Import *new_import(const char *module_name, char **function_names, int function_count) {
    Import *import = malloc(sizeof(Import));
    if (!import) {
        printf("Memory allocation failed for import\n");
        exit(1);
    }
    
    import->module_name = strdup(module_name);
    import->function_names = function_names;
    import->function_count = function_count;
    
    return import;
}

/**
 * count_function_names - Count the number of function names in a NULL-terminated array
 * @names: Array of function names, NULL-terminated
 * Return: Number of function names
 */
int count_function_names(char **names) {
    if (!names) return 0;
    int count = 0;
    while (names[count]) count++;
    return count;
}

void execute_import(Import *import) {
    Module *module = get_module(import->module_name);
    if (!module) {
        printf("Cannot import from module '%s': module not found\n", import->module_name);
        exit(1);
    }
    
    if (!import->function_names) {
        // Import entire module
        // Functions will be accessed using module.function syntax
        return;
    }
    
    // Import specific functions
    for (int i = 0; i < import->function_count; i++) {
        Function *func = get_module_function(import->module_name, import->function_names[i]);
        if (!func) {
            printf("Cannot import function '%s' from module '%s': function not found\n",
                   import->function_names[i], import->module_name);
            exit(1);
        }
        // Add function to current scope
        add_function(func);
    }
}
