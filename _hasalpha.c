#include "main.h"
/**
 * _hasalpha - function to check whther the string has letters or not
 * used for exit builtin function
 * @s: the string to be checked
 * Return: 0 if it does not,  1if it does.
*/
int _hasalpha(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
			return (1);

		i++;
	}
	return (0);
}
