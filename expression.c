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
Expression *new_integer(int value) {
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
Expression *new_decimal(double value) {
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
Expression *new_variable(char *var_name) {
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

Expression *new_string(char *string_value) {
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
Expression *new_boolean(bool value) {
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
Expression *new_unary_op(char op, Expression *operand) {
    Expression *expr = malloc(sizeof(Expression));
    expr->type = UNARY_OP;
    expr->data.unary_op.op = op;
    expr->data.unary_op.operand = operand;
    return expr;
}

ExpressionList *new_expression_list(Expression *expression, ExpressionList *next) {
    ExpressionList *list = malloc(sizeof(ExpressionList));
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
Expression *evaluate_expression(Expression *expr) {
    if (expr == NULL) {
        return NULL;
    }

    Expression *new_expr = malloc(sizeof(Expression));
    if (new_expr == NULL) {
        printf("Erreur ligne %d: Memory allocation failed in evaluate_expression\n", yylineno);
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
        case BOOLEAN:
            new_expr->type = BOOLEAN;
            new_expr->data.bool_value = expr->data.bool_value;
            break;
        case VARIABLE:
            {
                Symbol *sym = get_symbol(expr->data.var_name);
                if (!sym) {
                    printf("Erreur ligne %d: Undefined variable: %s\n", yylineno, expr->data.var_name);
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
                            printf("Erreur ligne %d: Memory allocation failed for string duplication\n", yylineno);
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
                Expression *lval = evaluate_expression(expr->data.binary_op.left);
                Expression *rval = evaluate_expression(expr->data.binary_op.right);

                double lvalue, rvalue;

                bool isint = (lval->type == INTEGER && rval->type == INTEGER) || (lval->type == BOOLEAN && rval->type == BOOLEAN);
                bool isnumber = (lval->type == INTEGER || lval->type == DECIMAL || lval->type == BOOLEAN) && (rval->type == INTEGER || rval->type == DECIMAL ||  rval->type == BOOLEAN);
                bool isstring = lval->type == STRING && rval->type == STRING;

                if (isint || isnumber)
                {
                    lvalue = lval->type == DECIMAL ? lval->data.double_value : lval->data.int_value;
                    rvalue = rval->type == DECIMAL ? rval->data.double_value : rval->data.int_value;
                }

                switch (expr->data.binary_op.op) {
                    case '+':
                        if (isint)
                        {
                            new_expr->type = INTEGER;
                            new_expr->data.int_value = (int) (lvalue + rvalue);
                        }else if (isnumber){
                            new_expr->type = DECIMAL;
                            new_expr->data.double_value = lvalue + rvalue;
                        }
                        else {
                            printf("Erreur ligne %d: Invalid type for addition\n", yylineno);
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
                            new_expr->data.int_value =  (int) (lvalue - rvalue);
                        }else if (isnumber){
                            new_expr->type = DECIMAL;
                            new_expr->data.double_value = lvalue - rvalue;
                        }
                        else {
                            printf("Erreur ligne %d: Invalid type for substraction\n", yylineno);
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
                            new_expr->data.int_value = (int) (lvalue * rvalue);
                        }else if (isnumber){
                            new_expr->type = DECIMAL;
                            new_expr->data.double_value = lvalue * rvalue;
                        }
                        else {
                            printf("Erreur ligne %d: Invalid type for multiplication\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case '/':
                        if (isnumber){
                            if (((rval->data.int_value + rval->data.double_value) == 0)) {
                                printf("Erreur ligne %d: Division par zéro\n", yylineno);
                                free(lval);
                                free(rval);
                                free(new_expr);
                                exit(1);
                            }
                            new_expr->type = DECIMAL;
                            new_expr->data.double_value = lvalue / rvalue;
                        } else {
                            printf("Erreur ligne %d: Invalid type for Division\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case 'P':
                        if (isint)
                        {
                            new_expr->type = INTEGER;
                            new_expr->data.int_value = (int) pow(lvalue, rvalue);
                        }else if (isnumber){
                            new_expr->type = DECIMAL;
                            new_expr->data.double_value = pow(lvalue, rvalue);
                        }
                        else {
                            printf("Erreur ligne %d: Invalid type for power\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case 'M':
                        if (isint)
                        {
                            new_expr->type = INTEGER;
                            new_expr->data.int_value = (int) lvalue % (int) rvalue;
                        }else if (isnumber){
                            new_expr->type = DECIMAL;
                            new_expr->data.double_value = (int)lvalue % (int)rvalue;
                        }
                        else {
                            printf("Erreur ligne %d: Invalid type for Mod\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case 'C': // CONCAT
                        char *result = malloc(sizeof(char) * (strlen(lval->data.string_value) + strlen(rval->data.string_value)) + 1);
                        new_expr->type = STRING;
                        strcpy(result, lval->data.string_value);
                        strcat(result, rval->data.string_value);
                        new_expr->data.string_value = strdup(result);
                        free(result);
                        break;
                    case '&': // AND
                        new_expr->type = BOOLEAN;
                        new_expr->data.bool_value = lval->data.bool_value && rval->data.bool_value;
                        break;
                    case '|': // OR
                        new_expr->type = BOOLEAN;
                        if (isnumber)
                            new_expr->data.bool_value = lvalue || rvalue;
                        else {
                            printf("Erreur ligne %d: Invalid type for OR\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case '^': // XOR
                        new_expr->type = BOOLEAN;
                        if (isnumber)
                            new_expr->data.bool_value = lvalue != rvalue;
                        else {
                            printf("Erreur ligne %d: Invalid type for XOR\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case '<':
                        new_expr->type = BOOLEAN;
                        if (isnumber)
                            new_expr->data.bool_value = lvalue < rvalue;
                        else {
                            printf("Erreur ligne %d: Invalid type for <\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case '>':
                        new_expr->type = BOOLEAN;
                        if (isnumber)
                            new_expr->data.bool_value = lvalue > rvalue;
                        else {
                            printf("Erreur ligne %d: Invalid type for >\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case 'L': // <=
                        new_expr->type = BOOLEAN;
                        if (isnumber)
                            new_expr->data.bool_value = lvalue <= rvalue;
                        else {
                            printf("Erreur ligne %d: Invalid type for <=\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case 'G': // >=
                        new_expr->type = BOOLEAN;
                        if (isnumber)
                            new_expr->data.bool_value = lvalue >= rvalue;
                        else {
                            printf("Erreur ligne %d: Invalid type for >=\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case '=': // ==
                        new_expr->type = BOOLEAN;
                        if (isnumber)
                            new_expr->data.bool_value = lvalue == rvalue;
                        else if (isstring)
                            new_expr->data.bool_value = strcmp(lval->data.string_value, rval->data.string_value) == 0;                           
                        else {
                            printf("Erreur ligne %d: Invalid type for ==\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case '!': // !=
                        new_expr->type = BOOLEAN;
                        if (isnumber)
                            new_expr->data.bool_value = lvalue != rvalue;
                        else if (isstring)
                            new_expr->data.bool_value = strcmp(lval->data.string_value, rval->data.string_value) != 0;                           
                        else {
                            printf("Erreur ligne %d: Invalid type for Or\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case 'A': // Alea(x, n)
                        srand(time(0));
                        new_expr->type = DECIMAL;
                        if (isnumber)
                        {
                            int min = lval->type == INTEGER ? (int)lval->data.int_value : (int)lval->data.double_value;
                            int max = rval->type == INTEGER ? (int)rval->data.int_value : (int)rval->data.double_value;

                            new_expr->data.double_value = rand() % (max - min + 1) + min;
                        }                         
                        else {
                            printf("Erreur ligne %d: Invalid type for 'Alea'\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case 'p': // Comparer(x, n)
                        srand(time(0));
                        new_expr->type = INTEGER;
                        if (lval->type == STRING && rval->type == STRING)
                        {
                            new_expr->data.int_value = strcmp(lval->data.string_value, rval->data.string_value);
                        }                         
                        else {
                            printf("Erreur ligne %d: Invalid type for 'Comparer'\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    case 'r': // Recherche(s1, s2)
                        new_expr->type = INTEGER;
                        if (lval->type == STRING && rval->type == STRING)
                        {
                            int pos = 0;

                            char *result = strstr(lval->data.string_value, lval->data.string_value);
                        if (result != NULL)
                            pos = (int)(result - lval->data.string_value + 1);

                        new_expr->data.int_value = pos;
                        free(result);
                        }                         
                        else {
                            printf("Erreur ligne %d: Invalid type for 'Recherche'\n", yylineno);
                            free(lval);
                            free(rval);
                            free(new_expr);
                            exit(1);
                        }
                        break;
                    default:
                        printf("Erreur ligne %d: Unknown binary operator\n", yylineno);
                        free(lval);
                        free(rval);
                        free(new_expr);
                        exit(1);
                    }
                free(lval);
                free(rval);
            }
            break;
        case UNARY_OP:
            {
                Expression *exp = evaluate_expression(expr->data.unary_op.operand);

                bool isnumber = exp->type == INTEGER || exp->type == DECIMAL || exp->type == BOOLEAN;

                if (exp->type == BOOLEAN) {
                    exp->type = INTEGER;
                    exp->data.int_value = exp->data.bool_value;
                }

                switch (expr->data.unary_op.op)
                {
                    case 'R':
                        if (!isnumber)
                        {
                            printf("Erreur ligne %d: Invalid argument type for 'Racine'\n", yylineno);
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
                            printf("Erreur ligne %d: Invalid argument type for 'Sin'\n", yylineno);
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
                            printf("Erreur ligne %d: Invalid argument type for 'Cos'\n", yylineno);
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
                            printf("Erreur ligne %d: Invalid argument type for 'Tangent'\n", yylineno);
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
                            printf("Erreur ligne %d: Invalid argument type for 'Log'\n", yylineno);
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
                            printf("Erreur ligne %d: Invalid argument type for 'Log10'\n", yylineno);
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
                            printf("Erreur ligne %d: Invalid argument type for 'Arrondi'\n", yylineno);
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
                            printf("Erreur ligne %d: Invalid argument type for 'Abs'\n", yylineno);
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
                            printf("Erreur ligne %d: Invalid argument type for 'Entier'\n", yylineno);
                            free(new_expr);
                            free(exp);
                            exit(1);
                        }
                        new_expr->type = INTEGER;
                        new_expr->data.int_value = exp->type == INTEGER ? exp->data.int_value : (int) exp->data.double_value;
                        break;

                    case 'H':
                        if (exp->type != STRING)
                        {
                            printf("Erreur ligne %d: Invalid argument type for 'Longueur'\n", yylineno);
                            free(new_expr);
                            free(exp);
                            exit(1);
                        }
                        new_expr->type = INTEGER;
                        new_expr->data.int_value = strlen(exp->data.string_value);
                        break;
                    default:
                        printf("Erreur ligne %d: Unknown Unary operation\n", yylineno);
                        free(new_expr);
                        exit(1);
                        break;
                    }
            }
            break;
        default:
            printf("Erreur ligne %d: Unknown expression type\n", yylineno);
            free(new_expr);
            exit(1);
    }
    return new_expr;
}
