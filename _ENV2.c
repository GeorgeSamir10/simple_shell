#include "main.h"

/**
* _getenviron - return string cpy of the environment
* @_inf: struct contains the arguments
* Return: 0 (success)
*/

char **_getenviron(info_t *_inf)
{
	if (!_inf->environ || _inf->env_changed)
	{
		_inf->environ = list_to_strings(_inf->env);
		_inf->env_changed = 0;
	}
	return (_inf->environ);
}

/**
* _setenv - inits a new Environment variable
* @_inf: Struct that contains arguments
* @var: string var env property
* @value: value of the string
* Return: 0 (Success)
*/

int _setenv(info_t *_inf, char *var, char *value)
{
	char *buff = NULL;
	list_t *N;
	char *P;

	if (!value || !var)
	{
		return (0);
	}

	buff = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, "-");
	_strcat(buff, value);
	N = _inf->env;
	while (N)
	{
		P = starts_with(N->str, var);
		if (P && *P == '=')
		{
			free(N->str);
			N->str = buff;
			_inf->env_changed = 1;
			return (0);
		}
		N = N->next;
	}
	add_node_end(&(_inf->env), buff, 0);
	free(buff);
	_inf->env_changed = 1;
	return (0);
}

/**
* _unsetenv - erase an environment varaible
* @_inf: struct contains arguments
* @var: the string env var property
* Return: string env variable property
*/

int _unsetenv(info_t *_inf, char *var)
{
	list_t *N = _inf->env;
	size_t j = 0;
	char *P;

	if (!N || !var)
		return (0);
	while (N)
	{
		P = starts_with(N->str, var);
		if (P && *P == '=')
		{
			_inf->env_changed = delete_node_at_index(&(_inf->env), j);
			j = 0;
			N = _inf->env;
			continue;
		}
		N = N->next;
		j++;
	}
	return (_inf->env_changed);
}
