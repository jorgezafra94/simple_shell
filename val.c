#include "shell.h"

int revision(char **p)
{
	int valenv = 0, valcd = 0, other = -1;

	_isexit(p);

	if ((valenv = _isenv(p)) == 0)
		return (valenv);
	if ((valcd = _iscd(p)) == 0)
	  return (valcd);
	return (other);
}

int main(void)
{
	char *line = NULL;
	char **args = NULL;
        int value = 1, i = 0;

	while (1)
	{
		line = _getline();
		if (line == NULL)
			return (0);
		args = parsing(line);
		if (args == NULL)
			return (0);
		for (i = 0; args[i] != NULL; i++)
			;
		value = revision(args);
		if (value != 0)
		{
			args = checkbin(args);
			_forky(args, line,  i);
		}
		free(line);
	        free_grid(args, i);
	}
		return (0);
}
