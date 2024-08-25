#include "main.h"


/**
 * main - main entry point for our progra
 * @ac: Argument count to the main
 * @av: pointer to array of argument values
 *
 * Return: return 0 success, otherwise return 1
 *
 */

int main(int ac, char **av)
{
	char *in;
	size_t len = 0;
	ssize_t input;

	(void)ac, (void)av;
	in = (char *)malloc(len * sizeof(char));
	if (in == NULL)
	{
		perror("unallcoated buffer");
		exit(1);
	}

	printf("type something");
	while (1)
	{
		write(STDOUT_FILENO, "shellprompt$", 13);
		input = getline(&in, &len, stdin);

		if (input == -1)
		{
			perror("Exiting Shell");
			exit(1);
		}

		printf("%s", in);
	}

	free(in);
	exit(EXIT_SUCCESS);
	return (0);
}
