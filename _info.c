#include "main.h"

/**
* _clrinf - initialize info_t struct
* @_inf: struct address
* Return: nothing
*/

void _clrinf(info_t *_inf)
{
	_inf->arg = NULL;
	_inf->argv = NULL;
	_inf->path = NULL;
	_inf->argc = 0;
}

/**
* _setinf - init info_t struct
* @_inf: struct address
* @av: argument vector
* Return: nothing
*/

void _setinf(info_t *_inf, char **av)
{
	int j = 0;

	_inf->fname = av[0];

	if (_inf->arg)
	{
		_inf->argv = strtow(_inf->arg, " \t");
		if (!_inf->argv)
		{
			_inf->argv = malloc(sizeof(char *) * 2);
			if (_inf->argv)
			{
				_inf->argv[0] = _strdupl(_inf->arg);
				_inf->argv[1] = NULL;
			}
		}
		for (j = 0; _inf->argv && _inf->argv[j]; j++)
			;
		_inf->argc = j;

		replace_alias(_inf);
		replace_vars(_inf);
	}
}

/**
* _frinf - frees info_t fields
* @_inf: struct address
* @fields: true if all fields cleared
* Return: nothing
*/

void _frinf(info_t *_inf, int fields)
{
	ffree(_inf->argv);
	_inf->argv = NULL;
	_inf->path = NULL;

	if (fields)
	{
		if (!_inf->cmd_buf)
			free(_inf->arg);
		if (_inf->history)
			free_list(&(_inf->history));
		if (_inf->env)
			free_list(&(_inf->env));
		if (_inf->alias)
			free_list(&(_inf->alias));
		ffree(_inf->environ);
			_inf->environ = NULL;
		bfree((void **)_inf->cmd_buf);
		if (_inf->readfd > 2)
			close(_inf->readfd);
		_putchar(BUF_FLUSH);
	}
}
