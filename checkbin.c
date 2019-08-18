#include "shell.h"

/**
 * _strlen - length of the string
 * @str: pointer to string
 * Return: 0.
 */

unsigned int _strlen(char *str)
{
	unsigned int length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}


/**
 * checkbin - checks if arg[0] has /bin/
 * @b: 
 * Return: 0.
 */

char **checkbin(char **b)
{
	unsigned int i, j, flag = 0;
	char bin[6] = "/bin/";

	i = _strlen(b[0]);
	if (b == NULL || i == 0)
		return (NULL);
	j = 0;
	while (j < 5)
	{
		flag = 0;
		if (b[0][j] != '\0')
		{
			if (bin[j] == b[0][j])
			{
				j++;
				if (j == 5)
				{
					flag = 1;
					break;
				}
			}
		        else 
				break;
		}
		else
		{
			break;
		}
	}
	if (flag == 0)
	{
		b[0] = _realloc2(b[0], i, (i + 5));
	}
	return (b);
}
