#include "main.h"
/**
 * _strcmp - function that compares 2 strings lexicographically
 * @str1: first string to be compared.
 * @str2: second string to be compared.
 *
 * Description: compare strings in many different
 *
 * Return: 0 is they are equal, 1 if str1 is greater, -1 if str2 is greater
*/
int _strcmp(char *str1, char *str2)
{
	int i, res, strlen1 = _strlen(str1), strlen2 = _strlen(str2);

	if (strlen1 == strlen2)
	{
		for (i = 0; i < strlen1; i++)
		{
			if (str1[i] > str2[i])
				return  (1);
			else if (str1[i] < str2[i])
				return  (-1);
		}
		res = (0);
	}
	else
	{
		if (strlen1 > strlen2)
		{
			for (i = 0; i < strlen2 ; i++)
			{
				if (str1[i] > str2[i])
					return  (1);
				else if (str1[i] < str2[i])
					return  (-1);
			}
			res = (1);
		}
		else if (strlen1 < strlen2)
		{
			for (i = 0; i < strlen1 ; i++)
			{
				if (str1[i] > str2[i])
					return  (1);
				else if (str1[i] < str2[i])
					return  (-1);
			}
			res = (-1);
		}
	}
	return (res);
}
