#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"

/**
 * new_statement_list - Creates a new statement list
 * @statement: Pointer to the Statement to be added to the list
 * @next: Pointer to the next StatementList in the sequence
 *
 * This function creates a new StatementList node, which is part of a linked
 * list structure representing a sequence of statements in the program.
 *
 * Return: A pointer to the newly created StatementList
 */
StatementList *new_statement_list(Statement *statement, StatementList *next) {
    StatementList *list = malloc(sizeof(StatementList));
    list->statement = statement;
    list->next = next;
    return list;
}


/**
 * new_assign - Creates a new assignment statement
 * @var_name: The name of the variable being assigned
 * @value: Pointer to the Expression representing the value to be assigned
 *
 * This function creates a new Statement structure representing an
 * assignment operation (e.g., x = 5).
 *
 * Return: A pointer to the newly created Statement
 */
Statement *new_assign(char *var_name, Expression *value) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = ASSIGN;
    stmt->data.assign.var_name = strdup(var_name);
    stmt->data.assign.value = value;
    return stmt;
}


/**
 * new_print - Creates a new print statement
 * @expr: Pointer to the Expression to be printed
 *
 * This function creates a new Statement structure representing a
 * print operation, which outputs the value of an expression.
 *
 * Return: A pointer to the newly created Statement
 */
Statement *new_print(Expression *expr) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = PRINT;
    stmt->data.print_expr = expr;
    return stmt;
}

/**
 * new_if - Creates a new if statement
 * @condition: Pointer to the Expression representing the condition
 * @then_branch: Pointer to the StatementList for the 'then' branch
 * @else_branch: Pointer to the StatementList for the 'else' branch (can be NULL)
 *
 * This function creates a new Statement structure representing an
 * if-then-else control structure.
 *
 * Return: A pointer to the newly created Statement
 */
Statement *new_if(Expression *condition, StatementList *then_branch, StatementList *else_branch) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = IF_STATEMENT;
    stmt->data.if_stmt.condition = condition;
    stmt->data.if_stmt.then_branch = then_branch;
    stmt->data.if_stmt.else_branch = else_branch;
    return stmt;
}

/**
 * new_read - Creates a new read statement
 * @var_name: The name of the variable to store the read value
 *
 * This function creates a new Statement structure representing a
 * read operation, which inputs a value from the user and stores it
 * in a variable.
 *
 * Return: A pointer to the newly created Statement
 */
Statement *new_read(char *var_name) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = READ;
    stmt->data.read_var_name = strdup(var_name);
    return stmt;
}

Statement *new_while(Expression *condition, StatementList *body) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = WHILE_STATEMENT;
    stmt->data.while_stmt.condition = condition;
    stmt->data.while_stmt.body = body;
    return stmt;
}

Statement *new_for(char *counter, Expression *start, Expression *end, StatementList *body) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = FOR_STATEMENT;
    stmt->data.for_stmt.counter = strdup(counter);
    stmt->data.for_stmt.start = start;
    stmt->data.for_stmt.end = end;
    stmt->data.for_stmt.body = body;
    return stmt;
}

Statement *new_switch(Expression *value, CaseList *cases, StatementList *default_case) {
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = SWITCH_STATEMENT;
    stmt->data.switch_stmt.value = value;
    stmt->data.switch_stmt.cases = cases;
    stmt->data.switch_stmt.default_case = default_case;
    return stmt;
}

CaseList *new_case_list(Expression *condition, StatementList *body, CaseList *next) {
    CaseList *case_list = malloc(sizeof(CaseList));
    case_list->condition = condition;
    case_list->body = body;
    case_list->next = next;
    return case_list;
}

/**
 * execute_statement_list - Executes a list of statements
 * @list: Pointer to the StatementList to be executed
 *
 * This function traverses a StatementList and executes each Statement
 * in the list. It forms the core of the interpreter's execution engine.
 *
 * Return: void
 */
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
            if (sym->is_constant) {
                printf("Erreur ligne %d : Reassignment of constant variable %s not allowed\n", yylineno, stmt->data.assign.var_name);
                exit(1);
            }
            Expression *result = evaluate_expression(stmt->data.assign.value);
            if (sym->type != result->type) {
                printf("Erreur ligne %d : Incompatible type for assignment to variable %s\n", yylineno, stmt->data.assign.var_name);
                exit(1);
            }
            set_symbol_value(stmt->data.assign.var_name, result);
            free(result);
        } else if (stmt->type == PRINT) {
            switch (stmt->data.print_expr->type)
            {
            case INTEGER:
                int value = evaluate_expression(stmt->data.print_expr)->data.int_value;
                printf("%d", value);
                break;
            case DECIMAL:
                double fvalue = evaluate_expression(stmt->data.print_expr)->data.double_value;
                printf("%f", fvalue);
                break;
            case STRING:
                char *cvalue = strdup(evaluate_expression(stmt->data.print_expr)->data.string_value);
                printf("%s", cvalue);
                free(cvalue);
                break; 
            case VARIABLE:
                Symbol *sym = get_symbol(stmt->data.print_expr->data.var_name);
                if (!sym) {
                    printf("Erreur ligne %d: Undefined variable: %s\n", yylineno, stmt->data.print_expr->data.var_name);
                    exit(1);
                }
                switch (sym->type)
                {
                case TYPE_ENTIER:
                    printf("%d", sym->value.int_val);
                    break;
                case TYPE_DECIMAL:
                    printf("%f", sym->value.float_val);
                    break;
                case TYPE_CHAINE:
                    printf("%s", sym->value.string_val);
                    break;
                case TYPE_LOGIQUE:
                    printf("%s", sym->value.bool_val ? "Vrai" : "Faux");
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
                printf("Erreur ligne %d: Undefined variable: %s\n", yylineno, stmt->data.read_var_name);
                exit(1);
            }
            char input[256];
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
                    printf("Erreur ligne %d: Boolean input not supported\n", yylineno);
                    free(exp);
                    exit(1);
            }
            set_symbol_value(stmt->data.read_var_name, exp);
            free(exp);
        } else if (stmt->type == WHILE_STATEMENT) {
            while (evaluate_expression(stmt->data.while_stmt.condition)->data.bool_value) {
                execute_statement_list(stmt->data.while_stmt.body);
            }
        }else if (stmt->type == FOR_STATEMENT) {
            int start = evaluate_expression(stmt->data.for_stmt.start)->data.int_value;
            int end = evaluate_expression(stmt->data.for_stmt.end)->data.int_value;
            Symbol *counter = get_symbol(stmt->data.for_stmt.counter);
            
            for (counter->value.int_val = start; counter->value.int_val <= end; counter->value.int_val++) {
                execute_statement_list(stmt->data.for_stmt.body);
            }
        } else if (stmt->type == SWITCH_STATEMENT) {
            Expression *switch_value = evaluate_expression(stmt->data.switch_stmt.value);
            CaseList *current_case = stmt->data.switch_stmt.cases;
            bool case_executed = false;

            while (current_case != NULL) {
                Expression *case_value = evaluate_expression(current_case->condition);
                if (switch_value->type == case_value->type) {
                    bool match = false;
                    switch (switch_value->type) {
                        case INTEGER:
                            match = (switch_value->data.int_value == case_value->data.int_value);
                            break;
                        case DECIMAL:
                            match = (switch_value->data.double_value == case_value->data.double_value);
                            break;
                        case STRING:
                            match = (strcmp(switch_value->data.string_value, case_value->data.string_value) == 0);
                            break;
                        case BOOLEAN:
                            match = (switch_value->data.bool_value == case_value->data.bool_value);
                            break;
                        default:
                            printf("Erreur ligne %d: Unsupported type in switch statement\n", yylineno);
                            exit(1);
                    }

                    if (match) {
                        execute_statement_list(current_case->body);
                        case_executed = true;
                        break;
                    }
                }
                current_case = current_case->next;
            }

            if (!case_executed && stmt->data.switch_stmt.default_case != NULL) {
                execute_statement_list(stmt->data.switch_stmt.default_case);
            }

            free(switch_value);
        }
        list = list->next;
    }
}
