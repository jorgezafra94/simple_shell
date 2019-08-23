#include "shell.h"

/**
 * _ishelp - if args[0] is help builtin
 * @p: input pointer
 * Return: Nothing.
 */
void _ishelp(char **p, int loop)
{
	char str[] = "help";
	int i = 0, j = 0, cont = 0;

	while (p[0][j] != '\0')
		j++;
        if (j == 4)
        {
		while (i < 4)
		{
			if (p[0][i] == str[i])
				cont++;
			i++;
		}
		if (cont == 4)
			_builtinhelp(p, loop);
	}
}
/**
 * _builtinhelp - writes the error
 * @p: input pointer
 * Return: nothing.
 */
void _builtinhelp(char **p, int loop)
{
	char str1[3] = "cd", str2[5] = "exit", str3[5] = "help";
	int i = 0, j = 0, cont = 0, cont2 = 0, k = 1;

	while (p[k] != NULL)
	{
		j = 0;
		cont = 0;
		cont2 = 0;
		while (p[k][j] != '\0')
			j++;
		if (j == 2)
		{
			for (i = 0; i < 2; i++)
				if (p[k][i] == str1[i])
					cont++;
			if (cont == 2)
				read_cdhelp();
		}
		else if (j == 4)
		{
			for (i = 0 ; i < 4; i++)
				if (p[k][i] == str2[i])
					cont++;
			if (cont == 4)
				read_exithelp();
			for (i = 0 ; i < 4; i++)
				if (p[k][i] == str3[i])
					cont2++;
			if (cont2 == 4)
				read_helphelp();
		}
		else
			_put_err(p, loop);
		k++;
	}
}
