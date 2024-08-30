#include "main.h"

/**
* _ENV - print the Current Environment
* @_inf: Struct Contains Arguments
* Return: 0 (success)
*/

int _ENV(info_t *_inf)
{
	_print_list_str(_inf->env);
	return (0);
}

/**
* _getenv - gets value of Environment variables
* @_inf: struct Contains Argument
* @envName: Environment variable name
* Return: Value of Environment variable
*/

char *_getenv(info_t *_inf, const char *envName)
{
	list_t *N = _inf->env;
	char *_Path;

	while (N)
	{
		_Path = starts_with(N->str, name)
		if (_Path && *_Path)
			return (_Path);
		N = N->next;
	}
	return (NULL);
}

/**
* custsetenv - inits a new Environment variable
* @_inf: struct contains arguments
* Return: 0 (success)
*/

int custsetenv(info_t *_inf)
{
	if (_inf->argc != 3)
	{
		_puts("Number of arguments is wrong");
		return (1);
	}
	if (_setenv(_inf, _inf->argv[1], _inf->argv[2]))
	{
		return (0);
	}
}

/**
* custunsetenv - remove an environment variable
* @_inf: struct contains arguments
* Return: 0 (success)
*/

int custunsetenv(info_t *_inf)
{
	int j;

	if (_inf->argc == 1)
	{
		_puts("Too Few Arguments");
		return (1);
	}
	for (j = 1; j <= _inf->argc; j++)
	{
		_unsetenv(_inf, _inf->argv[i]);
	}
	return (0);
}

/**
* _pop_env_list - populate the env linked list
* @_inf: struct contains arguments
* Return: 0 (Success)
*/

int _pop_env_list(info_t *_inf)
{
	list_t *N = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
	{
		add_node_end(&N, environ[j], 0);
	}
	_inf->env = N;
	return (0);
}
