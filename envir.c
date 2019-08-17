#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int arg, char *argv[])
{
	char *args[] = {"Hello", "World", NULL};
	printf("run newprogram\n");
	execv("./np", args);
	return (0);
}
