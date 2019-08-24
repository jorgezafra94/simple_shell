#include "shell.h"

/**
 * print_number - prints all natural numbers
 * @n: parameter to print
 * Return: Always 0
 */
void print_number(int n)
{
	unsigned int j, cont = 1;
	char a;
	unsigned int var1, num, var2, var3 = 1;

	var2 = n;
	num = var2;
	while (num > 9)
	{
		num = num / 10;
		cont++;
		var3 = var3 * 10;
	}
	for (j = 1; j <= cont; j++)
	{
		var1 = var2 / var3;
		var2 = var2 % var3;
		var3 = var3 / 10;
		a = '0' + var1;
		write(STDERR_FILENO, &a, 1);
	}
}

/**
 * _put_err - writes the error
 * @p: input pointer
 * @loop: counter of loops
 * @sig: signal
 * Return: Nothing.
 */
void _put_err(char **p, int loop, int sig)
{
	char prompt[] = "./hsh";
	static int pr = 1;

	(void)loop;
	if (sig == 0)
		pr = 0;
	if (sig == 3)
		pr = 3;
	pr++;
	if (pr == 2)
	{
		write(STDERR_FILENO, prompt, 5);
		write(STDERR_FILENO, ":", 1);
		write(STDERR_FILENO, " ", 1);
		print_number(loop);
		write(STDERR_FILENO, ":", 1);
		write(STDERR_FILENO, " ", 1);
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
		for (i = 0; i < 4; i++)
			if (p[0][i] == str3[i])
				cont2++;
		if (cont2 == 4)
			_errorhelp(p);
	}
}
