#include "main.h"

/*
active_shell - returns true if shell is
    in interactive mode
@info: struct address
Return: 1 if in interactive mode, 0 otherwise
*/

int active_shell(ino_t *info)
{
    return (isatty(STDIN_FILENO) && info-> <= 2);
}

/*
is_delim - checks if character is a delimeter
@c: char to check
@delim: delimiter string
Return: 1 if true, 0 if false
*/

int is_delim(char c, char *delim)
{
    while (*delim)
        if (*delim++ == c)
            return (1);
    return (0);
}

/*
_isalphabetic - checks for alphabetic char
@c: input char
Return: 1 if c is alpha, 0 if not
 */

 int _isalphabetic(int c)
 {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
 }

/*
convert_stoi - converts string to intger
@s: the string to be coonverted
Return: 0 iff no numbbers in string, converted nums otherwis

*/

int convert_stoi(char *s)
{
    int i, sign = 1, flag = 0, out;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
            sign *= -1;

        if (s[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');

        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        out = -result;
    else
        out = result;

    return (out);

}