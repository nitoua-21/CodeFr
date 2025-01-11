#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "ast.h"

/**
 * new_integer - Creates a new integer expression
 * @value: The integer value for the expression
 *
 * This function allocates and initializes a new Expression
 * structure representing an integer value.
 *
 * Return: A pointer to the newly created Expression
 */
Expression *new_integer(int value)
{
    Expression *expr = malloc(sizeof(Expression));
    expr->type = INTEGER;
    expr->data.int_value = value;
    return expr;
}

/**
 * new_decimal - Creates a new decimal expression
 * @value: The decimal value for the expression
 *
 * This function allocates and initializes a new Expression
 * structure representing a decimal (double) value.
 *
 * Return: A pointer to the newly created Expression
 */
Expression *new_decimal(double value)
{
    Expression *expr = malloc(sizeof(Expression));
    expr->type = DECIMAL;
    expr->data.double_value = value;
    return expr;
}

/**
 * new_variable - Creates a new variable expression
 * @var_name: The name of the variable
 *
 * This function allocates and initializes a new Expression
 * structure representing a variable, identified by its name.
 *
 * Return: A pointer to the newly created Expression
 */
Expression *new_variable(char *var_name)
{
    Expression *expr = malloc(sizeof(Expression));
    expr->type = VARIABLE;
    expr->data.var_name = strdup(var_name);
    return expr;
}

/**
 * new_string - Creates a new string expression
 * @string_value: The string value for the expression
 *
 * This function allocates and initializes a new Expression
 * structure representing a string value.
 *
 * Return: A pointer to the newly created Expression
 */

Expression *new_string(char *string_value)
{
    Expression *expr = malloc(sizeof(Expression));
    expr->type = STRING;
    expr->data.string_value = strdup(string_value);
    return expr;
}

/**
 * new_binary_op - Creates a new binary operation expression
 * @op: The operator character for the binary operation
 * @left: Pointer to the left operand Expression
 * @right: Pointer to the right operand Expression
 *
 * This function allocates and initializes a new Expression
 * structure representing a binary operation with two operands.
 *
 * Return: A pointer to the newly created Expression
 */
Expression *new_binary_op(char op, Expression *left, Expression *right)
{
    Expression *expr = malloc(sizeof(Expression));
    expr->type = BINARY_OP;
    expr->data.binary_op.op = op;
    expr->data.binary_op.left = left;
    expr->data.binary_op.right = right;
    return expr;
}

/**
 * new_boolean - Creates a new boolean expression
 * @value: The boolean value for the expression
 *
 * This function allocates and initializes a new Expression
 * structure representing a boolean value.
 *
 * Return: A pointer to the newly created Expression
 */
Expression *new_boolean(bool value)
{
    Expression *expr = malloc(sizeof(Expression));
    expr->type = BOOLEAN;
    expr->data.bool_value = value;
    return expr;
}

/**
 * new_unary_op - Creates a new unary operation expression
 * @op: The operator character for the unary operation
 * @operand: Pointer to the operand Expression
 *
 * This function allocates and initializes a new Expression
 * structure representing a unary operation with one operand.
 *
 * Return: A pointer to the newly created Expression
 */
Expression *new_unary_op(char op, Expression *operand)
{
    Expression *expr = malloc(sizeof(Expression));
    expr->type = UNARY_OP;
    expr->data.unary_op.op = op;
    expr->data.unary_op.operand = operand;
    return expr;
}

Expression *new_function_expression(char *name, ExpressionList *arguments) {
    Expression *expr = malloc(sizeof(Expression));
    expr->type = FUNCTION;
    expr->data.function_call.name = strdup(name);
    expr->data.function_call.arguments = arguments;
    return expr;
}

/**
 * new_expression_list - Creates a new node in the expression linked list
 * @expression: Pointer to the Expression to be stored in the new node
 * @next: Pointer to the next ExpressionList node
 *
 * Description: This function allocates memory for a new ExpressionList node
 * and initializes it with the given expression and next pointer. It's used
 * to build a linked list of expressions, commonly used for handling multiple
 * expressions in print statements or function arguments.
 *
 * Return: Pointer to the newly created ExpressionList node, or NULL if
 *         memory allocation fails
 */
ExpressionList *new_expression_list(Expression *expression, ExpressionList *next)
{
    ExpressionList *list = malloc(sizeof(ExpressionList));
    if (!list) {
        printf("Erreur ligne %d: Échec de l'allocation mémoire pour la liste d'expressions\n", yylineno);
        exit(1);
    }
    list->expression = expression;
    list->next = next;
    return list;
}

/**
 * evaluate_expression - Evaluates an expression
 * @expr: Pointer to the Expression to evaluate
 *
 * This function recursively evaluates an Expression structure,
 * performing the necessary operations based on the expression type.
 *
 * Return: A pointer to a new Expression containing the result of the evaluation
 */
Expression *evaluate_expression(Expression *expr)
{
    if (expr == NULL)
    {
        return NULL;
    }

    Expression *new_expr = malloc(sizeof(Expression));
    if (!new_expr) {
        printf("Erreur ligne %d: Échec de l'allocation mémoire pour l'expression\n", yylineno);
        exit(1);
    }

    switch (expr->type)
    {
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
        if (new_expr->data.string_value == NULL)
        {
            printf("Erreur ligne %d: Échec de l'allocation mémoire pour la chaîne\n", yylineno);
            free(new_expr);
            exit(1);
        }
        break;
    case BOOLEAN:
        new_expr->type = BOOLEAN;
        new_expr->data.bool_value = expr->data.bool_value;
        break;
    case VARIABLE:
    {
        Symbol *sym = get_symbol(expr->data.var_name);
        if (!sym)
        {
            printf("Erreur ligne %d: Variable non définie: %s\n", yylineno, expr->data.var_name);
            free(new_expr);
            exit(1);
        }
        switch (sym->type)
        {
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
            if (new_expr->data.string_value == NULL)
            {
                printf("Erreur ligne %d: Échec de l'allocation mémoire pour la chaîne\n", yylineno);
                free(new_expr);
                exit(1);
            }
            break;
        case TYPE_LOGIQUE:
            new_expr->type = BOOLEAN;
            new_expr->data.bool_value = sym->value.bool_val;
            break;
        }
    }
    break;

    case BINARY_OP:
    {
        Expression *left = evaluate_expression(expr->data.binary_op.left);
        Expression *right = evaluate_expression(expr->data.binary_op.right);

        double lvalue, rvalue;

        bool isint = (left->type == INTEGER && right->type == INTEGER) || (left->type == BOOLEAN && right->type == BOOLEAN);
        bool isnumber = (left->type == INTEGER || left->type == DECIMAL || left->type == BOOLEAN) && (right->type == INTEGER || right->type == DECIMAL || right->type == BOOLEAN);
        bool isstring = left->type == STRING && right->type == STRING;

        if (isint || isnumber)
        {
            lvalue = left->type == DECIMAL ? left->data.double_value : left->data.int_value;
            rvalue = right->type == DECIMAL ? right->data.double_value : right->data.int_value;
        }

        switch (expr->data.binary_op.op)
        {
        case '+':
            if (isint)
            {
                new_expr->type = INTEGER;
                new_expr->data.int_value = (int)(lvalue + rvalue);
            }
            else if (isnumber)
            {
                new_expr->type = DECIMAL;
                new_expr->data.double_value = lvalue + rvalue;
            }
            else if (isstring)
            {
                new_expr->type = STRING;
                char *result = malloc(strlen(left->data.string_value) + 
                                   strlen(right->data.string_value) + 1);
                if (!result) {
                    printf("Erreur ligne %d: Échec de l'allocation mémoire pour la concaténation\n", yylineno);
                    exit(1);
                }
                strcpy(result, left->data.string_value);
                strcat(result, right->data.string_value);
                new_expr->data.string_value = result;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'addition\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case '-':
            if (isint)
            {
                new_expr->type = INTEGER;
                new_expr->data.int_value = (int)(lvalue - rvalue);
            }
            else if (isnumber)
            {
                new_expr->type = DECIMAL;
                new_expr->data.double_value = lvalue - rvalue;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour la soustraction\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case '*':
            if (isint)
            {
                new_expr->type = INTEGER;
                new_expr->data.int_value = (int)(lvalue * rvalue);
            }
            else if (isnumber)
            {
                new_expr->type = DECIMAL;
                new_expr->data.double_value = lvalue * rvalue;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour la multiplication\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case '/':
            if (isnumber)
            {
                if (((rvalue == 0)))
                {
                    printf("Erreur ligne %d: Division par zéro\n", yylineno);
                    free(left);
                    free(right);
                    free(new_expr);
                    exit(1);
                }
                new_expr->type = DECIMAL;
                new_expr->data.double_value = lvalue / rvalue;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour la division\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case 'P':
            if (isint)
            {
                new_expr->type = INTEGER;
                new_expr->data.int_value = (int)pow(lvalue, rvalue);
            }
            else if (isnumber)
            {
                new_expr->type = DECIMAL;
                new_expr->data.double_value = pow(lvalue, rvalue);
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour la puissance\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case 'M':
            if (isint)
            {
                new_expr->type = INTEGER;
                new_expr->data.int_value = (int)lvalue % (int)rvalue;
            }
            else if (isnumber)
            {
                new_expr->type = DECIMAL;
                new_expr->data.double_value = (int)lvalue % (int)rvalue;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour le modulo\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case 'C': // CONCAT
            if (isstring)
            {
                new_expr->type = STRING;
                char *result = malloc(strlen(left->data.string_value) + 
                                   strlen(right->data.string_value) + 1);
                if (!result) {
                    printf("Erreur ligne %d: Échec de l'allocation mémoire pour la concaténation\n", yylineno);
                    exit(1);
                }
                strcpy(result, left->data.string_value);
                strcat(result, right->data.string_value);
                new_expr->data.string_value = result;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour la concaténation\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case '&': // AND
            if (isnumber)
            {
                new_expr->type = BOOLEAN;
                new_expr->data.bool_value = lvalue && rvalue;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération ET\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case '|': // OR
            if (isnumber)
            {
                new_expr->type = BOOLEAN;
                new_expr->data.bool_value = lvalue || rvalue;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération OU\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case '^': // XOR
            if (isnumber)
            {
                new_expr->type = BOOLEAN;
                new_expr->data.bool_value = lvalue != rvalue;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération XOR\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case '<':
            if (isnumber)
            {
                new_expr->type = BOOLEAN;
                new_expr->data.bool_value = lvalue < rvalue;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération <\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case '>':
            if (isnumber)
            {
                new_expr->type = BOOLEAN;
                new_expr->data.bool_value = lvalue > rvalue;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération >\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case 'L': // <=
            if (isnumber)
            {
                new_expr->type = BOOLEAN;
                new_expr->data.bool_value = lvalue <= rvalue;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération <=\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case 'G': // >=
            if (isnumber)
            {
                new_expr->type = BOOLEAN;
                new_expr->data.bool_value = lvalue >= rvalue;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération >=\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case '=': // ==
            if (isnumber)
            {
                new_expr->type = BOOLEAN;
                new_expr->data.bool_value = lvalue == rvalue;
            }
            else if (isstring)
            {
                new_expr->type = BOOLEAN;
                new_expr->data.bool_value = strcmp(left->data.string_value, right->data.string_value) == 0;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération ==\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case '!': // !=
            if (isnumber)
            {
                new_expr->type = BOOLEAN;
                new_expr->data.bool_value = lvalue != rvalue;
            }
            else if (isstring)
            {
                new_expr->type = BOOLEAN;
                new_expr->data.bool_value = strcmp(left->data.string_value, right->data.string_value) != 0;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération !=\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case 'A': // Alea(x, n)
            srand(time(0));
            new_expr->type = DECIMAL;
            if (isnumber)
            {
                int min = left->type == INTEGER ? (int)left->data.int_value : (int)left->data.double_value;
                int max = right->type == INTEGER ? (int)right->data.int_value : (int)right->data.double_value;

                new_expr->data.double_value = rand() % (max - min + 1) + min;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération Alea\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case 'p': // Comparer(x, n)
            srand(time(0));
            new_expr->type = INTEGER;
            if (left->type == STRING && right->type == STRING)
            {
                new_expr->data.int_value = strcmp(left->data.string_value, right->data.string_value);
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération Comparer\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        case 'r': // Recherche(s1, s2)
            new_expr->type = INTEGER;
            if (left->type == STRING && right->type == STRING)
            {
                int pos = 0;

                char *result = strstr(left->data.string_value, right->data.string_value);

                if (result != NULL)
                    pos = (int)(result - left->data.string_value + 1);

                new_expr->data.int_value = pos;
            }
            else
            {
                printf("Erreur ligne %d: Types incompatibles pour l'opération Recherche\n", yylineno);
                free(left);
                free(right);
                free(new_expr);
                exit(1);
            }
            break;
        default:
            printf("Erreur ligne %d: Opérateur binaire inconnu\n", yylineno);
            free(left);
            free(right);
            free(new_expr);
            exit(1);
        }
        free(left);
        free(right);
    }
    break;
    case UNARY_OP:
    {
        Expression *exp = evaluate_expression(expr->data.unary_op.operand);

        bool isnumber = exp->type == INTEGER || exp->type == DECIMAL || exp->type == BOOLEAN;

        if (exp->type == BOOLEAN)
        {
            exp->type = INTEGER;
            exp->data.int_value = exp->data.bool_value;
        }

        switch (expr->data.unary_op.op)
        {
        case 'R':
            if (!isnumber)
            {
                printf("Erreur ligne %d: Type invalide pour la racine carrée\n", yylineno);
                free(new_expr);
                free(exp);
                exit(1);
            }
            new_expr->type = DECIMAL;
            new_expr->data.double_value = exp->type == INTEGER ? sqrt(exp->data.int_value) : sqrt(exp->data.double_value);
            break;

        case 'S':
            if (!isnumber)
            {
                printf("Erreur ligne %d: Type invalide pour le sinus\n", yylineno);
                free(new_expr);
                free(exp);
                exit(1);
            }
            new_expr->type = DECIMAL;
            new_expr->data.double_value = exp->type == INTEGER ? sin(exp->data.int_value) : sin(exp->data.double_value);
            break;
        case 'C':
            if (!isnumber)
            {
                printf("Erreur ligne %d: Type invalide pour le cosinus\n", yylineno);
                free(new_expr);
                free(exp);
                exit(1);
            }
            new_expr->type = DECIMAL;
            new_expr->data.double_value = exp->type == INTEGER ? cos(exp->data.int_value) : cos(exp->data.double_value);
            break;
        case 'T':
            if (!isnumber)
            {
                printf("Erreur ligne %d: Type invalide pour la tangente\n", yylineno);
                free(new_expr);
                free(exp);
                exit(1);
            }
            new_expr->type = DECIMAL;
            new_expr->data.double_value = exp->type == INTEGER ? tan(exp->data.int_value) : tan(exp->data.double_value);
            break;
        case 'L':
            if (!isnumber)
            {
                printf("Erreur ligne %d: Type invalide pour le logarithme\n", yylineno);
                free(new_expr);
                free(exp);
                exit(1);
            }
            new_expr->type = DECIMAL;
            new_expr->data.double_value = exp->type == INTEGER ? log(exp->data.int_value) : log(exp->data.double_value);
            break;
        case 'l':
            if (!isnumber)
            {
                printf("Erreur ligne %d: Type invalide pour le logarithme décimal\n", yylineno);
                free(new_expr);
                free(exp);
                exit(1);
            }
            new_expr->type = DECIMAL;
            new_expr->data.double_value = exp->type == INTEGER ? log10(exp->data.int_value) : log10(exp->data.double_value);
            break;
        case 'D':
            if (!isnumber)
            {
                printf("Erreur ligne %d: Type invalide pour l'arrondi\n", yylineno);
                free(new_expr);
                free(exp);
                exit(1);
            }
            new_expr->type = DECIMAL;
            new_expr->data.double_value = exp->type == INTEGER ? round(exp->data.int_value) : round(exp->data.double_value);
            break;
        case 'A':
            if (!isnumber)
            {
                printf("Erreur ligne %d: Type invalide pour la valeur absolue\n", yylineno);
                free(new_expr);
                free(exp);
                exit(1);
            }
            new_expr->type = DECIMAL;
            new_expr->data.double_value = exp->type == INTEGER ? abs(exp->data.int_value) : abs(exp->data.double_value);
            break;
        case 'E':
            if (!isnumber)
            {
                printf("Erreur ligne %d: Type invalide pour la conversion en entier\n", yylineno);
                free(new_expr);
                free(exp);
                exit(1);
            }
            new_expr->type = INTEGER;
            new_expr->data.int_value = exp->type == INTEGER ? exp->data.int_value : (int)exp->data.double_value;
            break;

        case 'H':
            if (exp->type != STRING)
            {
                printf("Erreur ligne %d: Type invalide pour la longueur de chaîne\n", yylineno);
                free(new_expr);
                free(exp);
                exit(1);
            }
            new_expr->type = INTEGER;
            new_expr->data.int_value = strlen(exp->data.string_value);
            break;
        case 't':
            switch (exp->type)
            {
            case INTEGER:
                new_expr->type = STRING;
                new_expr->data.string_value = "Entier";
                break;
            case DECIMAL:
                new_expr->type = STRING;
                new_expr->data.string_value = "Decimal";
                break;
            case BOOLEAN:
                new_expr->type = STRING;
                new_expr->data.string_value = "Logique";
                break;
            case STRING:
                new_expr->type = STRING;
                new_expr->data.string_value = "Chaine";
                break;
            case FUNCTION:
                new_expr->type = STRING;
                new_expr->data.string_value = "Fonction";
                break;
            default:
                printf("Erreur ligne %d: Type invalide pour la fonction Type\n", yylineno);
                free(new_expr);
                free(exp);
                exit(1);
            }
            break;
        default:
            printf("Erreur ligne %d: Opération unaire inconnue\n", yylineno);
            free(new_expr);
            exit(1);
            break;
        }
        free(exp);
    }
    break;
    case ARRAY_ACCESS:
    {
        return get_array_element(expr->data.array_access.array_name, expr);
    }
    break;
    case FUNCTION:
    {
        Expression *result = evaluate_function_call(expr->data.function_call.name, expr->data.function_call.arguments);
        if (result) {
            // Create a deep copy of the result before returning
            Expression *result_copy = malloc(sizeof(Expression));
            if (!result_copy) {
                printf("Erreur ligne %d: Échec d'allocation mémoire pour le résultat de la fonction\n", yylineno);
                exit(1);
            }
            memcpy(result_copy, result, sizeof(Expression));
            
            // For string values, we need to duplicate the string
            if (result->type == STRING) {
                result_copy->data.string_value = strdup(result->data.string_value);
                if (!result_copy->data.string_value) {
                    printf("Erreur ligne %d: Échec d'allocation mémoire pour la chaîne de caractères\n", yylineno);
                    free(result_copy);
                    exit(1);
                }
            }
            
            free(result); // Free the original result
            return result_copy;
        }
        return NULL;
    }
    break;
    default:
        printf("Erreur ligne %d: Type d'expression inconnu\n", yylineno);
        free(new_expr);
        exit(1);
    }
    return new_expr;
}
