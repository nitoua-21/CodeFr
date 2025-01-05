#ifndef AST_H
#define AST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SYMBOLS 100
#define MAX_DIMENSIONS 2
extern int yylineno;

/**
 * enum SymbolType - Enumerates the possible types of symbols
 * @TYPE_ENTIER: Represents an integer type
 * @TYPE_DECIMAL: Represents a decimal (floating-point) type
 * @TYPE_LOGIQUE: Represents a logical (boolean) type
 * @TYPE_CHAINE: Represents a string type
 * @TYPE_VOID: Represents a void type
 *
 * This enumeration defines the possible data types that can be
 * represented in the language being interpreted.
 */
typedef enum
{
    TYPE_ENTIER,
    TYPE_DECIMAL,
    TYPE_LOGIQUE,
    TYPE_CHAINE,
    TYPE_VOID
} SymbolType;

/**
 * struct ArrayDimensions - Stores dimensions information for arrays
 * @sizes: Array holding the size of each dimension
 * @num_dimensions: Number of dimensions in the array (1 or 2)
 *
 * Description: This structure is used to store information about array
 * dimensions for both single and multi-dimensional arrays. The sizes array
 * holds the size of each dimension, where sizes[0] is the first dimension
 * and sizes[1] is the second dimension (if present). The num_dimensions
 * field indicates whether the array is 1D or 2D.
 */
typedef struct {
    int sizes[MAX_DIMENSIONS];
    int num_dimensions;
} ArrayDimensions;

/**
 * struct Symbol - Represents a symbol in the symbol table
 * @name: The name of the symbol (variable name)
 * @value: Union containing the value of the symbol
 * @type: The type of the symbol (from SymbolType enum)
 *
 * This structure represents a symbol in the symbol table, which
 * stores information about variables in the program.
 */
typedef struct
{
    char *name;
    bool is_constant;
    bool is_array;
    ArrayDimensions dimensions;
    union
    {
        int int_val;
        double float_val;
        bool bool_val;
        char *string_val;
        void *array_val;
    } value;
    SymbolType type;
} Symbol;

/**
 * struct Expression - Represents an expression in the AST
 * @type: The type of the expression
 * @data: Union containing the data specific to each expression type
 *
 * This structure represents various types of expressions in the
 * abstract syntax tree, including literals, variables, and operations.
 */
typedef struct Expression
{
    enum
    {
        INTEGER,
        DECIMAL,
        BOOLEAN,
        STRING,
        VARIABLE,
        BINARY_OP,
        UNARY_OP,
        ARRAY_ACCESS
    } type;
    union
    {
        int int_value;
        double double_value;
        bool bool_value;
        char *var_name;
        char *string_value;
        struct
        {
            char op;
            struct Expression *left;
            struct Expression *right;
        } binary_op;
        struct
        {
            char op;
            struct Expression *operand;
        } unary_op;
        struct {
            char *array_name;
            struct Expression *index;       // For 1D arrays
            struct Expression *index2;      // For 2D arrays
        } array_access;
    } data;
} Expression;

/**
 * struct ExpressionList - Linked list node for storing expressions
 * @expression: Pointer to an Expression structure
 * @next: Pointer to the next node in the ExpressionList
 *
 * Description: This structure represents a node in a linked list of expressions.
 * It is used to store multiple expressions in sequence, such as when handling
 * multiple arguments in a print statement or function call. The list is
 * implemented as a singly linked list where each node contains an expression
 * and a pointer to the next node.
 */
typedef struct ExpressionList
{
    Expression *expression;
    struct ExpressionList *next;
} ExpressionList;

/**
 * struct IdentifierList - Linked list node for storing identifiers
 * @identifier: The identifier name
 * @next: Pointer to the next node in the IdentifierList
 *
 * Description: This structure represents a node in a linked list of identifiers.
 * It is used to store multiple identifiers in sequence, such as when handling
 * multiple variables in a declaration statement. The list is implemented as a
 * singly linked list where each node contains an identifier and a pointer to
 * the next node.
 */
typedef struct IdentifierList {
    char *identifier;
    struct IdentifierList *next;
} IdentifierList;

/**
 * struct Parameter - Represents a function parameter
 * @name: Name of the parameter
 * @type: Type of the parameter
 */
typedef struct Parameter {
    char *name;
    SymbolType type;
    struct Parameter *next;
} Parameter;

// Forward declarations
struct Statement;
struct StatementList;
typedef struct Statement Statement;
typedef struct StatementList StatementList;

/**
 * struct StatementList - Represents a list of statements in the AST
 * @statement: Pointer to the current Statement
 * @next: Pointer to the next StatementList node
 *
 * This structure represents a linked list of statements, allowing
 * multiple statements to be chained together in sequence.
 */
struct StatementList
{
    Statement *statement;
    struct StatementList *next;
};

/**
 * struct Function - Represents a function definition
 * @name: Name of the function
 * @parameters: List of parameters
 * @return_type: Return type of the function (TYPE_VOID for no return)
 * @body: Function body statements
 * @declarations: Local variable declarations
 */
typedef struct Function {
    char *name;
    Parameter *parameters;
    SymbolType return_type;
    StatementList *body;
    StatementList *declarations;
} Function;

/**
 * struct CaseList - Linked list node for switch-case statements
 * @condition: Pointer to the Expression representing the case condition
 * @body: Pointer to the StatementList containing the case body
 * @next: Pointer to the next case in the switch statement
 *
 * Description: This structure represents a case within a switch statement.
 * Each node contains the case condition, the statements to execute when the
 * condition matches, and a pointer to the next case. The structure is used
 * to build a linked list of cases within a switch statement, allowing for
 * multiple case branches to be stored and evaluated sequentially.
 */
typedef struct CaseList
{
    Expression *condition;
    struct StatementList *body;
    struct CaseList *next;
} CaseList;

/**
 * struct Statement - Represents a statement in the AST
 * @type: The type of the statement
 * @data: Union containing the data specific to each statement type
 *
 * This structure represents various types of statements in the
 * abstract syntax tree, including assignments, print statements,
 * if statements, and read statements.
 */
typedef struct Statement
{
    enum
    {
        ASSIGN,
        ARRAY_ASSIGN,
        PRINT,
        READ,
        IF_STATEMENT,
        WHILE_STATEMENT,
        FOR_STATEMENT,
        SWITCH_STATEMENT,
        FUNCTION_DECL,
        FUNCTION_CALL,
        RETURN_STMT,
        ARRAY_DECL,
        VAR_DECL
    } type;
    union
    {
        struct
        {
            char *var_name;
            Expression *value;
        } assign;
        struct
        {
            char *array_name;
            Expression *index;
            Expression *index1;
            Expression *value;
        } array_assign;
        ExpressionList *print_exprs;
        struct
        {
            Expression *condition;
            struct StatementList *then_branch;
            struct ElseIfList *elif_branches;
            struct StatementList *else_branch;
        } if_stmt;
        char *read_var_name;
        struct
        {
            Expression *condition;
            struct StatementList *body;
        } while_stmt;
        struct
        {
            char *counter;
            Expression *start;
            Expression *end;
            struct StatementList *body;
        } for_stmt;
        struct
        {
            Expression *value;
            CaseList *cases;
            struct StatementList *default_case;
        } switch_stmt;
        struct {
            Function *function;
        } function_decl;
        struct {
            char *name;
            ExpressionList *arguments;
        } function_call;
        struct {
            Expression *value;
        } return_stmt;
        struct {
            char *array_name;
            ArrayDimensions dimensions;
            SymbolType element_type;
        } array_decl;
        struct {
            char *name;
            SymbolType type;
        } var_decl;
    } data;
} Statement;

/**
 * struct ElseIfBranch - Represents a single elif (SinonSi) branch
 * @condition: The condition to be evaluated for this branch
 * @body: The statements to execute if condition is true
 *
 * Description: This structure represents one SinonSi branch in an if statement,
 * containing both its condition and the statements to execute.
 */
typedef struct ElseIfBranch {
    Expression *condition;
    StatementList *body;
} ElseIfBranch;

/**
 * struct ElseIfList - Linked list of elif branches
 * @branch: The current elif branch
 * @next: Pointer to the next elif branch
 *
 * Description: This structure maintains a linked list of elif branches,
 * allowing for multiple SinonSi statements in sequence.
 */
typedef struct ElseIfList {
    ElseIfBranch branch;
    struct ElseIfList *next;
} ElseIfList;

void add_symbol(const char *name, SymbolType type, bool is_constant);
Symbol *get_symbol(const char *name);
void set_symbol_value(const char *name, Expression *value);

StatementList *new_statement_list(Statement *statement, StatementList *next);
Statement *new_assign(char *var_name, Expression *value);
Statement *new_array_assign(char *array_name, Expression *index, Expression *index1, Expression *value);
Statement *new_print(ExpressionList *exprs);
Statement *new_if(Expression *condition, StatementList *then_branch, StatementList *else_branch);
Statement *new_if_elif(Expression *condition, StatementList *then_branch,
                      ElseIfList *elif_branches, StatementList *else_branch);
ElseIfList *new_elif_list(Expression *condition, StatementList *body,
                         ElseIfList *next);
Statement *new_read(char *var_name);
Statement *new_while(Expression *condition, StatementList *body);
Statement *new_for(char *counter, Expression *start, Expression *end, StatementList *body);
Statement *new_switch(Expression *value, CaseList *cases, StatementList *default_case);
CaseList *new_case_list(Expression *condition, StatementList *body, CaseList *next);
ExpressionList *new_expression_list(Expression *expression, ExpressionList *next);
IdentifierList *new_identifier_list(char *identifier, IdentifierList *next);
void execute_statement_list(StatementList *list);

Expression *new_integer(int value);
Expression *new_decimal(double value);
Expression *new_variable(char *var_name);
Expression *new_string(char *string_value);
Expression *new_binary_op(char op, Expression *left, Expression *right);
Expression *new_boolean(bool value);
Expression *new_unary_op(char op, Expression *operand);
Expression *evaluate_expression(Expression *expr);

void add_array_symbol(const char *name, SymbolType type, ArrayDimensions dims);
Statement *new_array_declaration(char *name, ArrayDimensions dims, SymbolType type);
Expression *new_array_access(char *array_name, Expression *index, Expression *index2);
void set_array_element(const char *name, Expression *indices, Expression *value);
Expression *get_array_element(const char *name, Expression *indices);
void execute_array_declaration(Statement *stmt);
void add_multiple_symbols(IdentifierList *list, SymbolType type);

Function *new_function(char *name, Parameter *params, SymbolType return_type, StatementList *decls, StatementList *body);
Parameter *new_parameter(char *name, SymbolType type, Parameter *next);
Statement *new_function_decl(Function *function);
Statement *new_function_call(char *name, ExpressionList *arguments);
Statement *new_return(Expression *value);
void add_function(Function *function);
Function *get_function(const char *name);
Expression *evaluate_function_call(const char *name, ExpressionList *arguments);
Expression *get_return_value(void);
void set_return_value(Expression *value);
void push_scope(void);
void pop_scope(void);

char *process_string(const char *str);
bool check_file_extension(const char *filename);

#endif
