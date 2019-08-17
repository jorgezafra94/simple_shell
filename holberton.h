#ifndef _HOLBY_GAY_
#define _HOLBY_GAY_

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

#endif
