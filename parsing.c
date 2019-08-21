#include "shell.h"
/**
 * Counter - counts the number of lim found in the input
 * @L: the input string;
 * @lim: character to find inside the L string
 * Return: number of characters found
 */
int Counter(char *L, char *lim)
{
	int ct = 0, num = 0;
	if (lim != NULL)
	{
		while (L && L[ct] != '\0')
		{
			if (L[ct] != lim[0])
			{
				if (L[ct + 1] == lim[0] || L[ct + 1] == '\0')
					num++;
			}
			ct++;
		}
	}
	return (num);
}
/**
 * parsing - create an array of pointers depending of the delimit characters
 * @line: input of the user
 * Return: an array of pointers of n size
 */
char **parsing(char *line)
{
	char *token = NULL, **p = NULL;
	int length = 0, j = 0, i = 0, buffsize = 0;

	if (line == NULL)
		exit(EXIT_FAILURE);
	buffsize = Counter(line, " ");
	p = _calloc((buffsize + 1), sizeof(char *));
	if (!p)
	{
		perror("No memory");
		exit(EXIT_FAILURE);
	}
/*store the token partition inside **p */
        token = strtok(line, " \n\0");
	if (!token)
		return (NULL);
	while (token)
	{
		while (token[length] != '\0')
			length++;
		p[j] = _calloc((length + 1), sizeof(char));
		if (p[j] == NULL)
		{
			free_grid(p, j);
			perror("No memory");
			exit(EXIT_FAILURE);
		}
/*fill the pointer with the content of token*/
		for (i = 0; i < length; i++)
			p[j][i] = token[i];
		length = 0;
		j++;
/*get the next element*/
		token = strtok(NULL, " \n\0");
	}
	p[j] = NULL;
        return (p);
}
