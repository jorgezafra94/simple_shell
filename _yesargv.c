#include "shell.h"
/**
 * _yesargv - shell form without filename at input
 * @argv: arguments in the input
 */
void _yesargv(char *argv[])
{
	char *line = NULL;
	char **args = NULL, **m = NULL;
	int value = 1, i = 0, e = 0, *ploop;
	static int loop;

	loop = 0;
	ploop = &loop;
	while (1)
	{
		if (loop == 0)
		{
			m = create_env();
			for (e = 0; m[e] != NULL; e++)
				;
		}
		line = _getline(ploop, m, e);
		args = parsing(line);
		if (args)
		{
			for (i = 0; args[i] != NULL; i++)
				;
			value = revision(args, loop, line, i, argv, m);
			if (value != 0)
			{
				args = checkbin(args);
				if (args)
					_forky(args, line, i, loop, argv, e, m);
			}
			free_grid(args, i);
			free(line);
		}
		else
		{
			free_grid(m, e);
			free(line);
			fflush(STDIN_FILENO);
		}
		_put_err(args, loop, 0, argv);
	}
}
