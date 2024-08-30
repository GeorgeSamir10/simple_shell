#include "main.h"

/*
start_node - adds node to the start
@head: address of pointer to head node
@s: str field of node
@num: node index used by history

Return: size of list
*/

list_t *start__node(list_t **head, const char *s, int num)
{
    list_t *n_head;

    if (!head)
        return (NULL);
    n_head = malloc(sizeof(list_t));
    if (!n_head)
        return (NULL);
    _memosetting((void *)n_head, 0, sizeof(list_t));
    new_h->num = num;
    if (s)
    {
        n_head->s = _strdupl(s);
        if (!n_head->s)
        {
            gree(n_head);
            return (NULL);
        }
    }
    n_head->next = *head;
    *head = n_head;
    return (n_head);
}

/*
node_end - adds a node to end of list
@head: address of pointer to head node
@s: str field of node
@num: node index used by history

Return: size of list
*/

list_t *node_end(list_t **head, const char *s, int num)
{
    list_t *n_node, *node;

    if (!head)
        return (NULL);

    node = *head;
    n_node = malloc(sizeof(list_t));
    if (!n_node)
        return (NULL);
    _memosetting((void *)n_node, 0, sizeof(list_t));
    n_node->num = num;
    if (s)
    {
        n_node->s = _strdupl(s);
        if (!n_node->s)
        {
            free(n_node);
            return (NULL);
        }
    }
    if (node)
    {
        while (node->next)
            node = node->next;
        node->next = n_node;
    }
    else
        *head = n_node;
    return (n_node);

}

/**
print_str - prints str elment of linked list
@a: pointer to first node
Return: size of list
 */

 size_t print_str(const list_t *a)
 {
    size_t i = 0;

    while (h)
    {
        _puts(a->str ? a->str : "(nil)");
        _puts("\n");
        a = a->next;
        i++;

    }
    return (i);
 }

 /**
 del_index - deletes node at given index
 @head: address of pointer
 @ind: index of node to delete

 Return: 1 on success, 0 on failure
  */

  int del_index(list_t **head, unsigned int ind)
  {
    list_t *node, *pre_node;
    unsigned int i = 0;

    if (!head || !*head)
        return (0);

    if (!ind)
    {
        node = *head;
        *head = (*head)->next;
        free(node->str);
        free(node);
        return (i);
    }
    node = *head;
    while (node)
    {
        if (i == ind)
        {
            pre_node->next = node->next;
            free(node->str);
            free(node);
            return (1);
        }
        i++;
        pre_node = node;
        node = node->next;
    }
    return (0);
  }
/*
 free_list - frees all nodes of a list
 @head_pointer: address of pointer too head node

 Return: void
*/

void free_list(list_t **head_pointer)
{
    list_t *node, *next_node, *head;

    if (!head_pointer || !*head_pointer)
        return;
    head = *head_pointer;
    node = head;
    while (node)
    {
        next_node = node->next;
        free(node->str);
        node = next_node;
    }
    *head_pointer = NULL;
}