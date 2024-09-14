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
    if (name == NULL) {
        report_error("Nom de variable invalide");
        return;
    }
    symbols[symbol_count].name = strdup(name);
    if (symbols[symbol_count].name == NULL) {
        report_error("Échec de l'allocation mémoire pour le nom du symbole");
        return;
    }
    
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
            symbols[symbol_count].value.string_val = strdup("");  // Initialize with an empty string
            if (symbols[symbol_count].value.string_val == NULL) {
                report_error("Échec de l'allocation mémoire pour la valeur de chaîne");
                free(symbols[symbol_count].name);  // Clean up previously allocated name
                return;
            }
            break;
        default:
            report_error("Type de variable inconnu");
            free(symbols[symbol_count].name);  // Clean up previously allocated name
            return;
    }
    symbol_count++;
}

Symbol *get_symbol(const char *name) {
    if (name == NULL) {
        report_error("Nom de variable invalid");
        return NULL;
    }
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
                double val = *((double*)value);
                
                sym->value.int_val = (int)val;
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
                if (sym->value.string_val == NULL) {
                    report_error("Échec de l'allocation mémoire pour la valeur de chaîne");
                    sym->value.string_val = strdup("");  // Fallback to empty string
                    if (sym->value.string_val == NULL) {
                        report_error("Échec critique d'allocation mémoire");
                    }
                }
                break;
            default:
                report_error("Type de variable inconnu dans set_symbol_value");
        }
    } else {
        report_error("Tentative de définir la valeur d'une variable non déclarée");
    }
}

char **create_var_list(const char *name) {
    char **list = malloc(sizeof(char*) * 2);
    if (list == NULL) {
        report_error("Échec de l'allocation mémoire pour la liste de variables");
        return NULL;
    }
    list[0] = strdup(name);
    if (list[0] == NULL) {
        report_error("Échec de l'allocation mémoire pour le nom de variable");
        free(list);
        return NULL;
    }
    list[1] = NULL;
    return list;
}

void add_var_to_list(char **list, const char *name) {
    if (list == NULL || name == NULL) {
        report_error("Liste de variables ou nom invalide");
        return;
    }
    int count = 0;
    while (list[count] != NULL) count++;
    char **new_list = realloc(list, sizeof(char*) * (count + 2));
    if (new_list == NULL) {
        report_error("Échec de la réallocation de la liste de variables");
        return;
    }
    list = new_list;
    list[count] = strdup(name);
    if (list[count] == NULL) {
        report_error("Échec de l'allocation mémoire pour le nouveau nom de variable");
        return;
    }
    list[count + 1] = NULL;
}

void free_var_list(char **list) {
    if (list == NULL) {
        return;
    }
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

char* process_string(const char* str) {
    int len = strlen(str);
    char* processed = malloc(len);
    int i, j;
    for (i = 0, j = 0; i < len - 1; i++, j++) {
        if (str[i] == '\\') {
            i++;
            switch (str[i]) {
                case 'n': processed[j] = '\n'; break;
                case 't': processed[j] = '\t'; break;
                case '\\': processed[j] = '\\'; break;
                case '"': processed[j] = '"'; break;
                default: processed[j] = str[i];
            }
        } else {
            processed[j] = str[i];
        }
    }
    processed[j] = '\0';
    return processed;
}

void report_error(const char *message) {
    fprintf(stderr, "Erreur: %s\n", message);
}
