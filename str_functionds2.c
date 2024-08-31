#include "main.h"

/**
* _strncopy - copies a string
* @dest: string destination to be copied to
* @sec: source string address
* @n: amount of chars to be copied
* Return: concatenated string
*/

 char *_strncopy(char *dest, char *src, int n)
 {
    int i, j;
    char *s = dest;

    i = 0;
    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return (s);

 }

 /**
 * _strncon - concatenates 2 strings
 * @s1: first string
 * @s2: second string
 * @n: amount of byets to be used
 * Return: concatenated string
 */

  char *_strncon(char *s1, char *s2, int n)
  {
    int i, j;
    char *s = s1;

    i = 0;
    j = 0;
    while (s1[i] != '\0')
        i++;
    while (s2[j] != '\0' && j < n)
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    if (j < n)
        s1[i] = '\0';
    return (s);
  }

  /**
  * _strchr - returns location of a character
  * @s: string tto be parsed
  * @c: char to look for
  * Return: pointer to memory of char
  */

  char *_strchr(char *s, char c)
  {
    do {
        if (*s == c)
            return (s);
    } while (*s++ != '\0');
    return (NULL);
  }