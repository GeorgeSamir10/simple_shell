#include "main.h"

/**
 * assign_mem - assigns memory space for word characters.
 * @words: the double pointer to the words array.
 * @word_count: number of words.
 * @str: the string of original words.
 * @delimiter: delimiting character.
 *
 * Return: void.
 */
void assign_mem(char **words, int word_count, char *str, char delimiter)
{
	int i, _wordlen, j;

	for (i = 0, j = 0, _wordlen = 0; str[i] != '\0'; i++)
	{
		if (j == word_count)
			return;
		if (str[i] != delimiter)
		{
			_wordlen++;
			if (str[i + 1] == delimiter || str[i + 1] == '\0')
			{
				words[j] = (char *) malloc((_wordlen + 1) * sizeof(char));
				j++;
				_wordlen = 0;
			}
		}
	}
}

/**
 * countwords - counts number of space separated words
 * in a string.
 * @str: pointer to string to be counted.
 * @delimiter: delimiteriting character.
 *
 * Return: number of words
 */
int countwords(char *str, char delimiter)
{
	int i, word_count;

	word_count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != delimiter)
		{
			if (i == 0 || str[i - 1] == delimiter)
				word_count++;
		}
	}
	return (word_count);
}
/**
 * _strtolist - splits a string into words.
 * @str: pointer to string to be split.
 * @delimiter: delimiteriting character.
 *
 * Return: a double char pointer to the array of words.
 */
char **_strtolist(char *str, char delimiter)
{
	int word_count, i, j, k;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);
	word_count = countwords(str, delimiter);
	if (word_count == 0)
		return (NULL);
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	assign_mem(words, word_count, str, delimiter);
	for (i = 0, j = 0, k = 0; str[i] != '\0'; i++)
	{
		if (str[i] != delimiter)
		{
			words[j][k] = str[i];
			k++;
			if (str[i + 1] == delimiter || str[i + 1] == '\0')
			{
				words[j][k] = '\0';
				k = 0;
				j++;
			}
		}
	}
	words[word_count] = NULL;
	return (words);
}
