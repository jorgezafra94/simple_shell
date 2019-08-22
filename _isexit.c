#include "shell.h"

void type_exit(char **p)
{
	unsigned int valor, cont = 0, flag = 0;

	if (p[1] == NULL ||(p[1][0] == '0' && p[1][1] == '\0'))
		exit(0);
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
			perror("Error: no value admitted");
		else
		{
			valor = _atoi(p[1]);
			valor = valor % 256;
			exit(valor);
		}
	}
}
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
			type_exit(p);
	}
}
