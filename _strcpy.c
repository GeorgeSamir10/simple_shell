#include "main.h"

/**
 * _strcpy - copies the string pointed by source to the destination.
 * @_destin: destination string.
 * @_src: source string.
 * Return: char pointer to copied string.
 */
char *_strcpy(char *_destin, char *_src)
{
	int i = 0;

	while (_src[i] != '\0')
	{
		_destin[i] = _src[i];
		i++;
	}
	_destin[i] = '\0';
	return (_destin);
}
