#include "shell.h"
/**
 * _iscd - finds if line input is cd builtin
 * @p: input of user, array of pointers
 * @loop: counter of loop
 * @v: arguments in input
 * Return: -1 if not success 0 if exist cd in args[0]
 */
int _iscd(char **p, int loop, char *v[])
{
	char str[] = "cd";
	int i = 0, cont = 0, valor = -1;

	while (p[0][i] != '\0')
	{
		if (i < 2)
		{
			if (p[0][i] == str[i])
				cont++;
		}
		i++;
	}
	if (i == 2)
		cont++;

	if (cont == 3)
	{
		_cd(p, loop, v);
		valor = 0;
	}
	else if (cont == 2)
	{
		_put_err(p, loop, 3, v);
		valor = 0;
	}
	return (valor);
}

/**
 * _cleancd - clean buffer
 * @c: pointer to buf
 * Return: -1 if not success 0 if exist cd in args[0]
 */
void _cleancd(char *c)
{
	int i;

	for (i = 0; i < 2048; i++)
		c[i] = 0;
}

/**
 * _fullcd - fill buffer
 * @f: pointer to buf
 * @aux: pointer to aux
 * Return: -1 if not success 0 if exist cd in args[0]
 */
void _fullcd(char *f, char *aux)
{
	int w;

	for (w = 0; aux[w] != '\0'; w++)
		f[w] = aux[w];
	for (; w < 2048; w++)
		f[w] = 0;
}
/**
 * _cd - Changes the current directory of the process.
 * @a: input of user, array of pointers
 * @loop: loops counter
 * @v: arguments in input
 * Return:-1 if not find the directory or 0 if success
 */
void _cd(char **a, int loop, char *v[])
{
	int valor = 0;
	static char buf[2048];
	static int w = 1;
	char aux[2048] = {0};

	if (w == 1)
	{
		_fullcd(buf, _gethome());
		w++;
	}
	if (a[1] == NULL)
	{
		_cleancd(buf);
		getcwd(buf, 2048);
		valor = chdir((const char *)_gethome());
	}
	else if (a[1][0] == '-' && a[1][1] == '\0')
	{
		_cleancd(aux);
		getcwd(aux, 2048);
		write(STDOUT_FILENO, buf, 2048);
		write(STDOUT_FILENO, "\n", 1);
		valor = chdir((const char *) buf);
		_fullcd(buf, aux);
	}
	else
	{
		_cleancd(buf);
		getcwd(buf, 2048);
		valor = chdir((const char *)a[1]);
	}
	if (valor == -1)
		_put_err(a, loop, 1, v);
}
