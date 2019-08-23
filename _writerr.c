#include "shell.h"
/**
 * _put_err_char - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _put_err_char(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
/**
 * _put_err_str - writes the character c to stdout
 * @str: The string to print
 *
 * Return: Nothing.
 */
void _put_err_str(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_put_err_char(str[i]);
}
/**
 * _put_err - writes the error
 * @p: input pointer
 * @loop: counter of loops
 * Return: Nothing.
 */
void _put_err(char **p, int loop, int sig)
{
	char prompt[] = "./hsh";
	static int pr = 1;

	if (sig == 0)
		pr = 0;
	if (sig == 3)
		pr = 3;
	pr++;
	if (pr == 2)
	{
		_put_err_str(prompt);
		_put_err_char(':');
		_put_err_char(' ');
		_put_err_char(loop + '0');
		_put_err_char(':');
		_put_err_char(' ');
		_builtinerr(p);
	}
}
/**
 * _builtinerr - writes the error
 * @p: input pointer
 * Return: nothing.
 */
void _builtinerr(char **p)
{
	char str1[3] = "cd", str2[5] = "exit", str3[5] = "help";
	int i = 0, j = 0, cont = 0, cont2 = 0;

	while (p[0][j] != '\0')
		j++;
	if (j == 2)
	{
		for (; i < 2; i++)
			if (p[0][i] == str1[i])
				cont++;
		if (cont == 2)
			_errorcd(p);
	}
	if (j == 4)
	{
		for (i = 0 ; i < 4; i++)
			if (p[0][i] == str2[i])
				cont++;
		if (cont == 4)
			_errorexit(p);
	}
	if (j == 4)
        {
                for (i = 0; i < 4; i++)
			if (p[0][i] == str3[i])
				cont2++;
		if (cont2 == 4)
			_errorhelp(p);
	}
}
	
