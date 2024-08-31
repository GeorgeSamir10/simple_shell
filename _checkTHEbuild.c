#include "main.h"

/**
* _checkTHEbuild - checks if the command is a buildin
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*_checkTHEbuild(char **arv))(char **arv)
{
	int x, y;
	mybuild T[] = {
		{"exit", _EXITS},
		{"env", env},
		{"setenv", settenv},
		{"unsetenv", unsettenv},
		{NULL, NULL}
	};

	for (x = 0; T[x].name; x++)
	{
		y = 0;
		if (T[x].name[y] == arv[0][y])
		{
			for (y = 0; arv[0][y]; y++)
			{
				if (T[x].name[y] != arv[0][y])
					break;
			}
			if (!arv[0][y])
				return (T[x].func);
		}
	}
	return (0);
}
