#include "main.h"

/**
* _myprint - prints a text to the standard output
* @text: text that will be printed
* Return: Nothing
*/

void _myprint(const char *text)
{
	write(STDOUT_FILENO, text, _strlen(text));
}

/**
* _Strlen - it gives string length
* @s: pointer to string
* Return: length of string
*/
int _Strlen(char *s)
{
	int j = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (j);
}
