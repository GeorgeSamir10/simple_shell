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
 * @h: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */

list_path *nodeend(list_path **h, char *str)
{

	list_path *_temp;
	list_path *_N;

	_N = malloc(sizeof(list_path));

	if (!str || !_N)
	{
		return (NULL);
	}

	_N->dir = str;

	_N->p = '\0';
	if (!*h)
	{
		*h = _N;
	}
	else
	{
		_temp = *h;

		while (_temp->p)
		{

			_temp = _temp->p;
		}

		_temp->p = _N;
	}

	return (*h);
}


/**
 * _linkP - creates a linked list for path directories
 * @path: string of path value
 * Return: pointer to the created linked list
 */
list_path *_linkP(char *path)
{
	list_path *head = '\0';
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
char *_FPATH(char *filename, list_path *head)
{
	struct stat st;
	char *string;

	list_path *_temp = head;

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
void _FLST(list_path *head)
{
	list_path *_store;

	while (head)
	{
		_store = head->p;
		free(head->dir);
		free(head);
		head = _store;
	}

}
