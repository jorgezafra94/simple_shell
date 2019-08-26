#include "shell.h"
/**
 * main - shell skeleton
 * @argc: number of arguments in the input
 * @argv: arguments in the input
 * Return: 0 on Success
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		_noargv(argv);
	}
	else if (argc == 2)
	{
		_yesargv(argv);
	}
	else
	{
		write(STDIN_FILENO, "NO ADMITTED AMOUNT OF ARGUMENTS", 31);
		write(STDIN_FILENO, "\n", 1);
	}
	return (0);
}