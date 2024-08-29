#include "main.h"

/**
* _myprint - prints a text to the standard output
* @text: text that will be printed
* Return: Nothing
*/

void _myprint(char *text)
{
	write(STDOUT_FILENO, text, _strlen(text));
}

/**
* _strlen - it gives string length
* @s: pointer to string
* Return: length of string
*/
int _strlen(char *s)
{
	int j = 0;

	while (*(s + j) != '\0')
	{
		j++;
	}
	return (j);
}
