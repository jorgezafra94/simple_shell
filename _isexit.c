#include "shell.h"
#include <limits.h>
/**
 *type_exit - get the type of exit
 * @p: input user, array of pointers
 * @loop: counter of loops
 */
void type_exit(char **p, int loop, char *line, int i)
{
	unsigned int valor = 0, cont = 0, flag = 0;

	if (p[1] == NULL || (p[1][0] == '0' && p[1][1] == '\0'))
	{
		free(line);
		free_grid(p, i);
		exit(0);
	}
	else
	{
		while (p[1][cont] != '\0')
		{
			if (p[1][cont] < 48 || p[1][cont] > 57)
			{
				flag = 1;
				break;
			}
			cont++;
		}
		if (flag == 1)
			_put_err(p, loop);
		else
		{
			valor = _atoi(p[1]);

			if (!(valor > INT_MAX))
			{
				valor = valor % 256;
				free(line);
				free_grid(p, i);
				exit(valor);
			}
			else
				_put_err(p, loop);
		}
	}
}
/**
 * _isexit - finds if line input is exit therefore process termination
 * @p: input of user
 * @loop: loop counter
 */
void _isexit(char **p, int loop, char *line, int x)
{
	char str[5] = "exit";
	int i = 0, j = 0, cont = 0;

	while (p[0][j] != '\0')
	{
		j++;
	}
	if (j == 4)
	{
		while (i < 4)
		{
			if (p[0][i] == str[i])
				cont++;
			i++;
		}
		if (cont == 4)
			type_exit(p, loop, line, x);
	}
}
