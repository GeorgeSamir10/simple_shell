#include "main.h"


/**
 * _getenv - gets the value of the global variable
 * @N: name of the global variable
 * Return: string of value
 */
char *_getenv(const char *N)
{
	int x, y;
	char *_val;

	if (!N)
		return (NULL);
	for (x = 0; environ[x]; x++)
	{
		y = 0;
		if (N[y] == environ[x][y])
		{
			while (N[y])
			{
				if (N[y] != environ[x][y])
					break;

				y++;
			}
			if (N[y] == '\0')
			{
				_val = (environ[x] + y + 1);
				return (_val);
			}
		}
	}
	return (0);
}


/**
 * nodeend - adds a new node at the end of a list_t list
 * @head: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */

list_path_t *nodeend(list_path_t **head, char *str)
{

	list_path_t *_temp;
	list_path_t *_N;

	_N = malloc(sizeof(list_path_t));

	if (!_N || !str)
	{
		return (NULL);
	}

	_N->dir = str;

	_N->p = '\0';
	if (!*head)
	{
		*head = _N;
	}
	else
	{
		_temp = *head;

		while (_temp->p)
		{

			_temp = _temp->p;
		}

		_temp->p = _N;
	}

	return (*head);
}


/**
 * _linkP - creates a linked list for path directories
 * @path: string of path value
 * Return: pointer to the created linked list
 */
list_path_t *_linkP(char *path)
{
	list_path_t *head = '\0';
	char *token;
	char *cpath = stRdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = nodeend(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * _FPATH - finds the pathname of a filename
 * @filename: name of file or command
 * @head: head of linked list of path directories
 * Return: pathname of filename or NULL if no match
 */
char *_FPATH(char *filename, list_path_t *head)
{
	struct stat st;
	char *string;

	list_path_t *_temp = head;

	while (_temp)
	{

		string = _conc(_temp->dir, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		_temp = _temp->p;
	}

	return (NULL);
}

/**
 * _FLST - frees a list_t
 *@head: pointer to our linked list
 */
void _FLST(list_path_t *head)
{
	list_path_t *_store;

	while (head)
	{
		_store = head->p;
		free(head->dir);
		free(head);
		head = _store;
	}

}
