#include "holberton.h"

int main(void)
{
	char *line = NULL;
	char **args = NULL;
	pid_t child_pid;
        int status = 0, i = 0;
	while (1)
	{
		line = _getline();
		if (line == NULL)
			return (0);
		args = parsing(line);
		for (i = 0; args[i] != '\0'; i++)
			printf("%s\n", args[i]);
	     	child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("Before execve\n");
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error:");
			}
			printf("After execve\n");
			break;
		}
		else
		{
			wait(&status);
			printf("Oh, it's all better now\n");
		}
		free(line);
		for (; i >= 0; i--)
		{
			free(args[i]);
		}
		free(args);
	}
		return (0);
       
}
