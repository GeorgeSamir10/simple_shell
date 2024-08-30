#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*read/write buffers*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*for command chaining*/
#define CMD_NORM    0
#define CMD_OR      1
#define CMD_AND     2
#define CMD_CHAIN   3

/*CONVERT NUMBER*/
#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED    2

/*using system getline*/
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE   ".simple_shell_history"
#define HIST_MAX    4096

extern char **environ;

/*string reading & handling*/
char *_strcopy(char *, char *);
char *_strdupl(const char *);
void _puts(char *);
int _putchar(char);
int _strlength(char *);
int _strcmp(char *, char *);
char *star(const char *, const char *);
char *_strcon(char *, char *);
char *_strncopy(char *, char *, int);
char *_strncon(char *, char *, int);
char *_strchr(char *, char);
char **strtow2(char *, char);
char **strtow(char *, char *);

/*memory functions*/
char *_memosetting(char *, char, unsigned int);
void sfree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int pfree(void **);

/*more functions*/
int active_shell(info_t *);
int is_delim(char , char *);
int _isalphabetic(int);
int convert_stoi(char *);
int errstoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_num(long int, int, int);
void rm_comments(char *);

#endif /*MAIN_H*/