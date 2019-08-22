#include "shell.h"
/**
 * _getline - function to read what the user writes
 * Return: line in sucess otherwise NULL.
 */
char  *_getline(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	int num = 0, pos = 0;
/* this step is for not get an uninitialized variable in valgrind*/
	write(STDIN_FILENO, "#cisfun$ ", 9);
/*verify the Crtl+c Interrupt Signal*/
	signal(SIGINT, _signal);
	num = getline(&line, &bufsize, stdin);
/* infinity loop while is different of EOF or error*/
	while (num != -1)
	{
/* terminate when input is exit */
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
		write(STDIN_FILENO, "#cisfun$ ", 9);
		signal(SIGINT, _signal);
		num = getline(&line, &bufsize, stdin);
	}
/* to get an end of line when the shell finish*/
	if (num == -1)
		write(STDIN_FILENO, "\n", 1);
	free(line);
	return (NULL);
}
