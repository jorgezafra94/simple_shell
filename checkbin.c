#include "shell.h"
/**
 *
 *
 *
 */
char *_getpath(void)
{
	int i, j, k = 0, cont = 0;
	char str[] = "PATH=";
	char *path;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			if (cont == 5)
				break;
			if (environ[i][j] == str[j])
				cont++;
			else
				break;
		}
		if (cont == 5)
			break;
	}
	while (environ[i][k] != '\0')
		k++;
	path = _calloc(k + 1, sizeof(char));
	k = 5;
	while (environ[i][k] != '\0')
	{
		path[k - 5] = environ[i][k];
		k++;
	}
	return (path);
}
/**
 * checkbin - checks if arg[0] has /bin/
 * @b: array of pointers
 * Return: 0.
 */

char **checkbin(char **b)
{
	unsigned int i = 0, j = 0, k = 0;
	struct stat veri;
	char *path, *tokens, *buf;
	char *valor;

	i = _strlen(b[0]);
	if (b == NULL || i == 0)
		return (NULL);

	if (stat(b[0], &veri) == 0)
		return (b);
	else
	{
		path = _getpath();
		tokens = strtok(path, ":");
		while (tokens != NULL)
		{
			while (tokens[j] != '\0')
				j++;
			buf = _calloc((j + 2), sizeof(char));
			if (buf == NULL)
			{
				perror("No memory");
				exit(EXIT_FAILURE);
			}
			for (k = 0; k < j; k++)
				buf[k] = tokens[k];
			buf[k] = '/';
			valor = str_concat(buf, b[0]);
			if (stat(valor, &veri) == 0)
			{
				b[0] = _realloc2(buf, b[0], i, _strlen(valor));
				free(path);
				free(buf);
				free(valor);
				return (b);
			}
			tokens = strtok(NULL, ":");
			j = 0;
			free(buf);
			free(valor);
		}
		free(path);
		return (b);
	}
}
