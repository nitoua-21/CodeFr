#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codefr.h"

extern int yyparse(void);
extern FILE *yyin;

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    yyin = input_file;

    printf("CodeFR Interpreter\n");
    printf("------------------\n");

    int result = yyparse();

    if (result == 0) {
        printf("\nParsing completed successfully.\n");
    } else {
        printf("\nParsing failed.\n");
    }

    fclose(input_file);

    // Clean up symbol table
    for (int i = 0; i < symbol_count; i++) {
        free(symbols[i].name);
        if (symbols[i].type == TYPE_CHAINE && symbols[i].value.string_val) {
            free(symbols[i].value.string_val);
        }
    }

    return result;
}
