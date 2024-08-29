#include "main.h"

/**
* _input - Takes the input of the shell, handling line breaks and EOF.
* @mycmd: The command buffer.
* @inSize: The maximum size of the command buffer.
* Return: Nothing.
*/

void _input(char *mycmd, size_t inSize)
{
	ssize_t nread;

	nread = getline(&mycmd, &inSize, stdin);

	if (nread == -1)
	{
		_myprint("\nExiting Shell\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (mycmd[nread - 1] == '\n')
		{
			mycmd[nread - 1] = '\0';
		}
	}
}
