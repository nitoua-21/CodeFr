#include <stdio.h>
#include "parser.tab.h"

extern FILE *yyin;

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	if (argc > 1)
	{
		FILE *file = fopen(argv[1], "r");

		if (!file)
		{
			perror(argv[1]);
			return (1);
		}
		yyin = file;
	}

	yyparse();

	return (0);
}
