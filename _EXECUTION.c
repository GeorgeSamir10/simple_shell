#include "main.h"


/**
 * _splitstr - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */

char **_splitstr(char *str, const char *delim)
{
	int i, WN;
	char **array;
	char *token;
	char *copy;

	copy = malloc(strlength(str) + 1);
	if (copy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = stRdup(token);

	i = 1;
	WN = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = _realloc(array, (sizeof(char *) * (WN - 1)), (sizeof(char *) * WN));
		array[i] = stRdup(token);
		i++;
		WN++;
	}
	free(copy);
	return (array);
}

/**
 * exec - executes a command
 * @argv: array of arguments
 */

void exec(char **argv)
{

	int D, stat;

	if (!argv || !argv[0])
		return;
	D = fork();
	if (D == -1)
	{
		perror(_getenv("_"));
	}
	if (D == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&stat);
}

/**
 * _realloc - Reallocates memory block
 * @pointer: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 * Return: New resized Pointer
 */

void *_realloc(void *pointer, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (pointer == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (pointer);

	if (new_size == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}

	new = malloc(new_size);
	old = pointer;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(pointer);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(pointer);
	}
	return (new);
}

/**
 * _farv - frees the array of pointers arv
 *@arv: array of pointers
 */

void _farv(char **arv)
{
	int j;

	for (j = 0; arv[j]; j++)
		free(arv[j]);
	free(arv);
}
