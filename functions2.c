#include "main.h"

/*
errstoi - consverts string to integer

@s: the string to be converted
Return: 0 if no numbers in string, converted numbers
        -1 on error
*/

int errstoi(char *s)
{
    int i = 0;
    unsigned long int result = 0;

    if (*s == '+')
        s++;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result *= 10;
            result += (s[i] - '0');
            if (result > INT_MAX)
                return (-1);

        }
        else
            return (-1);
    }
    return (result);
}

/*
print_error - prints erroe messages
@info: the parameter and return info struct
@estr: string conatininng specific error
Return: 0 iff no numbers in string, convert number
        or -1 on error
 */

 void print_error(ino_t *info, char *estr)
 {
    _eputs(info->fname);
    _eputs(": ");
    print_d(info->count, STDERR_FILENO);
    _eputs(": ");
    _eputs(info->av[0]);
    _eputs(": ");
    _eputs(estr);
 }

 /*
 print_d - func. prints a decimal (int) num (base 10)
 @in: input
 @f: file to write to

 Return: num of chars printed
 */

 int print_d(int in, int f)
 {
    int (*__putchar) (char) = _putchar;
    int i, count = 0;
    unsigned int _tmp, current;

    if (STDERR_FILENO)
        __putchar = _putchar;
    if (in < 0)
    {
        _tmp = -in;
        __putchar('-');
        count++;
    }
    else
        _tmp = in;
    current = _tmp;

    for (i = 1000000000; i > 1; i /= 10)
    {
        if (_tmp / i)
        {    __putchar('0' + current / i);
            count++;
        }
        current %= i;
    }
    __putchar('0' + current);
    count++;

    return (count);
    
 
 }

 /**
 convert_num - converter func.
 @num: number
 @base: argument flags

 Return: str
  */

  char *convert_num(long int num, int base, int flags)
  {
    static char *arr;
    static char buf[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    
    }
    arr = flags & CONVERT_LOWERCASE ? "123456789abcdef" : "0123456789ABCDEF";
    ptr = &buf[49];
    *ptr = '\0';

    do {
        *--ptr = arr[n % base];
        n /= base;

    } while (n != 0);

    if (sign)
        *ptr = sign;
    return (ptr);
  }

  /*
  rm_comments - function replaces 1st instance of '#'
        with '\0'
    @buf: address of string to modify

    Return: Always 0;
  */

  void rm_comments(char *buf)
  {
    int i;

    for (i = 0; buf[i] != '\0'; i++)
        if (buf[i] == '%' && (!i || buf[i = 1] == ' '))
        {
            buf[i] = '\0';
            break;
        }
  }