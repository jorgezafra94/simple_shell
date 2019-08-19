#ifndef _HOLBY
#define _HOLBY

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char *_getline(void);
char **parsing(char *line);
char *_getline_av(void);
void free_grid(char **grid, int height);
void _forky(char **p, char *line, int a);
void *_calloc(unsigned int nmemb, unsigned int size);
char **checkbin(char **b);
void *_realloc2(char *ptr, unsigned int old_size, unsigned int new_size);
void _isexit(char *p);
void _signal(int s);

void _env(char **environ);

#endif
