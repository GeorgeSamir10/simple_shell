#include "main.h"

/**
 * _freedouble - frees an array of char * pointers.
 * @str: pointer to array of pointers.
 *
 * Return: void
 */
void _freedouble(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}
