#include "shell.h"
/**
 * _ishelp - if args[0] is help builtin
 * @p: input pointer
 * @loop: counter of loops
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
		{
			_help(p, loop);
		}
	}
}
/**
 * _help_builtin - help of builtin
 * @p: input pointer
 * @loop: counter of loops
 * Return: nothing.
 */
void _help_builtin(char **p, int loop)
{
	char str1[3] = "cd", str2[5] = "exit", str3[5] = "help";
	int i = 0, j = 0, cont = 0, cont2 = 0, k = 1;

	while (p[k] != NULL)
	{
		j = 0;
		cont = 0, cont2 = 0;
		while (p[k][j] != '\0')
			j++;
		if (j == 2)
		{
			for (i = 0; i < 2; i++)
				if (p[k][i] == str1[i])
					cont++;
			if (cont == 2)
				read_cdhelp();
			else
				_put_err(p, loop, 1);
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
			else if (cont != 4 && cont2 != 4)
				_put_err(p, loop, 1);
		}
		else
			_put_err(p, loop, 1);
		k++;
	}
}
/**
* _help- writes the error
* @p: input pointer
* @loop: counter of loops
* Return: nothing.
*/
void _help(char **p, int loop)
{
	if (p[0] != NULL && p[1] == NULL)
	{
		read_help();
	}
	else
	{
		_help_builtin(p, loop);
	}
}
