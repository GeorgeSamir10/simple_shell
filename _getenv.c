#include "main.h"
/**
* _getenv - Get the path of the environment variable
* @name: string to get the name of the variable
* Return: address of the variable if (success), NULL if (failed)
*/


char *_getenv(const char *name)
{
	char **envp = environ;

	while (*envp != NULL)
	{
		int i = 0;

		while (name[i] != '\0' && (*envp)[i] == name[i])
		{
			i++;
		}
		if (name[i] == '\0' && (*envp)[i] == '=')
		{
			return ((*envp) + i + 1);
		}
		envp++;
	}

	return (NULL);
}
