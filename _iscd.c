#include "shell.h"
/**
 * _iscd - finds if line input is cd builtin
 * @p: input of user, array of pointers
 * @loop: counter of loop
 * Return: -1 if not success 0 if exist cd in args[0]
 */
int _iscd(char **p, int loop)
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
			if (p[0][i] == str[i])
				cont++;
			i++;
		}
		if (cont == 2)
		{
			valor = _cd(p, loop);
		}
	}
	return (valor);
}
/**
 * _cd - Changes the current directory of the process.
 * @a: input of user, array of pointers
 * @loop: loops counter
 * Return:-1 if not find the directory or 0 if success
 */
int _cd(char **a, int loop)
{
	int valor = -1, i;
	static char buf[2048];
	static int w = 1;
	char *aux2, aux[2048] = {0};

	if (w == 1)
	{
		aux2 = _gethome();
		for (w = 0; aux2[w] != '\0'; w++)
			buf[w] = aux2[w];
	}
	if (a[1] == NULL)
	{
		getcwd(buf, 2048);
		valor = chdir((const char *)_gethome());
		if (valor == -1)
			_put_err(a, loop);
		return (valor);
	}
	else if (a[1][0] == '-' && a[1][1] == '\0')
	{
		getcwd(aux, 2048);
		write(STDOUT_FILENO, buf, 2048);
		write(STDOUT_FILENO, "\n", 1);
		valor = chdir((const char *) buf);
		if (valor == -1)
			_put_err(a, loop);
		for (i = 0; i < 2048; i++)
			buf[i] = aux[i];
		return (valor);
	}
	else
	{
		getcwd(buf, 2048);
		valor = chdir((const char *)a[1]);
		if (valor == -1)
			_put_err(a, loop);
		return (valor);
	}
}
