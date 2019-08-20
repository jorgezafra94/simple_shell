#include "shell.h"

/**
 * _gethome - funtion to get env HOME
 * @environ: points to an array of pointers to strings called the "environment"
 */
char *_gethome(void)
{
	int i, j, k;
	char str[] = "HOME=";
	char home[] = {0};

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			if (environ[i][j] != str[j])
				break;
			if(environ[i][j] == str[j])
			{
				cont++;
			}
			if (cont == 5)
				break;
		}
		if (cont == 5)
			break;
	}

	for (k = cont; environ[i][k]!= '\0'; k++)
	{
		home[k - cont] = environ[i][k];
	}
	home[k - cont] = '\0';
	return (home);
}
