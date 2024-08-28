#include <stdio.h>
#include <unistd.h>

/**
 * main - executing process
 *
 * Return: Always 0
 */

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	// Execution error handling
	printf("Before execution\n");

	if (execve(argv[0], argv, NULL ) == -1)
	{
		perror("Error");
	}

	printf("After execution\n");

	return (0);
}
