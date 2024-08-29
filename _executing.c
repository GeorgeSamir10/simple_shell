#include "main.h"

/**
* _executing - executes the command given
* @_mycmd: the command given
* Return: Nothing
*/

void _executing(const char *_mycmd)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		_myprint("Error with Forking\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *av[128];
		int ac = 0;
		char *_toKen = strtok((char *)_mycmd, " \t\n");

		while (_toKen != NULL)
		{
			av[ac] = _toKen;
			_toKen = strtok(NULL, " \t\n");
			ac++;
		}
		av[ac] = NULL;
		execve(av[0], av, NULL);
		_myprint("Executing error: command not found\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
