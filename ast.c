#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"
#include "parser.tab.h"

// Global function table
#define MAX_FUNCTIONS 100
static Function *function_table[MAX_FUNCTIONS];
static int function_count = 0;

// Global variable for loop control
int loop_control = LOOP_NORMAL;

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
 * new_identifier_list - Creates a new identifier list node
 * @identifier: The identifier name to store
 * @next: Pointer to the next IdentifierList node
 *
 * Description: This function creates a new node in the identifier list,
 * which is used to store multiple variable names during declaration.
 *
 * Return: A pointer to the newly created IdentifierList node
 */
IdentifierList *new_identifier_list(char *identifier, IdentifierList *next)
{
    IdentifierList *list = malloc(sizeof(IdentifierList));
    if (!list) {
        printf("Memory allocation failed for identifier list\n");
        exit(1);
    }
    list->identifier = strdup(identifier);
    list->next = next;
    return list;
}

/**
 * add_multiple_symbols - Adds multiple symbols to the symbol table
 * @list: Pointer to the IdentifierList containing variable names
 * @type: The type to assign to all variables in the list
 *
 * Description: This function processes a list of identifiers and adds
 * each one to the symbol table with the specified type.
 */
void add_multiple_symbols(IdentifierList *list, SymbolType type)
{
    while (list != NULL) {
        add_symbol(list->identifier, type, false);
        list = list->next;
    }
}

/**
 * new_array_assign - Creates a new array assignment statement
 * @array_name: Name of the array
 * @index: First dimension index expression
 * @index1: Second dimension index expression (can be NULL for 1D arrays)
 * @value: Expression representing the value to assign
 *
 * Return: Pointer to the new Statement structure
 */
Statement *new_array_assign(char *array_name, Expression *index, Expression *index1, Expression *value)
{
    Statement *stmt = malloc(sizeof(Statement));
    if (!stmt)
    {
        printf("Memory allocation failed for array assignment\n");
        exit(1);
    }
    stmt->type = ARRAY_ASSIGN;
    stmt->data.array_assign.array_name = strdup(array_name);
    stmt->data.array_assign.index = index;
    stmt->data.array_assign.index1 = index1;
    stmt->data.array_assign.value = value;
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
 * new_elif_list - Creates a new elif branch in the elif list
 * @condition: Expression to evaluate for this branch
 * @body: Statements to execute if condition is true
 * @next: Pointer to the next elif branch (or NULL)
 *
 * Return: Pointer to new ElseIfList structure
 */
ElseIfList *new_elif_list(Expression *condition, StatementList *body, ElseIfList *next)
{
    ElseIfList *elif = malloc(sizeof(ElseIfList));
    if (!elif)
    {
        printf("Memory allocation failed for elif list\n");
        exit(1);
    }
    elif->branch.condition = condition;
    elif->branch.body = body;
    elif->next = next;
    return elif;
}

/**
 * new_if_elif - Creates a new if statement with elif branches
 * @condition: Main if condition
 * @then_branch: Statements for main if branch
 * @elif_branches: List of elif branches (can be NULL)
 * @else_branch: Statements for else branch (can be NULL)
 *
 * Return: Pointer to new Statement structure
 */
Statement *new_if_elif(Expression *condition, StatementList *then_branch,
                       ElseIfList *elif_branches, StatementList *else_branch)
{
    Statement *stmt = malloc(sizeof(Statement));
    if (!stmt)
    {
        printf("Memory allocation failed for if statement\n");
        exit(1);
    }
    stmt->type = IF_STATEMENT;
    stmt->data.if_stmt.condition = condition;
    stmt->data.if_stmt.then_branch = then_branch;
    stmt->data.if_stmt.elif_branches = elif_branches;
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
    StatementList *current = list;
    
    while (current != NULL && current->statement != NULL)
    {
        Statement *stmt = current->statement;
        
        // Check for break or continue statements first
        if (stmt->type == BREAK_STMT)
        {
            // Set the break flag and return immediately
            loop_control = LOOP_BREAK;
            return;
        }
        else if (stmt->type == CONTINUE_STMT)
        {
            // Set the continue flag and return immediately
            loop_control = LOOP_CONTINUE;
            return;
        }
        
        if (stmt->type == ASSIGN)
        {
            // Handle assignment
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

        if (stmt->type == ARRAY_ASSIGN)
        {
            Symbol *sym = get_symbol(stmt->data.array_assign.array_name);
            if (!sym || !sym->is_array)
            {
                printf("Erreur ligne %d: Invalid array: %s\n", yylineno,
                       stmt->data.array_assign.array_name);
                exit(1);
            }

            // Evaluate indices
            Expression *index_result = evaluate_expression(stmt->data.array_assign.index);
            int index = index_result->data.int_value;
            free(index_result);

            // Check first dimension bounds
            if (index < 0 || index >= sym->dimensions.sizes[0])
            {
                printf("Erreur ligne %d: Array index out of bounds\n", yylineno);
                exit(1);
            }

            // Calculate offset
            int offset = index;

            // Handle second dimension if present
            if (stmt->data.array_assign.index1)
            {
                if (sym->dimensions.num_dimensions != 2)
                {
                    printf("Erreur ligne %d: Invalid dimension access for array %s\n",
                           yylineno, stmt->data.array_assign.array_name);
                    exit(1);
                }

                Expression *index2_result = evaluate_expression(stmt->data.array_assign.index1);
                int index2 = index2_result->data.int_value;
                free(index2_result);

                if (index2 < 0 || index2 >= sym->dimensions.sizes[1])
                {
                    printf("Erreur ligne %d: Second dimension index out of bounds\n", yylineno);
                    exit(1);
                }

                offset = index * sym->dimensions.sizes[1] + index2;
            }

            // Evaluate value to assign
            Expression *value = evaluate_expression(stmt->data.array_assign.value);

            // Perform type checking and conversion if needed
            if (sym->type != value->type)
            {
                if ((sym->type == TYPE_ENTIER || sym->type == TYPE_DECIMAL) &&
                    value->type == BOOLEAN)
                {
                    value->type = INTEGER;
                    value->data.int_value = value->data.bool_value;
                }
                if (!((sym->type == TYPE_ENTIER && value->type == TYPE_DECIMAL) ||
                      (sym->type == TYPE_DECIMAL && value->type == TYPE_ENTIER)))
                {
                    printf("Erreur ligne %d: Type incompatible for array assignment\n",
                           yylineno);
                    free(value);
                    exit(1);
                }
            }

            // Assign value based on type
            switch (sym->type)
            {
            case TYPE_ENTIER:
                {
                    int *arr = (int *)sym->value.array_val;
                    arr[offset] = value->type == INTEGER ? value->data.int_value : (int)value->data.double_value;
                    break;
                }
            case TYPE_DECIMAL:
                {
                    double *arr = (double *)sym->value.array_val;
                    arr[offset] = value->type == DECIMAL ? value->data.double_value : (double)value->data.int_value;
                    break;
                }
            case TYPE_LOGIQUE:
                {
                    bool *arr = (bool *)sym->value.array_val;
                    arr[offset] = value->data.bool_value;
                    break;
                }
            case TYPE_CHAINE:
                {
                    char **arr = (char **)sym->value.array_val;
                    if (arr[offset])
                    {
                        free(arr[offset]);
                    }
                    arr[offset] = strdup(value->data.string_value);
                    break;
                }
            }

            free(value);
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
            else
            {
                bool executed = false;
                ElseIfList *elif = stmt->data.if_stmt.elif_branches;

                // Try each elif branch in order
                while (elif && !executed)
                {
                    condition = evaluate_expression(elif->branch.condition)->data.int_value;
                    if (condition)
                    {
                        execute_statement_list(elif->branch.body);
                        executed = true;
                    }
                    elif = elif->next;
                }

                // If no elif branch executed and there's an else branch
                if (!executed && stmt->data.if_stmt.else_branch)
                {
                    execute_statement_list(stmt->data.if_stmt.else_branch);
                }
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
            // Handle while statement
            while (evaluate_expression(stmt->data.while_stmt.condition)->data.bool_value)
            {
                // Execute the loop body
                execute_statement_list(stmt->data.while_stmt.body);
                
                // Check if break was encountered
                if (loop_control == LOOP_BREAK)
                {
                    loop_control = LOOP_NORMAL;  // Reset for next time
                    break;
                }
                
                // Check if continue was encountered
                if (loop_control == LOOP_CONTINUE)
                {
                    loop_control = LOOP_NORMAL;  // Reset for next time
                    continue;
                }
            }
        }
        else if (stmt->type == FOR_STATEMENT)
        {
            // Handle for statement
            Expression *start_expr = evaluate_expression(stmt->data.for_stmt.start);
            Expression *end_expr = evaluate_expression(stmt->data.for_stmt.end);
            int start = start_expr->data.int_value;
            int end = end_expr->data.int_value;
            free(start_expr);
            free(end_expr);

            // First, create a temporary expression for the counter variable
            Expression *counter_var = new_variable(stmt->data.for_stmt.counter);

            // Execute loop for each value in range
            for (int i = start; i <= end; i++)
            {
                // Create an integer expression for current loop value
                Expression *current_value = new_integer(i);

                // Update the counter variable with current value
                set_symbol_value(stmt->data.for_stmt.counter, current_value);
                free(current_value);

                // Reset loop control flag before executing the body
                loop_control = LOOP_NORMAL;
                
                // Execute loop body
                execute_statement_list(stmt->data.for_stmt.body);
                
                // Check if break was encountered
                if (loop_control == LOOP_BREAK)
                {
                    loop_control = LOOP_NORMAL;  // Reset for next time
                    break;
                }
                
                // Check if continue was encountered
                if (loop_control == LOOP_CONTINUE)
                {
                    loop_control = LOOP_NORMAL;  // Reset for next time
                    continue;
                }
            }

            free(counter_var);
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
                        
                        // Check if break or continue was encountered
                        if (loop_control != LOOP_NORMAL)
                            return;
                    }
                }
                current_case = current_case->next;
            }

            if (!case_executed && stmt->data.switch_stmt.default_case != NULL)
            {
                execute_statement_list(stmt->data.switch_stmt.default_case);
                
                // Check if break or continue was encountered
                if (loop_control != LOOP_NORMAL)
                    return;
            }

            free(switch_value);
        }
        else if (stmt->type == ARRAY_DECL)
        {
            execute_array_declaration(stmt);
        }
        else if (stmt->type == FUNCTION_CALL)
        {
            Expression *result = evaluate_function_call(stmt->data.function_call.name, stmt->data.function_call.arguments);
            free(result);
        }
        else if (stmt->type == RETURN_STMT)
        {
            Expression *value = evaluate_expression(stmt->data.return_stmt.value);
            set_return_value(value);
            // Don't free the value here as it will be used by the caller
            return;  // Exit function execution after return
        }
        // Check if a return value has been set (by a nested function call)
        if (get_return_value() != NULL)
        {
            // A return has occurred in a nested function call, so we should stop executing
            return;
        }
        
        // Move to the next statement
        current = current->next;
        
        // Check if we need to break out of the loop due to control flow
        if (loop_control != LOOP_NORMAL)
        {
            return;
        }
    }
}

/**
 * evaluate_function_call - Evaluates a function call and returns its result
 * @name: Name of the function to call
 * @arguments: List of argument expressions
 *
 * Return: Expression containing the function's return value
 */
Expression *evaluate_function_call(const char *name, ExpressionList *arguments) {
    Function *func = get_function(name);
    if (!func) {
        printf("Erreur ligne %d: La fonction '%s' n'existe pas\n", yylineno, name);
        exit(1);
    }

    // Create a new scope for function parameters
    push_scope();

    // Bind arguments to parameters
    Parameter *param = func->parameters;
    ExpressionList *arg = arguments;
    while (param && arg) {
        Expression *value = evaluate_expression(arg->expression);
        add_symbol(param->name, param->type, false);
        set_symbol_value(param->name, value);
        free(value); // Free the evaluated expression after setting the symbol value
        param = param->next;
        arg = arg->next;
    }

    if (param || arg) {
        printf("Erreur ligne %d: Nombre incorrect de paramètres pour la fonction '%s'\n", 
               yylineno, name);
        exit(1);
    }

    // Reset return value before executing function body
    clear_return_value();
    
    // Execute function declarations
    execute_statement_list(func->declarations);
    
    // Execute function body
    execute_statement_list(func->body);

    // Get return value
    Expression *result = get_and_clear_return_value();
    if (!result && func->return_type != TYPE_VOID) {
        printf("Erreur ligne %d: La fonction '%s' doit retourner une valeur\n", 
               yylineno, name);
        exit(1);
    }

    // Make a copy of the result before popping the scope
    Expression *result_copy = NULL;
    if (result) {
        result_copy = malloc(sizeof(Expression));
        if (!result_copy) {
            printf("Erreur: Échec de l'allocation mémoire pour la valeur de retour\n");
            exit(1);
        }
        memcpy(result_copy, result, sizeof(Expression));
        
        // For string values, make a deep copy
        if (result->type == TYPE_CHAINE && result->data.string_value) {
            result_copy->data.string_value = strdup(result->data.string_value);
        }
        
        // Free the original result
        free(result);
    }

    // Restore previous scope
    pop_scope();

    return result_copy;
}

// Global variable to store return value
static Expression *return_value = NULL;

/**
 * get_return_value - Gets the current return value without clearing it
 *
 * Return: The current return value, or NULL if none
 */
Expression *get_return_value(void) {
    return return_value;
}

/**
 * get_and_clear_return_value - Gets and clears the current return value
 *
 * Return: The current return value, or NULL if none
 */
Expression *get_and_clear_return_value(void) {
    Expression *result = return_value;
    return_value = NULL;
    return result;
}

/**
 * set_return_value - Sets the return value from a return statement
 * @value: The value to return
 */
void set_return_value(Expression *value) {
    return_value = value;
}

/**
 * clear_return_value - Clears the current return value
 */
void clear_return_value(void) {
    if (return_value) {
        free(return_value);
        return_value = NULL;
    }
}

/**
 * new_parameter - Creates a new function parameter
 * @name: Name of the parameter
 * @type: Type of the parameter
 * @next: Next parameter in the list
 *
 * Return: Pointer to the new Parameter structure
 */
Parameter *new_parameter(char *name, SymbolType type, Parameter *next) {
    Parameter *param = malloc(sizeof(Parameter));
    if (!param) {
        printf("Erreur ligne %d: Échec de l'allocation mémoire pour le paramètre\n", yylineno);
        exit(1);
    }
    param->name = strdup(name);
    param->type = type;
    param->next = next;
    return param;
}

/**
 * new_function - Creates a new function definition
 * @name: Function name
 * @params: List of parameters
 * @return_type: Return type of the function
 * @decls: Local variable declarations
 * @body: Function body statements
 *
 * Return: Pointer to the new Function structure
 */
Function *new_function(char *name, Parameter *params, SymbolType return_type, 
                      StatementList *decls, StatementList *body) {
    Function *func = malloc(sizeof(Function));
    if (!func) {
        printf("Erreur ligne %d: Échec de l'allocation mémoire pour la fonction\n", yylineno);
        exit(1);
    }
    func->name = strdup(name);
    func->parameters = params;
    func->return_type = return_type;
    func->declarations = decls;
    func->body = body;
    return func;
}

/**
 * new_function_decl - Creates a new function declaration statement
 * @function: Function to declare
 *
 * Return: Pointer to the new Statement structure
 */
Statement *new_function_decl(Function *function) {
    Statement *stmt = malloc(sizeof(Statement));
    if (!stmt) {
        printf("Erreur ligne %d: Échec de l'allocation mémoire pour la déclaration de fonction\n", yylineno);
        exit(1);
    }
    stmt->type = FUNCTION_DECL;
    stmt->data.function_decl.function = function;
    return stmt;
}

/**
 * new_function_call - Creates a new function call statement
 * @name: Name of the function to call
 * @arguments: List of argument expressions
 *
 * Return: Pointer to the new Statement structure
 */
Statement *new_function_call(char *name, ExpressionList *arguments) {
    Statement *stmt = malloc(sizeof(Statement));
    if (!stmt) {
        printf("Erreur ligne %d: Échec de l'allocation mémoire pour l'appel de fonction\n", yylineno);
        exit(1);
    }
    stmt->type = FUNCTION_CALL;
    stmt->data.function_call.name = strdup(name);
    stmt->data.function_call.arguments = arguments;
    return stmt;
}

/**
 * new_return - Creates a new return statement
 * @value: Expression to return
 *
 * Return: Pointer to the new Statement structure
 */
Statement *new_return(Expression *value) {
    Statement *stmt = malloc(sizeof(Statement));
    if (!stmt) {
        printf("Erreur ligne %d: Échec de l'allocation mémoire pour l'instruction de retour\n", yylineno);
        exit(1);
    }
    stmt->type = RETURN_STMT;
    stmt->data.return_stmt.value = value;
    return stmt;
}

/**
 * add_function - Adds a function to the function table
 * @function: Function to add
 */
void add_function(Function *function) {
    if (function_count >= MAX_FUNCTIONS) {
        printf("Nombre maximum de fonctions atteint\n");
        exit(1);
    }
    if (get_function(function->name) != NULL) {
        printf("Fonction %s déjà définie\n", function->name);
        exit(1);
    }
    function_table[function_count++] = function;
}

/**
 * get_function - Retrieves a function from the function table
 * @name: Name of the function to retrieve
 *
 * Return: Pointer to the Function structure, or NULL if not found
 */
Function *get_function(const char *name) {
    for (int i = 0; i < function_count; i++) {
        if (strcmp(function_table[i]->name, name) == 0) {
            return function_table[i];
        }
    }
    return NULL;
}

/**
 * new_function_statement - Creates a new statement node for a function
 * @function: The function to wrap in a statement
 *
 * Return: A pointer to the new Statement structure
 */
Statement *new_function_statement(Function *function) {
    Statement *stmt = malloc(sizeof(Statement));
    if (!stmt) {
        printf("Memory allocation failed for function statement\n");
        exit(1);
    }
    stmt->type = FUNCTION_DECL;
    stmt->data.function_decl.function = function;
    return stmt;
}

/**
 * new_break - Creates a new break statement
 *
 * Description: This function allocates and initializes a new Statement structure
 * representing a break statement, which exits the innermost loop when executed.
 *
 * Return: Pointer to the newly created Statement structure
 */
Statement *new_break()
{
    Statement *stmt = malloc(sizeof(Statement));
    if (!stmt)
    {
        printf("Memory allocation failed for break statement\n");
        exit(1);
    }
    stmt->type = BREAK_STMT;
    return stmt;
}

/**
 * new_continue - Creates a new continue statement
 *
 * Description: This function allocates and initializes a new Statement structure
 * representing a continue statement, which skips to the next iteration of the
 * innermost loop when executed.
 *
 * Return: Pointer to the newly created Statement structure
 */
Statement *new_continue()
{
    Statement *stmt = malloc(sizeof(Statement));
    if (!stmt)
    {
        printf("Memory allocation failed for continue statement\n");
        exit(1);
    }
    stmt->type = CONTINUE_STMT;
    return stmt;
}
