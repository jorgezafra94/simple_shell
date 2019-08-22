#include "shell.h"

/**
 * _forky - program that creates process and execute
 * @p: array of pointer (args)
 * @line: input typed by the user
 * @a: count of pointers
 * Return: Nothing.
 */

void _forky(char **p, char *line, int a, int loop)
{
	pid_t child_pid;
	int status;
	(void)loop;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(127);
	}
	if (child_pid == 0)
	{
		/*printf("Before execve\n");*/
		if (execve(p[0], p, NULL) == -1)
		{
			/*_put_err(p, loop);*/
		}
		free(line);
		free_grid(p, a);
		/*printf("After execve\n");*/
		exit(127);
	}
	else
	{
		wait(&status);
	}
}
