#include "main.h"

/**
* main - entry point
* @ac: argument count
* @av: argument vector
* Return: 0 (Success), 1 (Failure)
*/

int main(int ac, char **av)
{
	info_t _inf[] = {INFO_INIT};
	int filed = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		 : "=r" (filed)
		 : "r" (filed));

	if (ac == 2)
	{
		filed = open(av[1], O_RDONLY);
		if (filed == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Couldn't Open");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		_inf->readfd = filed;
	}
	_pop_env_list(_inf);
	_readhistory(_inf);
	hsh(_inf, av);
	return (EXIT_SUCCESS);
}
