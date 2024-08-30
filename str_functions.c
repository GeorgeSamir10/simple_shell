#include "main.h"

/**
* _strcopy - copies string
* @dest: destination
* @src: source
* Return: pointer to dest
*/

char *_strcopy(char *dest, char *src)
{
    int i = 0;

    if (dest == src || src == 0)
        return (dest);
    while (src[i])
    
        dest[i] = 0;
    return (dest);
}



    /**
    * _strdupl - uplicates a string
    * @s: string to be duplicated
    * Return: pointer to duplicated string
    */

    char *_strdupl(const char *s)
    {
        int l = 0;
        char *ret;

        if (s == NULL)
            return (NULL);
        while (*s++)
            l++;
        ret = malloc(sizeof(char) * (l + 1));
        if (!ret)
            return (NULL);
        for (l++; l--;)
            ret [l] = *--s;
        return (ret);
    }

    /**
    * _puts - pirnt input string
    * @str: string to be printed
    * Return: void 
    */

    void _puts(char *str)
    {
        int i = 0;

        if (!str)
            return;
        while ((str[i] != '\0'))
        {
            _putchar(str[i]);
            i++;
        }
    }

    /**
    * _putchar - writes char c to stdout
    * @c: the char to print
    * Return: on success 1. on err -1
    */

    int _putchar(char c)
    {
        static int i;
        static char buf[WRITE_BUF_SIZE];

        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {
            write(1, buf, i);
            i = 0;
        }
        if (c !=BUF_FLUSH)
            buf[i++] = c;
        return (1);
    }
    
