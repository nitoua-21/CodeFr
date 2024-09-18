#include "codefr.h"
#include <stdbool.h>
#include <stdarg.h>

static IfBlockState if_stack[MAX_IF_NESTING];
static int if_nesting_level = 0;

void start_if_block() {
    if (if_nesting_level >= MAX_IF_NESTING) {
        report_error("Maximum if nesting level exceeded");
        return;
    }
    if_nesting_level++;
    if_stack[if_nesting_level - 1].condition = false;
    if_stack[if_nesting_level - 1].executed = false;
    //
}

void start_else_if_block() {
    if (if_nesting_level == 0) {
        report_error("Unexpected SinonSi");
        return;
    }
    if_stack[if_nesting_level - 1].condition = false;
    //
}

void start_else_block() {
    if (if_nesting_level == 0) {
        report_error("Unexpected Sinon");
        return;
    }
    if_stack[if_nesting_level - 1].condition = !if_stack[if_nesting_level - 1].executed;
    //
}

void end_if_block() {
    if (if_nesting_level == 0) {
        report_error("Unexpected FinSi");
        return;
    }
    if_nesting_level--;
    //
}

bool evaluate_comparison(double left, char op, double right) {
    bool result;
    switch (op) {
        case '>': result = left > right; break;
        case '<': result = left < right; break;
        case '=': result = left == right; break;
        case 'g': result = left >= right; break;
        case 'l': result = left <= right; break;
        case '!': result = left != right; break;
        default:
            report_error("Opérateur de comparaison inconnu");
            return false;
    }
    /*
    if (if_nesting_level > 0 && !if_stack[if_nesting_level - 1].executed) {
        if_stack[if_nesting_level - 1].condition = result;
        if (result) {
            if_stack[if_nesting_level - 1].executed = true;
        }
    }*/   
    return result;
}

bool should_execute() {
    if (if_nesting_level == 0) {
        return true;
    }
    
    for (int i = 0; i < if_nesting_level; i++) {
        if (!if_stack[i].condition) {
            return false;
        }
    }
    
    return true;
}

void execute_statement(const char* statement_type) {
    if (should_execute()) {

        // Actual execution logic here
    } else {
        // tes5
    }
}

void write_statement(int arg_count, ...) {
    if (should_execute()) {
        va_list args;
        va_start(args, arg_count);
        
        for (int i = 0; i < arg_count; i++) {
            char* arg_type = va_arg(args, char*);
            if (strcmp(arg_type, "string") == 0) {
                char* str = va_arg(args, char*);
                printf("%s", str);
            } else if (strcmp(arg_type, "int") == 0) {
                int value = va_arg(args, int);
                printf("%d", value);
            } else if (strcmp(arg_type, "variable") == 0) {
                char* var_name = va_arg(args, char*);
                Symbol* sym = get_symbol(var_name);
                if (sym) {
                    switch (sym->type) {
                        case TYPE_ENTIER:
                            printf("%d", sym->value.int_val);
                            break;
                        // Add cases for other types as needed
                        default:
                            report_error("Unsupported type for write operation");
                    }
                } else {
                    report_error("Undefined variable in write statement");
                }
            }
        }
        
        va_end(args);
    } else {
        //
    }
}

void read_statement(const char* variable_name) {
    if (should_execute()) {
        Symbol* sym = get_symbol(variable_name);
        if (sym) {
            switch (sym->type) {
                case TYPE_ENTIER: {
                    int value;
                    if (scanf("%d", &value) == 1) {
                        set_symbol_value(variable_name, &value);
                    } else {
                        report_error("Invalid input for integer");
                    }
                    break;
                }
                // Add cases for other types as needed
                default:
                    report_error("Unsupported type for read operation");
            }
        } else {
            report_error("Undefined variable in read statement");
        }
    } else {
        //
    }
}