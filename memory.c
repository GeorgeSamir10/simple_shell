#include "main.h"

/**
 * *_memosetting - fills memory wirh const byte
 * @Str: pointer to memory area
 * @byte: byte to fill *s with
 * @n: amoount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */

 char *_memosetting(char *str, char byte, unsigned int n)
 {
    unsigned int i;

    for (i = 0; i < n; i++)
        str[i] = byte;
    return (str);
 }

 /**
 * sfree - frees string from other strings
 * @sos: string of strings
 */

 void sfree(char **sos)
 {
    char **a = sos;

    if (!sos)
        return;
    while (*sos)
        free(*sos++);
    free(a);
 }

 /**
 * _realloc - reallocates memory location
 * @ptr: pointer to previous location
 * @OS: bytes size of previous block
 * @NS: bytes size of new block
 * Return: pointer to new allocated memory
 */

 void *_realloc(void *ptr, unsigned int OS, unsigned int NS)
 {
    char *c;

    if(!ptr)
        return (malloc(NS));
    if (!NS)
        return (free(ptr), NULL);
    if (NS == OS)
        return (ptr);

    c = malloc(NS);
    if (!c)
        return (NULL);

    OS = OS < NS ? OS : NS;
    while (OS--)
        c[OS] = ((char *)ptr) [OS];
    free(ptr);
    return (c);    
 }