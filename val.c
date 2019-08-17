#include "shell.h"

int main(void)
{
	char *line = NULL;
	char **args = NULL;
        int status = 0, i = 0;

	while (1)
	{
		line = _getline();
		if (line == NULL)
			return (0);
		args = parsing(line);
		if (args == NULL)
			return (0);
		for (i = 0; args[i] != NULL; i++)
			printf("%s\n", args[i]);
	     	_forky(args, line,  i);
		free(line);
	        free_grid(args, i);
	}
		return (0);
}
