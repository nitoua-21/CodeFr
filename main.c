#include <stdio.h>
#include "ast.h"
#include "module.h"

extern int yyparse(void);
extern FILE *yyin;
extern StatementList *parsed_program;

#define CODEFR_VERSION "1.0"

/**
 * main - Entry point of the interpreter
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 *
 * Description: Main function that validates input files and starts
 * the interpretation process. Accepts multiple .cfr files.
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <source_file> [additional_source_files...]\n", argv[0]);
        return 1;
    }

    // Handle the --version argument
    if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
        printf("CodeFr Interpreter version %s\n", CODEFR_VERSION);
        return 0;
    }

    // Process each input file
    for (int i = 1; i < argc; i++) {
        // Check file extension
        if (!check_file_extension(argv[i]))
        {
            fprintf(stderr, "Erreur: Le fichier %s doit avoir l'extension .cfr\n", argv[i]);
            return 1;
        }

        FILE *file = fopen(argv[i], "r");
        if (!file)
        {
            perror("Erreur d'ouverture du fichier");
            return 1;
        }

        yyin = file;
        parsed_program = NULL;  // Reset for each file

        if (yyparse() != 0)
        {
            fprintf(stderr, "Erreur d'analyse syntaxique\n");
            fclose(file);
            return 1;
        }

        if (parsed_program)
        {
            execute_statement_list(parsed_program);
        }

        fclose(file);
    }

    return 0;
}
