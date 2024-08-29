#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


extern char **environ;

void _prompt(void);
void _myprint(const char *text);
void _input(char *_mycmd, size_t inSize);
void _executing(const char *_mycmd);
char *_getenv(const char *name);

#endif /* MAIN_H */
