#ifndef _HOLBY
#define _HOLBY

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_getline(void);
char **parsing(char *line);
char *_getline_av(void);
void free_grid(char **grid, int height);
void _forky(char **p, char *line, int a);
void *_calloc(unsigned int nmemb, unsigned int size);
#endif
