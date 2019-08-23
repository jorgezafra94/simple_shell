#include "shell.h"

/**
 * _ishelp - if args[0] is help builtin
 * @p: input pointer
 * Return: Nothing.
 */
void _ishelp(char **p)
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
			_builtinhelp(p);
	}
}
/**
 * _builtinhelp - writes the error
 * @p: input pointer
 * Return: nothing.
 */
void _builtinhelp(char **p)
{
	char str1[3] = "cd", str2[5] = "exit", str3[5] = "help";
	int i = 0, j = 0, cont = 0;

	while (p[1][j] != '\0')
		j++;
	if (j == 2)
	{
		for (; i < 2; i++)
			if (p[1][i] == str1[i])
				cont++;
		if (cont == 2)
			read_cdhelp();
	}
	if (j == 4)
	{
		for (i = 0 ; i < 4; i++)
			if (p[1][i] == str2[i])
				cont++;
		if (cont == 4)
			read_exithelp();
	}
	if (j == 4)
        {
                for (i = 0; i < 4; i++)
			if (p[1][i] == str3[i])
				cont++;
		if (cont == 4)
			read_helphelp();
	}
}
