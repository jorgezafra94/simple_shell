#include "shell.h"

/**
 * _strlen - returns the length of a string.
 * @s: string
 * Return: Always 0.
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _isenv - finds if line input is env
 * @p: input of user
 */
int _isenv(char *p)
{
        char str[4] = "env";
        int i = 0, j = 0, cont = 0;

        while (p[j] != '\0')
        {
                j++;
        }
        if (j == 4)
        {
                while (i < 3)
                {
                        if(p[i] == str[i])
                                cont++;
                        i++;
                }
                if (cont == 3)
                {
                        _env();
                        return (1);
                }
        }
}
/**
 * _env - function to print the environment
 * @environ: points to an array of pointers to strings called the "environment"
 */
void _env(void)
{
        int i;

        for (i = 0; environ[i] != NULL; i++)
        {
                write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
                write(STDOUT_FILENO, "\n", 1);
        }
}
