#include "shell.h"

/**
 * _signal - handle SIGINT signal
 * @s: signal to catch
 */
void _signal(int s)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		printf("Signal error: %i\n", s);
}
