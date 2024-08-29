#include "main.h"


/**
 * main - main entry point for our progra
 * @argc: Argument count to the main
 * @argv: pointer to array of argument values
 *
 * Return: return 0 success, otherwise return 1
 *
 */

int main()
{
	char input[MAX_LINE_LENGTH];
	// char* args[MAX_ARGS];.
	int status;

    if (i >= MAX_ARGS) 
	{
		fprintf(stderr, "Too many arguments\n");
		continue;
    }

	while (1)
	{
		fgets(input, MAX_LINE_LENGTH, stdin);

		/* tokenize the input*/
	    int i = 0;

		args[i] = strtok(input, "\n");
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, "\n");

		}
		args[i] = NULL;

		/*builtin commands*/
		if (strcmp(args[0], "cd") == 0)
		{
			chdir(args[1]);
			continue;

		}
		else if (strcmp(args[0], "exit") == 0)
		{
			exit(0);
		
		}

		/* child process*/
		pid_t pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			exit(1);

		}

		else if (pid == 0)
		{
			/*child*/gcc -Wall -Wextra -pedantic *.c -o shell && ./shell
			execvp(args[0], args);
			perror("ecexution fail");
		}

		else 
		{
			/* parent*/
			waitpid(pid, &status, 0);
		}
	}
	return 0;

	}
