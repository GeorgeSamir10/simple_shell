#include "main.h"

/**
 * count_dirs - Calculates the number of directories in the PATH variable.
 * @path_str: The PATH variable string.
 *
 * Return: The number of directories.
 */
int count_dirs(char *path_str)
{
	int idx, dir_count;

	for (dir_count = 1, idx = 0; path_str[idx] != '\0'; idx++)
	{
		if (path_str[idx] == ':')
		{
			dir_count++;
		}
	}
	return (dir_count);
}

/**
 * free_all - Frees the allocated memory for
 * tmp_list, tmp_str, new_node, and head.
 * @tmp: Array of strings of tokens.
 * @tmp_str: Pointer to the path string.
 * @node: Pointer to the new node.
 * @head: Pointer to the head of the list.
 *
 * Return: Void.
 */
void free_all(char **tmp, char *tmp_str, Path_List_t *node, Path_List_t *head)
{
	if (tmp)
	{
		_freedouble(tmp);
	}
	if (tmp_str)
	{
		free(tmp_str);
	}
	if (node)
	{
		free(node);
	}
	if (head)
	{
		_freepathlist(head);
	}
}

/**
 * add_path_node - Creates and adds a node to the path list.
 * @head: Pointer to the head pointer of the path list.
 * @tmp_list: Array of strings from the PATH variable.
 * @tmp_str: Pointer to the value string of the PATH variable.
 * @idx: Index of the tmp_list string to be added.
 *
 * Return: 0 on success, -1 on failure.
 */
int add_path_node(Path_List_t **head, char **tmp_list, char *tmp_str, int idx)
{
	Path_List_t *new_node, *temp;
	char *dir;

	new_node = malloc(sizeof(Path_List_t));
	if (new_node == NULL)
	{
		free_all(tmp_list, tmp_str, new_node, *head);
		return (-1);
	}
	dir = malloc(_strlen(tmp_list[idx]) + 1);
	if (dir == NULL)
	{
		free_all(tmp_list, tmp_str, new_node, *head);
		return (-1);
	}
	dir = _strcpy(dir, tmp_list[idx]);
	new_node->dir = dir;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (0);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	return (0);
}

/**
 * create_path_list - Builds a linked list of the PATH directories.
 *
 * Return: Head pointer to the first node/struct_pathdir in the linked list.
 */
Path_List_t *create_path_list(void)
{
	unsigned int dir_count, i;
	int check;
	char *path_str = _getenv("PATH"), *tmp_str, **tmp_list;
	Path_List_t *head = NULL;

	if (path_str == NULL || path_str[0] == '\0')
	{
		return (NULL);
	}
	tmp_str = malloc(_strlen(path_str) + 1);
	if (tmp_str == NULL)
	{
		return (NULL);
	}
	_strcpy(tmp_str, path_str);
	dir_count = count_dirs(tmp_str);
	tmp_list = _strtolist(tmp_str, ':');
	for (i = 0; i < dir_count; i++)
	{
		check = add_path_node(&head, tmp_list, tmp_str, i);
		if (check == -1)
		{
			return (NULL);
		}
	}
	_freedouble(tmp_list);
	free(tmp_str);
	return (head);
}
