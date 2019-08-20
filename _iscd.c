#include "shell.h"

/**
 * _iscd - finds if line input is cd builtin
 * @p: input of user
 * Return: -1 if not success 0 if exist cd in args[0]
 */
int _iscd(char **p)
{
        char str[3] = "cd";
        int i = 0, j = 0, cont = 0, valor = -1;

	while (p[0][j] != '\0')
	{
		j++;
	}
	if (j == 2)
	{
		while (i < 2)
		{
			if(p[0][i] == str[i])
				cont++;
			i++;
		}
		if (cont == 2)
		{
			valor = _cd(p[1]);
		}
	}
	return (valor);
}
/**
 * _cd - Changes the current directory of the process.
 * @a: pointer to check
 * Return:-1 if not find the directory or 0 if success
 */

int _cd(char *a)
{
	int valor = -1, i;
	char *ptr = NULL;
	static char buf[2048];
	static int w = 0;
	char *aux2;
	char aux[2048];

	if (w == 0)
	{
		aux2 = _gethome();
		while (aux2[w] != '\0')
		{
			buf[w] = aux2[w];
			w++;
		}
	}
	if (a == NULL)
	{
		ptr = getcwd(buf, 2048);
		valor = chdir((const char *)_gethome());
		return (valor);
	}
	else if (a[0] == '-' && a[1] == '\0')
	{
		getcwd(aux, 2048);
		valor = chdir((const char *) buf);
		for (i = 0; i < 2048; i++)
			buf[i] = aux[i];
		return (valor);
	}
	else
	{
		getcwd(buf, 2048);
		valor = chdir((const char *)a);
		return (valor);
	}
}
