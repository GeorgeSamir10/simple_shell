#include "main.h"


/**
 * main - entry point for our program
 * @ac: Argument count to the main
 * @av: pointer to array of argument values
 *
 * Return: return 0 success, otherwise return 1
 *
 */

int main(int ac, char **av)
{
	char *in = NULL, *Token;
	size_t len = 0;
	ssize_t input;
	pid_t pid;
	int status, i;
	char **Temp;

	(void)ac, (void)av;
	in = (char *)malloc(len * sizeof(char));

	/*
	*if (in == NULL)
	*{
	*	perror("unallcoated buffer");
	*	exit(1);
	*}
	*/

	/* printf("type something"); */
	while (1)
	{
		write(STDOUT_FILENO, "shellprompt$", 13);

		input = getline(&in, &len, stdin);

		if (input == -1)
		{
			perror("Exiting Shell");
			exit(1);
		}

		Token = strtok(in, " \n");

		Temp = malloc(sizeof(char *) * 1024);
		i = 0;
		while (Token)
		{
			Temp[i] = Token;
			Token = strtok(NULL, " \n");
			i++;
		}
		Temp[i] = NULL;

		pid = fork();

		if (pid == 0)
		{
			if (execve(Temp[0], Temp, NULL) == -1)
			{
				perror("Command Not Found");
				exit(97);
			}
		}
		else if (pid < 0)
		{
			/* failed to create the child process */
			perror("failed");
			exit(41);
		}
		else
		{
			/* wait */
			wait(&status);
		}
	}

	free(in);
	return (0);
}
