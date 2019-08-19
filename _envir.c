#include "shell.h"

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
                        _env((char **)p);
                        return (1);
                }
        }
}
/**
 * _env - function to print the environment
 * @environ:.
 */
void _env(char **environ)
{
        int i;

        for (i = 0; environ[i] != NULL; i++)
        {
                write(STDOUT_FILENO, environ[i], strlen(environ[i]));
                write(STDOUT_FILENO, "\n", 1);
        }
}
