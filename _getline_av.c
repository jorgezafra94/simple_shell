#include "holberton.h"
/**
 * _getline - function to read what the user writes
 */
char  *_getline_av(void)
{
	char s, *buffer;
	int pos = 0, size = 1024, r = 1, w = 0;

	
        buffer = malloc(sizeof(char) * size);
	if (!buffer)
	{
		perror("Error: There is not enough space");
	        exit(EXIT_FAILURE);
	}
	while (r != 0)
	{
		write(STDOUT_FILENO,"$ ", 2);
		r = read(STDIN_FILENO, buffer, 1024);
		if (r == -1)
		{
                        perror("Error: Can't read from file");
			exit(98);
                }
		pos = pos + r;
		if (pos >= size)
		{
			buffer = _realloc(buffer, size, (1024 + size));
			if (buffer == NULL)
			{
			        perror("Error: There is not enough space");
				exit(EXIT_FAILURE);
			}
			size += 1024;
		}
	}
	return (buffer);
}
