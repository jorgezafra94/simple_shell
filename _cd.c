#include "shell.h"

/**
 * _iscd - finds if line input is cd builtin
 * @p: input of user
 */
int _iscd(char *p)
{
        char str[3] = "cd";
        int i = 0, j = 0, cont = 0;

	while (p[j] != '\0')
	{
		j++;
	}
	if (j == 3)
	{
		while (i < 2)
		{
			if(p[i] == str[i])
				cont++;
			i++;
		}
		if (cont == 2)
		{
			_cd(p);
			return (cont);
		}
	}
}
/**
 * _cd - Changes the current directory of the process.
 * @p: 
 */

void _cd(char *p)
{
	if (p == NULL)
	{
		chdir(getenv("HOME"));
	}
	else
		if (chdir(p[1]) == -1)
			printf("No such file or directory");
}
