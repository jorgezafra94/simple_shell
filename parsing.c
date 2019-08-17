#include "holberton.h"

#define DELIM " \\`'#*&\n"

char **parsing(char *line)
{
	char *str = NULL;
	char *str2 = NULL, *token = NULL, **p = NULL;
	int length = 0, j = 0, i = 0, buffsize = 10;

	str = line;
	p = malloc((buffsize) * sizeof(char *));
	if (p == NULL)
	{
		perror("No memory");
		exit(EXIT_FAILURE);
	}
	p[buffsize] = NULL;
        token = strtok(str, DELIM);
	j = 0;
	while (token != NULL)
	{
		while (token[length] != '\0')
			length++;
		p[j] = malloc((length + 1) * sizeof(char));
		if (p[j] == NULL)
		{
			while (j >= 0)
			{
				free(p[j]);
				--j;
			}
			free(p);
			perror("No memory");
			exit(EXIT_FAILURE);
		}
		for (i = 0; i < length; i++)
			p[j][i] = token[i];
		p[j][i] == '\0';
		length = 0;
		j++;
		token = strtok(NULL, DELIM);
	}
        return (p);
}
