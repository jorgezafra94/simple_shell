#include "shell.h"
/**
 * _isenv - finds if line input is env
 * @p: input of user, array of pointers
 * Return: -1 if fails or 0 if success
 */
int _isenv(char **p, char **myenv)
{
	char str[4] = "env";
	int i = 0, j = 0, cont = 0;

	while (p[0][j] != '\0')
		j++;
	if (j == 3)
	{
		while (i < 3)
		{
			if (p[0][i] == str[i])
				cont++;
			i++;
		}
		if (cont == 3)
		{
			_env(myenv);
			return (0);
		}
	}
	return (-1);
}
char **create_env(void)
{
	int i, j = 0, c = 0;
        char **myenv = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		;
	}
        myenv = _calloc(i + 1, sizeof(char *));
	if (!myenv)
                return (NULL);
	while (environ[j] != NULL)
	{
		c = 0;
		while (environ[j][c] != '\0')
			c++;
		myenv[j] = _calloc(c + 1, sizeof(char));
		if (myenv[j] == NULL)
		{
			free_grid(myenv, j);
			return (NULL);
		}
                for (i = 0; i < c; i++)
			myenv[j][i] = environ[j][i];
		j++;
        }
	myenv[j] = NULL;
        return (myenv);
}
/**
 * _env - function to print the environment variables
 * environ points to an array of pointers to strings called the "environment"
 * @myenv: icopy of environmental
 */
void _env(char **myenv)
{
	int i;

	for (i = 0; myenv[i] != NULL; i++)
	{
		write(STDOUT_FILENO, myenv[i], _strlen(myenv[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
