#include "main.h"

/**
 * _freepathlist - Frees a Path_List_t list.
 * @head: Head of linked list of Path_List_t nodes.
 *
 * Return: Void.
 */
void _freepathlist(Path_List_t *head)
{
	Path_List_t *current;

	current = head;
	while (current != NULL)
	{
		current = current->next;
		free(head->dir);
		free(head);
		head = current;
	}
}
