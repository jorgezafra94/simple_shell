#include "holberton.h"
/**
 * _getline - function to read what the user writes
 */
void _getline(void)
{
	char s, *buffer;
	int pos = 0, size = 1204, r = 1;

	write(STDOUT_FILENO,"$ ", 2);
        buffer = malloc(sizeof(char) * size);
	if (!buffer)
	{
	 	dprintf(STDERR_FILENO, "Error: There is no sufficient memory");
	 	exit(98);
	}

	while (1)
	{
		r = read(STDIN_FILENO, buffer, 1024);
		write(STDOUT_FILENO, buffer, 1024);
		return;
	}
}

int main (void)
{
	_getline();
	return (0);
}
