#include "main.h"


/**
 * main - entry point for our program
 *
 * Return: return 0 success, otherwise return 1
 */

int main(void)
{
	char userCommand[120];

	while (1)
	{
		_prompt();
		_input(userCommand, sizeof(userCommand));
		_executing(userCommand);
	}
	return (0);
}
