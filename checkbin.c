#include "shell.h"
/**
  *
  *
  *
  */
char *_getpwd(void)
{
        int i, j, k = 0, cont = 0;
        char str[] = "PWD=";
        char *pwd;

        for (i = 0; environ[i] != NULL; i++)
        {
                for (j = 0; environ[i][j] != '\0'; j++)
                {
                        if (cont == 4)
                                break;
                        if (environ[i][j] == str[j])
                                cont++;
                        else
                                break;
                }
                if (cont == 4)
                        break;
        }
        while (environ[i][k] != '\0')
                k++;
        pwd = _calloc(k + 1, sizeof(char));
	if (pwd == NULL)
		return (NULL);
        k = 4;
        while (environ[i][k] != '\0')
        {
                pwd[k - 4] = environ[i][k];
                k++;
        }
        return (pwd);
}

/**
 *
 *
 *
 */
char *_verifypath(char *path, char *pwd)
{
	char *newpath = NULL, *str1 = NULL, *str2 = NULL;
	char dosp = ':';
	int cont, pa, pw, k1, k2;

	if (path == NULL || pwd == NULL)
		return (NULL);

	for (pw = 0; pwd[pw] != '\0'; pw++)
		;
	for (pa = 0; path[pa] != '\0'; pa++)
		;
	for (cont = 0; path[cont] != '\0'; cont++)
	{
		if (path[0] == dosp)
		{
			newpath = str_concat(pwd, path);
			free(pwd);
			free(path);
			return (newpath);
		}
		else if(path[cont] == dosp && path[cont + 1] == dosp)
		{
			str1 = _calloc(pa + 1, sizeof(char));
			if (!str1)
				return(NULL);
			str2 = _calloc(pa + 1, sizeof(char));
			if (!str2)
				return(NULL);
			for (k1 = 0; k1 <= cont; k1++)
				str1[k1] = path[k1];
			for (k2 = 0; path[k1] != '\0'; k2++, k1++)
				str2[k2] = path[k1];
			newpath = str_concat(pwd, str2);
			newpath = str_concat(str1, newpath);
			free(str1);
			free(str2);
			free(pwd);
			free(path);
			return (newpath);
		}
	}
	free(pwd);
	return (path);
}
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
	if (path == NULL)
		return (NULL);
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
	char *path, *tokens, *buf, *pwd, *newpath;
	char *valor;

	i = _strlen(b[0]);
	if (b == NULL || i == 0)
		return (NULL);

	path = _getpath();
	pwd = _getpwd();
	newpath = _verifypath(path,pwd);
	/*printf("this is the new path %s\n", newpath);*/
	tokens = strtok(newpath, ":");
	if (!tokens)
		return (NULL);
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
			free(buf);
			free(valor);
			free(newpath);
			return (b);
		}
		tokens = strtok(NULL, ":");
		j = 0;
		free(buf);
		free(valor);
	}
	free(newpath);
	if (stat(b[0], &veri) == 0)
		return (b);
	return (b);
}
