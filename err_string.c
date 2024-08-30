#include "main.h"

/*
_eputs - prints an input string
@s: printed string

Return: nothing
*/

void _eputs(char *s)
{
    int i = 0;
    if (!s)
        return;
    while (s[i] != '\0')
    {
        _eputchar(s[i]);
        i++
    }
}

/*
_eputchar - writes character to c stderr
@c: the char to print

Return: 1, -1on error
*/

int _eputchar(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write9(2, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);

}

/*
_putfd - writes char c to given fd

@c: char to print
@fd: filedescripter to write to
Return: 1, -1 on error
 */

 int _putfd(char c, int fd)
 {
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(fd, buf, i);
        i = 0;

    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
 }

 /*
 _putsfd - prints input string

 @s: string to be printed
 @fd: filedescriptor

 Return: num of chars
 */

 int _putsfd(char *str, int fd)
 {
    int i = 0;

    if (!str)
        return(0);
    while (*str)
    {
        i += _putfd(*str++, fd);
    }
    return(i);
 }