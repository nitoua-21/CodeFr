#include <stdio.h>
#include "ast.h"

extern int yyparse(void);
extern FILE *yyin;
extern StatementList *parsed_program;

#define CODEFR_VERSION "1.0"

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

    // Handle the --version argument
    if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
        printf("CodeFr Interpreter version %s\n", CODEFR_VERSION);
        return 0;
    }

    // Check file extension
    if (!check_file_extension(argv[1]))
    {
        fprintf(stderr, "Erreur: Le fichier doit avoir l'extension .cfr\n");
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

    fclose(file);
    return 0;
}
