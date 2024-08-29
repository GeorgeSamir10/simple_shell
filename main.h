#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stddef.h>


extern char **environ;

void _prompt(void);
void _myprint(const char *text);
void _input(char *_mycmd, size_t inSize);
void _executing(const char *_mycmd);
char *_getenv(const char *name);

 /* int _putchar(char c); */
 /* int _puts(char *str); */
int _strlen(char *s);
#endif /* MAIN_H */
