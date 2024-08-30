#include "main.h"

/**
* replace_ali - replaces an aliases in tokenized string
* @inf: parameter struct
* Return: 1 if replaced, 0 otherwise
*/

int replace_ali(info_t *inf)
{
    int i;
    list_t *node;
    char *p;

    for (i = 0; i < 10; i++)
    {
        node = node_starts_with(inf->alias, info->av[0], '=');
        if (!node)
            return (0);
        free(inf->av[0]);
        p = _strchr(node->str, '=');
        if (!node)
            return (0);
        p = _strdupl(p + 1);
        if (!p)
            return (0);
        inf->av[0] = p;
    
    }
    return (1);
}

/**
* replace_variables - replaces vars in the tokenized string
* @inf: parameter struct

* Return: 1 if replaced, 0 otherwise
*/

int replace_variables(info_t *inf)
{
    int i = 0;
    list_t *node;

    for (i = 0; info->av[i]; i++)
    {
        if (inf->av[i][0] != "$" || !inf->av[i][1])
            continue;

        if (!_strcmp(inf->av[i], "$?"))
        {
            replace_string(&(inf->av[i]),
                _strdupl(convert_number(inf->status, 10, 0)));
            continue;
        }
        if (!_strcmp(inf->av[i], "$$"))
        {
            replace_string(&(inf->av[i]),
                _strdupl(convert_number(getpid(), 10, 0)));
            continue;
        }
        node = node_starts_with(inf->env, &inf->av[i][1], '=');
        if (node)
        {
            replace_string(&(inf->av[i]),
                _strdupl(_strchr(node->str, '=') + 1));
                continue;
        }
        replace_string(&inf->av[i], _strdupl(""));
    }
    return (0);
}