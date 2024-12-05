#include "main.h"
/**
 * _strdup - duplicate sthe string into another pointer that is
 * dynamically allocated
 * @str: the string to be duplicated
 * Return: the pointer to the string that is a copy
*/
char *_strdup(char *str)
{
	char *copy;
	int _length, i;

	_length = _strlen(str);
	copy = malloc((sizeof(char) * _length) + 1);
	for (i = 0; i <= _length; i++)
	{
		copy[i] = str[i];
	}
	return (copy);
}
