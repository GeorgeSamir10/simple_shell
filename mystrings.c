#include "main.h"

/**
* _myprint - prints a text to the standard output
* @text: text that will be printed
* Return: Nothing
*/

void _myprint(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
}
