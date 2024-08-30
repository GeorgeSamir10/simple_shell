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

/* read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM    0
#define CMD_OR      1
#define CMD_AND     2
#define CMD_CHAIN   3

/* CONVERT NUMBER */
#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED    2

/* using system getline */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE   ".simple_shell_history"
#define HIST_MAX    4096

extern char **environ;



/**
* struct liststr - singly linked list
* @str: string
* @num: the number field
* @next: points to the next node
*/
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
*struct passinfo - contains arguments to pass to functions
*@arg: string from getline
*@argv: array genereted from args
*@argc: argument count
*@path: string path for command
*@line_count: error count
*@err_num: error code for exit
*@linecount_flag: line of input when on count
*@fname: program file name
*@env: local copy of environ
*@environ:custom modifed copy of environ
*@history: history node
*@env_changed: on if environ was changed
*@alias: alias node
*@status: return status of last exec
*@cmd_buf: address of pointer to cmd buf
*@cmd_buf_type: cmd_type
*@readfd: the fd from which line reads
*@histcount: history number count
*/

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL \
	0, 0, NULL, 0, 0, 0}


/**
* struct builtin - contains builtin string and functions
* @type: builtin command flag
* @func: the function
*/

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;



/* string reading & handling */
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

/* memory functions */
char *_memosetting(char *, char, unsigned int);
void sfree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int pfree(void **);

/* more functions */
int active_shell(info_t *);
int is_delim(char, char *);
int _isalphabetic(int);
int convert_stoi(char *);
int errstoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_num(long int, int, int);
void rm_comments(char *);

/* linked list handling */
list_t *start__node(list_t **, const char *, int);
list_t *node_end(list_t **, const char *, int);
size_t print_str(const list_t *);
int del_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **ltos(list_t *);
size_t print_l(const list_t *);
list_t *node_start(list_t *, char *, char);

/* Environment Functions */
int _ENV(info_t *);
char *_getenv(info_t *, const char *);
int custsetenv(info_t *);
int custunsetenv(info_t *);
int _pop_env_list(info_t *);
char **_getenviron(info_t *);
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);

/* file i/o manapulation functions */
char _gethistoryfile(info_t *);
int _writehistory(info_t *);
int _readhistory(info_t *);
int _buildhistorylist(info_t *, char *, int);
int _renumberhistory(info_t *);

/* info functions */
void _clrinf(info_t *);
void _setinf(info_t *, char **);
void _frinf(info_t *, int);

/* error string functions */
void _eputs(char *);
int _eputchar(char);
int _putfd(char, int);
int _putsfd(char *, int);


#endif /* MAIN_H */
