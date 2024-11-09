#include <stdio.h>
#include "ast.h"

extern int yyparse(void);
extern FILE *yyin;
extern StatementList *parsed_program;

/**
 * main - Entry point of the interpreter
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 *
 * Description: Main function that validates input file and starts
 * the interpretation process. Only accepts .algo files.
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    // Check file extension
    if (!check_file_extension(argv[1]))
    {
        fprintf(stderr, "Erreur: Le fichier doit qvoir l'extension .algo\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    yyin = file;

    // extern int yydebug;
    // yydebug = 1;

    if (yyparse() == 0)
    {
        execute_statement_list(parsed_program);
    }
    else
    {
        fprintf(stderr, "Parsing failed.\n");
    }

    fclose(file);
    return 0;
}
