#include "main.h"

/**
* _checkTHEbuild - checks if the command is a buildin
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*_checkTHEbuild(char **arv))(char **arv)
{
	int x, l;
	mybuild T[] = {
		{"exit", _EXITS},
		{"env", env},
		{"setenv", settenv},
		{"unsetenv", unsettenv},
		{NULL, NULL}
	};

	for (x = 0; T[x].name; x++)
	{
		l = 0;
		if (T[x].name[l] == arv[0][l])
		{
			for (l = 0; arv[0][l]; y++)
			{
				if (T[x].name[l] != arv[0][l])
					break;
			}
			if (!arv[0][l])
				return (T[x].func);
		}
	}
	return (0);
}
