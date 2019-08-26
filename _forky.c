#include "shell.h"

/**
 * _forky - program that creates process and execute
 * @p: array of pointer (args)
 * @line: input typed by the user
 * @a: count of pointers
 * @loop: count of loops
 * @v: arguments in input
 * @e: env length
 * @m: copy of environmental variable
 * Return: Nothing.
 */

void _forky(char **p, char *line, int a, int loop, char *v[], int e, char **m)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(127);
	}
	if (child_pid == 0)
	{
		if (execve(p[0], p, m) == -1)
		{
			_put_err(p, loop, 3, v);
		}
		free(line);
		free_grid(p, a);
		free_grid(m, e);
		/*printf("After execve\n");*/
		exit(127);
	}
	else
	{
		wait(&status);
	}
}
