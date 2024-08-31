#include "main.h"

/**
 * _EXITS - exits the shell with or without a return of status n
 * @arv: array of words of the entered line
 */
void _EXITS(char **arv)
{
	int i, N;

	if (arv[1])
	{
		N = STRTOI(arv[1]);
		if (N <= -1)
			N = 2;
		_farv(arv);
		exit(N);
	}
	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
	exit(0);
}

/**
 * STRTOI - converts a string into an integer
 *@st: pointer to a string
 *Return: the integer
 */
int STRTOI(char *st)
{
	int i, _int, sign = 1;

	i = 0;
	_int = 0;
	while (!((st[i] >= '0') && (st[i] <= '9')) && (st[i] != '\0'))
	{
		if (st[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((st[i] >= '0') && (st[i] <= '9'))
	{
		_int = (_int * 10) + (sign * (st[i] - '0'));
		i++;
	}
	return (_int);
}

/**
 * env - prints the current environment
 * @arv: array of arguments
 */
void env(char **arv __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}

}

/**
 * settenv - Initialize a new environment variable, or modify an existing one
 * @arv: array of entered words
 */
void settenv(char **arv)
{
	int i, j, k;

	if (!arv[1] || !arv[2])
	{
		perror(_getenv("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				k = 0;
				while (arv[2][k])
				{
					environ[i][j + 1 + k] = arv[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = _conc(arv[1], "=", arv[2]);
		environ[i + 1] = '\0';

	}
}

/**
 * unsettenv - Remove an environment variable
 * @arv: array of entered words
 */
void unsettenv(char **arv)
{
	int i, j;

	if (!arv[1])
	{
		perror(_getenv("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
