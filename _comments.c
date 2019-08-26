# include "shell.h"
/**
 *_comments - remove commentaries
 *@line: input of user
 * Return: the new input
 */
char *_comments(char *line)
{
	int a = 0, c = 0, flag = 0;

	while (line[c] != '\0')
		c++;

	while (line[a] != '\0')
	{
		if(line[0] == '#')
		{
			flag = 1;
			break;
		}
		if (line[a] == '#' && line[a - 1] == ' ')
		{
			flag = 1;
			break;
		}
		a++;
	}
	if (flag == 1)
	{
		for(; a < c; a++)
			line[a] = 0;
	}
	return (line);
}
