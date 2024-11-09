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
StatementList *new_statement_list(Statement *statement, StatementList *next)
{
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
Statement *new_assign(char *var_name, Expression *value)
{
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
Statement *new_print(ExpressionList *exprs)
{
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = PRINT;
    stmt->data.print_exprs = exprs;
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
Statement *new_if(Expression *condition, StatementList *then_branch, StatementList *else_branch)
{
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
Statement *new_read(char *var_name)
{
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = READ;
    stmt->data.read_var_name = strdup(var_name);
    return stmt;
}

/**
 * new_while - Creates a new while loop statement
 * @condition: Pointer to the Expression representing the loop condition
 * @body: Pointer to the StatementList containing the loop body
 *
 * Description: This function allocates and initializes a new Statement structure
 * representing a while loop. The loop continues executing the body statements
 * as long as the condition evaluates to true.
 *
 * Return: Pointer to the newly created Statement structure
 *         NULL if memory allocation fails
 */
Statement *new_while(Expression *condition, StatementList *body)
{
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = WHILE_STATEMENT;
    stmt->data.while_stmt.condition = condition;
    stmt->data.while_stmt.body = body;
    return stmt;
}

/**
 * new_for - Creates a new for loop statement
 * @counter: String containing the loop counter variable name
 * @start: Pointer to Expression representing the initial counter value
 * @end: Pointer to Expression representing the final counter value
 * @body: Pointer to StatementList containing the loop body
 *
 * Description: This function allocates and initializes a new Statement structure
 * representing a for loop. The loop iterates from the start value to the end value,
 * using the specified counter variable, executing the body statements in each iteration.
 *
 * Return: Pointer to the newly created Statement structure
 *         NULL if memory allocation fails
 */
Statement *new_for(char *counter, Expression *start, Expression *end, StatementList *body)
{
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = FOR_STATEMENT;
    stmt->data.for_stmt.counter = strdup(counter);
    stmt->data.for_stmt.start = start;
    stmt->data.for_stmt.end = end;
    stmt->data.for_stmt.body = body;
    return stmt;
}

/**
 * new_switch - Creates a new switch statement
 * @value: Pointer to Expression representing the switch value to match
 * @cases: Pointer to CaseList containing the switch cases
 * @default_case: Pointer to StatementList for the default case (can be NULL)
 *
 * Description: This function allocates and initializes a new Statement structure
 * representing a switch statement. It includes the value to match against,
 * a list of cases with their corresponding statements, and an optional default case.
 *
 * Return: Pointer to the newly created Statement structure
 *         NULL if memory allocation fails
 */
Statement *new_switch(Expression *value, CaseList *cases, StatementList *default_case)
{
    Statement *stmt = malloc(sizeof(Statement));
    stmt->type = SWITCH_STATEMENT;
    stmt->data.switch_stmt.value = value;
    stmt->data.switch_stmt.cases = cases;
    stmt->data.switch_stmt.default_case = default_case;
    return stmt;
}

/**
 * new_case_list - Creates a new case entry in a switch statement
 * @condition: Pointer to Expression representing the case value to match
 * @body: Pointer to StatementList containing statements to execute for this case
 * @next: Pointer to the next CaseList node in the switch statement
 *
 * Description: This function allocates and initializes a new CaseList structure
 * representing a case in a switch statement. It creates a linked list node
 * containing the case condition, its corresponding statements, and a link
 * to the next case.
 *
 * Return: Pointer to the newly created CaseList structure
 *         NULL if memory allocation fails
 */
CaseList *new_case_list(Expression *condition, StatementList *body, CaseList *next)
{
    CaseList *case_list = malloc(sizeof(CaseList));
    case_list->condition = condition;
    case_list->body = body;
    case_list->next = next;
    return case_list;
}

/**
 * execute_array_declaration - Processes and executes an array declaration statement
 * @stmt: Pointer to the Statement structure containing array declaration information
 *
 * Description: This function handles the execution of array declarations in the
 * program. It validates the array dimensions, ensures the array name isn't already
 * in use, and creates the array symbol in the symbol table. It performs necessary
 * error checking for array dimensions and memory allocation.
 *
 * Return: void
 *
 * Error conditions:
 * - Exits with error if the statement type is invalid
 * - Exits with error if array dimensions are not positive
 * - Exits with error if the array name is already declared
 * - Exits with error if memory allocation fails
 */
void execute_array_declaration(Statement *stmt)
{
    if (stmt->type != ARRAY_DECL)
    {
        printf("Erreur ligne %d: Type de déclaration invalide\n", yylineno);
        exit(1);
    }

    // Validate dimensions
    for (int i = 0; i < stmt->data.array_decl.dimensions.num_dimensions; i++)
    {
        if (stmt->data.array_decl.dimensions.sizes[i] <= 0)
        {
            printf("Erreur ligne %d: La dimension du tableau doit être positive\n", yylineno);
            exit(1);
        }
    }

    // Check if symbol already exists
    if (get_symbol(stmt->data.array_decl.array_name) != NULL)
    {
        printf("Erreur ligne %d: Variable %s Variable déjà déclarée\n",
               yylineno, stmt->data.array_decl.array_name);
        exit(1);
    }

    // Add array symbol to symbol table
    add_array_symbol(
        stmt->data.array_decl.array_name,
        stmt->data.array_decl.element_type,
        stmt->data.array_decl.dimensions);
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
void execute_statement_list(StatementList *list)
{
    int statement_count = 0;
    while (list)
    {
        statement_count++;
        Statement *stmt = list->statement;
        if (stmt->type == ASSIGN)
        {
            if (stmt->data.assign.value->type == ARRAY_ACCESS)
            {
                // Handle array to array assignment
                Expression *result = evaluate_expression(stmt->data.assign.value);
                set_symbol_value(stmt->data.assign.var_name, result);
                free(result);
            }
            else if (stmt->data.assign.var_name && strchr(stmt->data.assign.var_name, '['))
            {
                // This is an array element assignment
                char *array_name = strdup(stmt->data.assign.var_name);
                char *bracket = strchr(array_name, '[');
                *bracket = '\0'; // Split the string at the first bracket

                Symbol *sym = get_symbol(array_name);
                if (!sym || !sym->is_array)
                {
                    printf("Erreur ligne %d: Affectation de tableau invalide\n", yylineno);
                    free(array_name);
                    exit(1);
                }

                // Parse the index expressions from the assignment target
                char *index_str = bracket + 1; // Skip the '['
                char *end_bracket = strchr(index_str, ']');
                if (!end_bracket)
                {
                    printf("Erreur ligne %d: Accès au tableau malformé\n", yylineno);
                    free(array_name);
                    exit(1);
                }

                *end_bracket = '\0'; // Temporarily terminate the first index
                Expression *index1 = new_integer(atoi(index_str));

                Expression *index2 = NULL;
                if (sym->dimensions.num_dimensions > 1)
                {
                    char *second_bracket = strchr(end_bracket + 1, '[');
                    if (second_bracket)
                    {
                        char *second_index = second_bracket + 1;
                        char *second_end = strchr(second_index, ']');
                        if (!second_end)
                        {
                            printf("Erreur ligne %d: Accès à un tableau 2D mal formé\n", yylineno);
                            free(array_name);
                            free(index1);
                            exit(1);
                        }
                        *second_end = '\0';
                        index2 = new_integer(atoi(second_index));
                    }
                }

                // Create the array access expression
                Expression *array_access = new_array_access(array_name, index1, index2);

                Expression *value = evaluate_expression(stmt->data.assign.value);
                set_array_element(array_name, array_access, value);

                // Clean up
                free(array_name);
                free(array_access);
                free(value);
            }
            else
            {
                Symbol *sym = get_symbol(stmt->data.assign.var_name);
                if (!sym)
                {
                    printf("Variable non définie: %s\n", stmt->data.assign.var_name);
                    exit(1);
                }
                if (sym->is_constant)
                {
                    printf("Erreur ligne %d : La réaffectation de la variable constante %s n'est pas autorisée\n", yylineno, stmt->data.assign.var_name);
                    exit(1);
                }
                Expression *result = evaluate_expression(stmt->data.assign.value);
                if (sym->type != result->type)
                {
                    if ((sym->type == TYPE_ENTIER || sym->type == DECIMAL) && result->type == BOOLEAN)
                    {
                        result->type = INTEGER;
                        result->data.int_value = result->data.bool_value;
                    }
                    if (!((sym->type == TYPE_ENTIER && result->type == TYPE_DECIMAL) || (sym->type == TYPE_DECIMAL && result->type == TYPE_ENTIER)))
                    {
                        printf("Erreur ligne %d : Type incompatible pour l'affectation à la variable %s\n", yylineno, stmt->data.assign.var_name);
                        exit(1);
                    }
                }
                set_symbol_value(stmt->data.assign.var_name, result);
                free(result);
            }
        }
        else if (stmt->type == PRINT)
        {
            ExpressionList *expr_list = stmt->data.print_exprs;

            while (expr_list)
            {
                Expression *print_expr = evaluate_expression(expr_list->expression);

                switch (print_expr->type)
                {
                case INTEGER:
                    printf("%d", print_expr->data.int_value);
                    break;
                case DECIMAL:
                    printf("%f", print_expr->data.double_value);
                    break;
                case STRING:
                    printf("%s", print_expr->data.string_value);
                    break;
                case TYPE_LOGIQUE:
                    printf("%s", print_expr->data.bool_value ? "Vrai" : "Faux");
                    break;
                default:
                    break;
                }
                expr_list = expr_list->next;
            }
        }
        else if (stmt->type == IF_STATEMENT)
        {
            int condition = evaluate_expression(stmt->data.if_stmt.condition)->data.int_value;
            if (condition)
            {
                execute_statement_list(stmt->data.if_stmt.then_branch);
            }
            else if (stmt->data.if_stmt.else_branch)
            {
                execute_statement_list(stmt->data.if_stmt.else_branch);
            }
        }
        else if (stmt->type == READ)
        {
            Symbol *sym = get_symbol(stmt->data.read_var_name);
            if (!sym)
            {
                printf("Erreur ligne %d: Variable non définie: %s\n", yylineno, stmt->data.read_var_name);
                exit(1);
            }
            char input[256];
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0; // Remove newline

            Expression *exp = malloc(sizeof(Expression));
            switch (sym->type)
            {
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
                printf("Erreur ligne %d: Entrée booléenne non prise en charge\n", yylineno);
                free(exp);
                exit(1);
            }
            set_symbol_value(stmt->data.read_var_name, exp);
            free(exp);
        }
        else if (stmt->type == WHILE_STATEMENT)
        {
            while (evaluate_expression(stmt->data.while_stmt.condition)->data.bool_value)
            {
                execute_statement_list(stmt->data.while_stmt.body);
            }
        }
        else if (stmt->type == FOR_STATEMENT)
        {
            int start = evaluate_expression(stmt->data.for_stmt.start)->data.int_value;
            int end = evaluate_expression(stmt->data.for_stmt.end)->data.int_value;
            Symbol *counter = get_symbol(stmt->data.for_stmt.counter);

            for (counter->value.int_val = start; counter->value.int_val <= end; counter->value.int_val++)
            {
                execute_statement_list(stmt->data.for_stmt.body);
            }
        }
        else if (stmt->type == SWITCH_STATEMENT)
        {
            Expression *switch_value = evaluate_expression(stmt->data.switch_stmt.value);
            CaseList *current_case = stmt->data.switch_stmt.cases;
            bool case_executed = false;

            while (current_case != NULL)
            {
                Expression *case_value = evaluate_expression(current_case->condition);
                if (switch_value->type == case_value->type)
                {
                    bool match = false;
                    switch (switch_value->type)
                    {
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
                        printf("Erreur ligne %d: Type non pris en charge dans l'instruction switch\n", yylineno);
                        exit(1);
                    }

                    if (match)
                    {
                        execute_statement_list(current_case->body);
                        case_executed = true;
                        break;
                    }
                }
                current_case = current_case->next;
            }

            if (!case_executed && stmt->data.switch_stmt.default_case != NULL)
            {
                execute_statement_list(stmt->data.switch_stmt.default_case);
            }

            free(switch_value);
        }
        else if (stmt->type == ARRAY_DECL)
        {
            execute_array_declaration(stmt);
        }
        list = list->next;
    }
}
