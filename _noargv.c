#include "shell.h"
/**
 *revision - gets if the input of user is env, cd
 *@p: input user, array of pointers
 *@loop: counter of loops
 *@li: input user
 *@i:number of pointers inside array of pointers
 *@av: arguments in input
 *@m: copy of environmental variable
 *@e: number of elements in m
 * Return: -1 if the input is different to env or cd
 *or 0 if the input is cd or env
 */
int revision(char **p, int loop, char *li, int i, char *av[], char **m, int e)
{
	int valenv = 0, valcd = 0, other = -1, valex = 0, valhel = 0;

	valex = _isexit(p, loop, li, i, av, m, e);
	if (valex == 0)
		return (valex);
	valhel = _ishelp(p, loop, av);
	if (valhel == 0)
		return (valhel);
	valenv = _isenv(p, m);
	valcd = _iscd(p, loop, av, m);
	if (valenv == 0)
		return (valenv);
	if (valcd == 0)
		return (valcd);
	return (other);
}
/**
 * _noargv - shell form without filename at input
 * @argv: arguments in the input
 */
void _noargv(char *argv[])
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
			value = revision(args, loop, line, i, argv, m, e);
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
			free(line);
			fflush(STDIN_FILENO);
		}
		_put_err(args, loop, 0, argv);
	}
}