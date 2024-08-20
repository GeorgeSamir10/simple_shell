#include "main.h"


/**
 * main - main entry point for our progra
 * @argc: Argument count to the main
 * @argv: pointer to array of argument values
 *
 * Return: return 0 success, otherwise return 1
 *
 */

int main(int argc, char *argv[])
{
	(void)argc, (void)argv;

	char *in;
	size_t len = 0;
	ssize_t input;

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
