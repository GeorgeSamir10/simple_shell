#include "main.h"
/**
 * pfree - frees a pointer
 * @ptr: address of the pointer to free
 * Return: 1 if freed, 0 otherwise
 */

int pfree(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return (1);
    }
    return (0);
}