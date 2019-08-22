#ifndef _HOLBY
#define _HOLBY

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

/*global variables*/
int loopin;
int err;
extern char **environ;

/* shell functions*/
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char *_getline(void);
char **parsing(char *line);
char *_getline_av(void);
void free_grid(char **grid, int height);
void _forky(char **p, char *line, int a);
void *_calloc(unsigned int nmemb, unsigned int size);
char **checkbin(char **b);
void *_realloc2(char *a, char *p, unsigned int old_size, unsigned int new_size);
void _isexit(char **p);
void _signal(int s);
int _isenv(char **p);
void _env(char *p);
int _cd(char **a);
int _iscd(char **p);
char *_gethome(void);
char *_getpwd(void);
int _atoi(char *s);

/* errors */
void _put_err(char **p);
void _builtinerr(char **p);
#endif
