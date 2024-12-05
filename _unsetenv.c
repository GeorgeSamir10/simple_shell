#include "main.h"

/**
 * unset_env - deletes a variable from the environ list.
 * @args: array of arguments in program.
 * @_exitstatus: pointer to _exitstatus of program.
 * @linenum: the number of the line of the command
 * @prog: the name of the shell
 * Return: void.
 */
void unset_env(char **args, int *_exitstatus, int linenum, char *prog)
{
	int i = 0, ret;
	char *var;

	(void) linenum;
	(void)_exitstatus;
	(void)prog;
	if (args[1] == NULL)
	{
		perror("unsetenv: ");
		return;
	}
	var = args[1];
	while (args[1][i] != '\0')
	{
		if (args[1][i] == '=')
			return;
		i++;
	}
	ret = _unsetenv(var);
	if (ret != 0)
	{
		perror("unsetenv: ");
		return;
	}
}

/**
 * shrinkenv - shrinks the env list by 1 and deletes the
 * variable at delete_loc.
 * @size: new size of the env list.
 * @delete_loc: the location of the var to be deleted.
 *
 * Return: array of string to the env list.
 */
char **shrinkenv(int size, int delete_loc)
{
	char **_newenv, **env = environ;
	int i, j, k;

	_newenv = malloc(sizeof(char *) * size);
	if (_newenv == NULL)
		return (NULL);
	for (i = 0, j = 0; env[i] != NULL; i++, j++)
	{
		if (i == delete_loc)
		{
			i++;
		}
		if (env[i] == NULL)
			break;
		_newenv[j] = malloc(strlen(env[i]) + 1);
		if (_newenv[j] == NULL)
		{
			for (k = j - 1; k >= 0; k--)
				free(_newenv[k]);
			free(_newenv);
			return (NULL);
		}
		strcpy(_newenv[j], env[i]);
	}
	_newenv[j] = NULL;
	return (_newenv);
}

/**
 * _unsetenv - deletes the variable name from the environment
 * @name: name string of the variable to be unset.
 * Return: 0 on success and -1 on failure.
 */
int _unsetenv(char *name)
{
	char **env = environ, **_newenv;
	int i, j, delete_loc, del_flag = 0, varlen, size;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0, varlen = 0; env[i][j] != '='; j++)
			varlen++;
		if (_strlen(name) == varlen)
		{
			if (_strncmp(name, env[i], varlen) == 0)
			{
				del_flag = 1;
				delete_loc = i;
			}
		}
	}
	if (del_flag == 0)
		return (-1);
	size = i;
	_newenv = shrinkenv(size, delete_loc);
	if (_newenv == NULL)
		return (-1);
	_freedouble(environ);
	environ = _newenv;
	return (0);
}
