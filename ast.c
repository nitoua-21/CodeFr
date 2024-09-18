#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"

// Statement list constructor
StatementList *new_statement_list(Statement *statement, StatementList *next) {
    StatementList *list = malloc(sizeof(StatementList));
    list->statement = statement;
    list->next = next;
    return list;
}

// Create an assignment statement
Statement *new_assign(char *var_name, Expression *value) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = ASSIGN;
    stmt->data.assign.var_name = strdup(var_name);
    stmt->data.assign.value = value;
    return stmt;
}

// Create a print statement
Statement *new_print(Expression *expr) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = PRINT;
    stmt->data.print_expr = expr;
    return stmt;
}

// Create an if statement
Statement *new_if(Expression *condition, StatementList *then_branch, StatementList *else_branch) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = IF_STATEMENT;
    stmt->data.if_stmt.condition = condition;
    stmt->data.if_stmt.then_branch = then_branch;
    stmt->data.if_stmt.else_branch = else_branch;
    return stmt;
}

// Expression constructors
Expression *new_integer(int value) {
    Expression *expr = malloc(sizeof(Expression));
    expr->type = INTEGER;
    expr->data.int_value = value;
    return expr;
}

Expression *new_decimal(double value) {
    Expression *expr = malloc(sizeof(Expression));
    expr->type = DECIMAL;
    expr->data.double_value = value;
    return expr;
}

Expression *new_variable(char *var_name) {
    Expression *expr = malloc(sizeof(Expression));
    expr->type = VARIABLE;
    expr->data.var_name = strdup(var_name);
    return expr;
}

Expression *new_string(char *string_value) {
    Expression *expr = malloc(sizeof(Expression));
    expr->type = STRING;
    expr->data.string_value = strdup(string_value);
    return expr;
}

Expression *new_binary_op(char op, Expression *left, Expression *right)
{
    Expression *expr = malloc(sizeof(Expression));
    expr->type = BINARY_OP;
    expr->data.binary_op.op = op;
    expr->data.binary_op.left = left;
    expr->data.binary_op.right = right;
    return expr;
}

Statement *new_read(char *var_name) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = READ;
    stmt->data.read_var_name = strdup(var_name);
    return stmt;
}

// Execute a statement list
void execute_statement_list(StatementList *list) {
    int statement_count = 0;
    while (list) {
        statement_count++;
        Statement *stmt = list->statement;
        if (stmt->type == ASSIGN) {
            Symbol *sym = get_symbol(stmt->data.assign.var_name);
            if (!sym) {
                printf("Undefined variable: %s\n", stmt->data.assign.var_name);
                exit(1);
            }
            Expression *result = evaluate_expression(stmt->data.assign.value);
            set_symbol_value(stmt->data.assign.var_name, result);
            free(result);
        } else if (stmt->type == PRINT) {
            switch (stmt->data.print_expr->type)
            {
            case INTEGER:
                int value = evaluate_expression(stmt->data.print_expr)->data.int_value;
                printf("%d\n", value);
                break;
            case DECIMAL:
                double fvalue = evaluate_expression(stmt->data.print_expr)->data.double_value;
                printf("%f\n", fvalue);
                break;
            case STRING:
                char *cvalue = strdup(evaluate_expression(stmt->data.print_expr)->data.string_value);
                printf("%s\n", cvalue);
                free(cvalue);
                break; 
            case VARIABLE:
                Symbol *sym = get_symbol(stmt->data.print_expr->data.var_name);
                if (!sym) {
                    printf("Undefined variable: %s\n", stmt->data.print_expr->data.var_name);
                    exit(1);
                }
                switch (sym->type)
                {
                case TYPE_ENTIER:
                    printf("%d\n", sym->value.int_val);
                    break;
                case TYPE_DECIMAL:
                    printf("%f\n", sym->value.float_val);
                    break;
                case TYPE_CHAINE:
                    printf("%s\n", sym->value.string_val);
                    break;
                case TYPE_LOGIQUE:
                    printf("%s\n", sym->value.bool_val ? "Vrai" : "Faux");
                    break;
                default:
                    break;
                }
            default:
                break;
            }
        } else if (stmt->type == IF_STATEMENT) {
            int condition = evaluate_expression(stmt->data.if_stmt.condition)->data.int_value;
            if (condition) {
                execute_statement_list(stmt->data.if_stmt.then_branch);
            } else if (stmt->data.if_stmt.else_branch) {
                execute_statement_list(stmt->data.if_stmt.else_branch);
            }
        } else if (stmt->type == READ) {
            Symbol *sym = get_symbol(stmt->data.read_var_name);
            if (!sym) {
                printf("Undefined variable: %s\n", stmt->data.read_var_name);
                exit(1);
            }
            char input[256];
            printf("Enter value for %s: ", stmt->data.read_var_name);
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0; // Remove newline

            Expression *exp = malloc(sizeof(Expression));
            switch (sym->type) {
                case TYPE_ENTIER:
                    exp->type = INTEGER;
                    exp->data.int_value = atoi(input);
                    break;
                case TYPE_DECIMAL:
                    exp->type = DECIMAL;
                    exp->data.double_value = atof(input);
                    break;
                case TYPE_CHAINE:
                    exp->type = STRING;
                    exp->data.string_value = strdup(input);
                    break;
                case TYPE_LOGIQUE:
                    printf("Boolean input not supported\n");
                    free(exp);
                    exit(1);
            }
            set_symbol_value(stmt->data.read_var_name, exp);
            free(exp);
        }
        list = list->next;
    }
}

Expression *evaluate_expression(Expression *expr) {
    if (expr == NULL) {
        return NULL;
    }

    Expression *new_expr = malloc(sizeof(Expression));
    if (new_expr == NULL) {
        printf("Error: Memory allocation failed in evaluate_expression\n");
        exit(1);
    }

    switch (expr->type) {
        case INTEGER:
            new_expr->type = INTEGER;
            new_expr->data.int_value = expr->data.int_value;
            break;

        case DECIMAL:
            new_expr->type = DECIMAL;
            new_expr->data.double_value = expr->data.double_value;
            break;

        case STRING:
            new_expr->type = STRING;
            new_expr->data.string_value = strdup(expr->data.string_value);
            if (new_expr->data.string_value == NULL) {
                free(new_expr);
                exit(1);
            }
            break;

        case VARIABLE:
            {
                Symbol *sym = get_symbol(expr->data.var_name);
                if (!sym) {
                    printf("Error: Undefined variable: %s\n", expr->data.var_name);
                    free(new_expr);
                    exit(1);
                }
                switch (sym->type) {
                    case TYPE_ENTIER:
                        new_expr->type = INTEGER;
                        new_expr->data.int_value = sym->value.int_val;
                        break;
                    case TYPE_DECIMAL:
                        new_expr->type = DECIMAL;
                        new_expr->data.double_value = sym->value.float_val;
                        break;
                    case TYPE_CHAINE:
                        new_expr->type = STRING;
                        new_expr->data.string_value = strdup(sym->value.string_val);
                        if (new_expr->data.string_value == NULL) {
                            printf("Error: Memory allocation failed for string duplication\n");
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case TYPE_LOGIQUE:
                        printf("Error: Boolean type not supported in expressions\n");
                        free(new_expr);
                        exit(1);
                }
            }
            break;

        case BINARY_OP:
            {
                Expression *lval = evaluate_expression(expr->data.binary_op.left);
                Expression *rval = evaluate_expression(expr->data.binary_op.right);

                bool isint = lval->type == INTEGER && rval->type == INTEGER;
                bool isnumber = (lval->type == INTEGER || lval->type == DECIMAL) && (rval->type == INTEGER || rval->type == DECIMAL); 

                switch (expr->data.binary_op.op) {
                    case '+':
                        if (isint)
                        {
                            new_expr->type = INTEGER;
                            new_expr->data.int_value = lval->data.int_value + rval->data.int_value;
                        }else if (isnumber){
                            new_expr->type = DECIMAL;
                            double lvalue = lval->data.double_value + lval->data.int_value;
                            double rvalue = rval->data.double_value + rval->data.int_value;
                            new_expr->data.double_value = lvalue + rvalue;
                        }
                        else {
                            printf("Error: Invalid type for addition\n");
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case '-':
                        if (isint)
                        {
                            new_expr->type = INTEGER;
                            new_expr->data.int_value = lval->data.int_value - rval->data.int_value;
                        }else if (isnumber){
                            new_expr->type = DECIMAL;
                            double lvalue = lval->data.double_value + lval->data.int_value;
                            double rvalue = rval->data.double_value + rval->data.int_value;
                            new_expr->data.double_value = lvalue - rvalue;
                        }
                        else {
                            printf("Error: Invalid type for substraction\n");
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case '*':
                        if (isint)
                        {
                            new_expr->type = INTEGER;
                            new_expr->data.int_value = lval->data.int_value * rval->data.int_value;
                        }else if (isnumber){
                            new_expr->type = DECIMAL;
                            double lvalue = lval->data.double_value + lval->data.int_value;
                            double rvalue = rval->data.double_value + rval->data.int_value;
                            new_expr->data.double_value = lvalue * rvalue;
                        }
                        else {
                            printf("Error: Invalid type for multiplication\n");
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case '/':
                        if (isnumber){
                            if (((rval->data.int_value + rval->data.double_value) == 0)) {
                                printf("Division par zéro\n");
                                free(lval);
                                free(rval);
                                free(new_expr);
                                exit(1);
                            }
                            new_expr->type = DECIMAL;
                            double lvalue = lval->data.double_value + lval->data.int_value;
                            double rvalue = rval->data.double_value + rval->data.int_value;
                            new_expr->data.double_value = lvalue / rvalue;
                        } else {
                            printf("Error: Invalid type for Division\n");
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    default:
                        printf("Error: Unknown binary operator\n");
                        free(lval);
                        free(rval);
                        free(new_expr);
                        exit(1);
                    }
                free(lval);
                free(rval);
            }
            break;
        default:
            printf("Error: Unknown expression type\n");
            free(new_expr);
            exit(1);
    }
    return new_expr;
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