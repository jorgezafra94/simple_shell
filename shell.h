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
extern char **environ;

/* shell functions*/
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char *_getline(int *a);
char **parsing(char *line);
/*char _getline_av(char *buffer);*/
void free_grid(char **grid, int height);
void _forky(char **p, char *line, int a, int loop);
void *_calloc(unsigned int nmemb, unsigned int size);
char **checkbin(char **b);
void *_realloc2(char *a, char *p, unsigned int old, unsigned int new_size);
void _isexit(char **p, int loop, char *line, int i);
void _signal(int s);
int _isenv(char **p);
void _env(char *p);
int _cd(char **a, int loop);
int _iscd(char **p, int loop);
char *_gethome(void);
char *_getpwd(void);
int _atoi(char *s);
char *_strtoky(char *s, char *d);

#define SIZE 1024

/* help files*/
void _ishelp(char **p, int loop);
void _builtinhelp(char **p, int loop);
ssize_t read_cdhelp(void);
ssize_t read_exithelp(void);
ssize_t read_helphelp(void);

/* errors */
void _put_err(char **p, int loop);
void _builtinerr(char **p);
void _errorcd(char **p);
void _errorexit(char **p);
void _errorhelp(char **p);

#endif
