#include "shell.h"
/**
 *revision - gets if the input of user is env, cd
 *@p: input user, array of pointers
 * Return:-1 if the input is different to env or cd
 *or 0 if the input is cd or env
 */
int revision(char **p)
{
	int valenv = 0, valcd = 0, other = -1;

	_isexit(p);
	valenv = _isenv(p);
	valcd = _iscd(p);
	if (valenv == 0)
		return (valenv);
	if (valcd == 0)
		return (valcd);
	return (other);
}
/**
 *main - shell skeleton
 * Return: 0 on Success
 */
int main(void)
{
	char *line = NULL;
	char **args = NULL;
	int value = 1, i = 0;

	while (1)
	{
		line = _getline();
		args = parsing(line);
		if (args)
		{
			for (i = 0; args[i] != NULL; i++)
				;
			value = revision(args);
			if (value != 0)
			{
				args = checkbin(args);
				if (args)
				_forky(args, line, i);
			}
			free_grid(args, i);
			free(line);
		}
		else
		{
			free(line);
			fflush(STDIN_FILENO);
		}
	}
		return (0);
}
