#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;


int _putchar(char c);
void _puts(char *str);
int strlength(char *s);
char *stRdup(char *str);
char *_conc(char *N, char *sep, char *value);

char **_splitstr(char *str, const char *delimiter);
void exec(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);



void(*_checkTHEbuild(char **arv))(char **arv);
int STRTOI(char *s);
void _EXITS(char **arv);
void env(char **arv);
void settenv(char **arv);
void unsettenv(char **arv);



/**
 * struct mybuild - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

char *_getenv(const char *name);
list_path *nodeend(list_path **head, char *str);
list_path *_linkP(char *path);
char *_FPATH(char *filename, list_path *head);

void _farv(char **arv);
void _FLST(list_path *head);


#endif
