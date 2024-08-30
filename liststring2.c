#include "main.h"

/**
*list_len - returns length of linked list
*@l: pointer to first node
*Return: size of list
*/

size_t list_len(const list_t *l)
{
	size_t i = 0;

	while (l)
	{
		l = l->next;
		i++;
	}
	return (i);
}


/**
*ltos - returns an array of strings of list->str
*@head: pointer to first node
*Return: array of strings
*/

char **ltos(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!str)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlength(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
	str = _strcopy(str, node->str);
	strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
*print_l - prints all elements of list_t linked list
*@h: pointer to first node
*Return: size of list
*/

size_t print_l(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_putchar("\n");
		h = h->next;
		i++;

	}
	return (i);
}

/**
*node_start - returns node which string starts with prefix
*@node: pointer to list head
*@prefix: string to match
*@c: the next character after prefix
*Return: match or NULL
*/

list_t *node_start(list_t *node, char *prefix, char c)
{
	char *n = NULL;

	while (node)
	{
	n = starts_with(node->str, prefix);
	if (n && ((c == -1) || (*n == c)))
		return (node);
	node = node->next;
	}
	return (NULL);
}

/**
*get_ind - gets the index of node
*@head: pointer to head
*@node: pointer to node
*Return: index of node or -1
*/

ssize_t get_ind(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

