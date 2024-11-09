#include "ast.h"

/**
 * process_string - Processes a string by handling escape sequences
 * @str: The input string to process
 *
 * This function takes a string and processes it by converting escape
 * sequences (like \n, \t, \\, \") into their actual characters. It
 * allocates a new string for the processed result.
 *
 * Return: A pointer to the newly allocated processed string
 */
char *process_string(const char *str)
{
    int len = strlen(str);
    char *processed = malloc(len);
    int i, j;

    for (i = 0, j = 0; i < len - 1; i++, j++)
    {
        if (str[i] == '\\')
        {
            i++;
            switch (str[i])
            {
            case 'n':
                processed[j] = '\n';
                break;
            case 't':
                processed[j] = '\t';
                break;
            case '\\':
                processed[j] = '\\';
                break;
            case '"':
                processed[j] = '"';
                break;
            default:
                processed[j] = str[i];
            }
        }
        else
        {
            processed[j] = str[i];
        }
    }
    processed[j] = '\0';
    return processed;
}

/**
 * check_file_extension - Verifies if a file has .algo extension
 * @filename: Name of the file to check
 *
 * Description: This function checks if the given filename ends with
 * the .algo extension. Case sensitive comparison is performed.
 *
 * Return: true if file has .algo extension, false otherwise
 */
bool check_file_extension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename) {
        return false;
    }
    return strcmp(dot, ".algo") == 0;
}