#include "holberton.h"
/**
 * _getline - function to read what the user writes
 */
char  *_getline(void)
{
	char *line = NULL;
	ssize_t bufsize = 0, num = 1, pos = 0;

	while (num != -1)
	{
		printf("$ ");
		num = getline(&line, &bufsize, stdin);
		if (!(line[0] == '\n'))
		{
			while (line[pos] != '\0')
			{
				if (line[pos] == '\n')
					return line;
				pos++;
			}
		}
	}
}	
