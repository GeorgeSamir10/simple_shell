#include "main.h"

/**
  * isaty - verif if terminal
  */

void isaty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("\nSHELL_PROMPT$ ");
}


/**
* ENDF - handles the End of File
* @length: return value of getline function
* @buf: buffer
 */
void ENDF(int length, char *buf)
{
	(void)buf;
	if (length == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buf);
		}
		exit(0);
	}
}

/**
 * handler - checks if Ctrl C is pressed
 * @number: int
 */
void handler(int number)
{
	if (number == SIGINT)
	{
		_puts("\nMyPrompt$ ");
	}
}


/**
 * main - Shell
 * Return: 0 on success
 */

int main(void)
{
	ssize_t length = 0;
	char *buf = NULL, *_val, *PNAME, **arv;
	size_t SIZE = 0;
	list_path *HD = '\0';
	void (*f)(char **);

	signal(SIGINT, handler);
	while (length != EOF)
	{
		isaty();
		length = getline(&buf, &SIZE, stdin);
		ENDF(length, buf);
		arv = _splitstr(buf, " \n");
		if (!arv || !arv[0])
			exec(arv);
		else
		{
			_val = _getenv("PATH");
			HD = _linkP(_val);
			PNAME = _FPATH(arv[0], HD);
			f = _checkTHEbuild(arv);
			if (f)
			{
				free(buf);
				f(arv);
			}
			else if (!PNAME)
				exec(arv);
			else if (PNAME)
			{
				free(arv[0]);
				arv[0] = PNAME;
				exec(arv);
			}
		}
	}
	_FLST(HD);
	_farv(arv);
	free(buf);
	return (0);
}
