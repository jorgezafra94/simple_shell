#include "shell.h"
/**
 * _getline - function to read what the user writes
 * Return: line in sucess otherwise NULL.
 */
char  *_getline(void)
{
	char *line = NULL;
	ssize_t bufsize = 0, num = 0, pos = 0;

/* this step is for not get an uninitialized variable in valgrind*/
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	num = getline(&line, &bufsize, stdin);
/* print list of environment varibales*/
	_env();
/* infinity loop while is different of EOF or error*/
	while (num != -1)
	{
		_isexit(line);
		pos = 0;
		if (!(line[0] == '\n'))
		{
			while (line[pos] != '\0')
			{
				if (line[pos] == '\n')
					return (line);
				pos++;
			}
		}
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		num = getline(&line, &bufsize, stdin);
	}
/* to get an end of line when the shell finish*/
	write(STDOUT_FILENO, "\n", 1);
	free(line);
	return (NULL);
}
