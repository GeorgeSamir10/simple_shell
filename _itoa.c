#include "main.h"

/**
 * reverse_string - Reverses a string.
 * @str: A pointer to the string.
 *
 * Return: Void.
 */
void reverse_string(char *str)
{
	int idx, length;
	char temp;

	for (idx = 0, length = 0; str[idx] != '\0'; idx++)
		length++;
	for (idx = 0; idx < (length / 2); idx++)
	{
		temp = str[idx];
		str[idx] = str[length - idx - 1];
		str[length - idx - 1] = temp;
	}
}

/**
 * _itoa - Converts an integer value to a string.
 * @number: The integer to be converted.
 *
 * Return: A pointer to the converted string.
 */
char *_itoa(int number)
{
	int length = 0, temp, is_negative = 0, remainder, i;
	char *str;

	if (number == 0)
	{
		str = _strdup("0");
		if (!str)
			return (NULL);
		return (str);
	}
	if (number < 0)
	{
		length++;
		number = number * -1;
		is_negative = 1;
	}
	temp = number;
	while (temp)
	{
		temp = temp / 10;
		length++;
	}
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	for (i = 0; number; i++, number = number / 10)
	{
		remainder = number % 10;
		str[i] = remainder + '0';
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	reverse_string(str);
	return (str);
}
