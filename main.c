#include "main.h"

/**
 * execute_command - creates a child process and executes command.
 * @args: array of argument strings to command.
 * @exitstatus: pointer to the exitstatus of program.
 *
 * Return: void.
 */
void execute_command(char **args, int *exitstatus)
{
	pid_t pid;
	int _stat;

	pid = fork();
	if (pid == -1)
	{
		perror(args[0]);
		_freedouble(args);
		return;
	}
	else if (pid == 0)
	{
		execve(args[0], args, environ);
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &_stat, 0);
		*exitstatus = WEXITSTATUS(_stat);
		_freedouble(args);
	}
}

/**
 * initargs - reads input string from stdin
 * and creats the args string array.
 * @linenum: number of lines inputed so far.
 * @exitstatus: pointer to the exitstatus int
 * for the program.
 * @fd: filedescriptor to initialize from args from.
 * Return: double pointer to the args array.
 */
char **initargs(int *linenum, int *exitstatus, int fd)
{
	char **args = NULL, *input = NULL;
	size_t size;
	ssize_t readbytes;
	int i;

	readbytes = _getline(&input, &size, fd);
	if (readbytes == -1)
	{
		if (fd != STDIN_FILENO)
			close(fd);
		_freedouble(environ);
		free(input);
		exit(*exitstatus);
	}
	if (input[0] == '\n' || input[0] == ';' || input[0] == '#')
	{
		free(input);
		return (NULL);
	}
	for (i = 0; input[i] != '\n' && input[i] != ';' && input[i] != '\0';)
		i++;
	if (input[i] == '\n' || input[i] == '\0')
		(*linenum)++;
	input[i] = '\0';
	args = _strtolist(input, ' ');
	handledollar(args, exitstatus);
	handlecomments(args, exitstatus);
	free(input);
	return (args);
}

/**
 * looprun - runs interactive REPL loop for the shell.
 * @prog: name of the running shell.
 * @exitstatus: address to the exitstatus int of the
 * program.
 * @fd: filedescriptor to run command from.
 * Return: exit status of a loop.
 */
void looprun(char *prog, int *exitstatus, int fd)
{
	char **args = NULL;
	int _builtinF, _foundF = 0, _absoluteF;
	static int linenum;

	args = initargs(&linenum, exitstatus, fd);
	if (args == NULL || args[0] == NULL)
		return;
	_builtinF = built_in(args, exitstatus, linenum, prog);
	if (_builtinF == 1)
	{
		_freedouble(args);
		return;
	}
	_absoluteF = check_absolute_path(args, exitstatus, prog, linenum);
	if (_absoluteF == 1)
		return;
	_foundF = find_in_PATH(args, exitstatus, prog, linenum);
	if (_foundF == 1)
		return;
	_freedouble(args);
}

/**
 * main - entry point.
 * @argc: number of arguments.
 * @argv: pointer to string array
 * of arguments.
 *
 * Return: 0 on success
 * on error, a different value.
 */
int main(int argc, char **argv)
{
	int interactiveflag = 0, fd = STDIN_FILENO;
	static int exitstatus;

	environ = initenv();
	exitstatus = 0;
	if (argc == 2)
		fd = _readfile(argv);
	else if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		interactiveflag = 1;
	while (1)
	{
		if (interactiveflag)
			_putstr("Shell_Prompt$ ");
		looprun(argv[0], &exitstatus, fd);
	}
	return (exitstatus);
}
