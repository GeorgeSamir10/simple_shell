#include "main.h"

/**
_strlength - returns length of string
@s: the string to check
Return: int length of s
*/

int _strlength(char *s)
{
    int i = 0;

    if (!s)
        return (0);

    while (*s++)
        i++;
    return (i);
}

/**
_strcmp - performs lexicograpic coomparison
@s1: the first string
@s2: the second string
Return: 0 if s1 == s2, -1 s1 < s2, 1 if s2 > s1
 */

 int _strcmp(char *s1, char *s2)
 {
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
                return (*s1 - *s2);
        s1++;
        s2++;
    }
    if (*s1 == *s2)
        return (0);
    else
        return (*s1 > *s2 ? 1 : -1);
 }

 /**
 star - shecks if key starts with a
 @a: str
 @key: the substr
 
 Return: address of next char of key or NUL
 */

 char *star(const char *key, const char *a)
 {
    while (*a)
        if (*a++ != *key++)
            return (NULL);
    return ((char *)key);
 }
/**
_strcon - concatenates two strings
@dest: the destination buffer
@src: the source buffer
Return: pointer to distenation buffer
*/

char *_strcon(char *dest, char *src)
{
    char *retrieve = dest;

    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = *src;
    return (retrieve);
}