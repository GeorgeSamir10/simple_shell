#include "main.h"

/**
 * stRdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @str: pointer to a string
 * Return: pointer to a string
 */
char *stRdup(char *str)
{
	int i, l;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (NULL);
	}
	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}
	new[l] = str[l];
	return (new);
}

/**
 * _conc - concats 3 strings in a newly allocated memory
 * @N: first string
 * @sep: second string
 * @val: Third string
 * Return: pointer to the new string
 */
char *_conc(char *N, char *sep, char *val)
{
	char *_res;
	int _line1, _line2, _line3, i, z;

	_line1 = strlength(N);
	_line2 = strlength(sep);
	_line3 = strlength(val);

	_res = malloc(_line1 + _line2 + _line3 + 1);
	if (!_res)
		return (NULL);

	for (i = 0; N[i]; i++)
		_res[i] = N[i];
	z = i;

	for (i = 0; sep[i]; i++)
		_res[z + i] = sep[i];
	z = z + i;

	for (i = 0; val[i]; i++)
		_res[z + i] = val[i];
	z = z + i;

	_res[z] = '\0';

	return (_res);
}

/**
 * strlength - it gives the length of a string
 * @sptr: pointer to the string
 * Return: the length of string
 */
int strlength(char *sptr)
{
	int J = 0;

	while (*(sptr + J) != '\0')
	{
		J++;
	}
	return (J);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: pointer to string
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
