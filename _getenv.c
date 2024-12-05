#include "main.h"

/**
 * _getenv - gets an environment variable.
 * @name: name of the var inside the environ list.
 *
 * Return: pointer to the value string of the var defined
 * by name.
 */
char *_getenv(char *name)
{
	int i, k, count = 0, _comp;
	char **env = environ;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (k = 0, _comp = 0; env[i][k] != '='; k++)
			_comp++;
		if (_strlen(name) == _comp)
		{
			if (_strncmp(name, env[i], _comp) == 0)
				count = 1;
		}
		if (count == 1)
		{
			return (&env[i][_comp + 1]);
		}
	}
	return (NULL);
}
