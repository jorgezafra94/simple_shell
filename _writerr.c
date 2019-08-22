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
	return (write(2, &c, 1));
}
/**
 * _put_err_str - writes the character c to stdout
 * @str: The string to print
 *
 * Return: nothing.
 */
void _put_err_str(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_put_err_char(str[i]);
}
/**
 * _put_err - writes the error
 * @p: The string to print
 * @loop: count of loop in prompt
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void _put_err(char **p)
{
	char prompt[] = "./hsh";

	if (err == 0)
	{
		_put_err_str(prompt);
		_put_err_char(':');
		_put_err_char(' ');
		_put_err_char(loopin + '0');
		_put_err_char(':');
		_put_err_char(' ');
		_builtinerr(p);
		err = 1;
	}
}
/**
 * _builtinerr - writes the error
 * @str: 
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void _builtinerr(char **p)
{
	char str1[3] = "cd";
	char str2[5] = "exit";
	int i = 0, j = 0, cont = 0;
	
	while (p[0][j] != '\0')
	{
		j++;
	}
	if (j == 2)
	{
		while (i < 2)
		{
			if(p[0][i] == str1[i])
				cont++;
			i++;
		}
		if (cont == 2)
		{
			write(STDOUT_FILENO, p[0], 2);
			write(STDOUT_FILENO, ": can't cd to ", 14);
			write(STDOUT_FILENO, p[1], _strlen(p[1]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	if (j == 4)
	{
		while (i < 4)
		{
			if(p[0][i] == str2[i])
				cont++;
			i++;
		}
		if (cont == 4)
		{
			write(STDOUT_FILENO, p[0], 4);
			write(STDOUT_FILENO, ": Illegal number: ", 18);
			write(STDOUT_FILENO, p[1], _strlen(p[1]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}
