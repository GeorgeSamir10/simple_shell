#include "main.h"

/**
 * shell_launch - launches the process into the shell
 * @argv: number of given arguments
 *
 * Return: true if the child exited normally
 */

int shell_launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		//child
		if (execvp(args[0], args) ==-1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		// error forking
		perror("lsh");
	}
	else
	{
		//parent
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}

