#include "shell.h"
/**
 * _isexit - finds if line input is exit therefore process termination
 * @p: input of user
 */
void _isexit(char **p)
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
			if(p[0][i] == str[i])
				cont++;
			i++;
		}
		if (cont == 4)
			exit(0);
	}
}
