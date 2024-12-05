#include "main.h"
/* for: cd*/
/**
 * switch_current_dir - switched between oldpwd and pwd
 * when using 'cd -'
*/
void switch_current_dir(void)
{
	int _stat;
	char *_tmp;

	if (_getenv("OLDPWD") != NULL)
	{
		change_dir(_getenv("OLDPWD"));
		_tmp = _strdup(_getenv("OLDPWD"));
		print_path(_tmp);

		_stat = _setenv("OLDPWD", _getenv("PWD"), 1);

		if (_stat != 0)
			perror("setenv:");
		_stat = _setenv("PWD", _tmp, 1);

		if (_stat != 0)
			perror("setenv:");
		free(_tmp);
	}
	else
	{
		change_dir(_getenv("PWD"));
		_tmp = _strdup(_getenv("PWD"));
		print_path(_tmp);
		_stat = _setenv("OLDPWD", _getenv("PWD"), 0);
		if (_stat != 0)
			perror("setenv:");
		free(_tmp);
	}
}

/**
 * go_to_home - goes to path in the $HOME env var
*/
void go_to_home(void)
{
	int _stat;

	if (_getenv("HOME") == NULL)
		return;

	change_dir(_getenv("HOME"));

	_stat = _setenv("PWD", _getenv("HOME"), 1);
	if (_stat != 0)
		perror("setenv:");
}
/**
 * change_to_new_dir - goed to dir specified after cd
 * @exitstatus: the exit status to exit with throughg out the program
 * @dir_name: current dir name
 * @linenum: number of line of commmand
 * @prog: name of the shell
 * @args: the argumnets of the command
*/
void change_to_new_dir(int *exitstatus, char *dir_name,
int linenum, char *prog, char **args)
{
	int _stat;

	if (access(args[1], F_OK) == 0)
	{
		if (is_directory(args[1]) == 0)
		{
			not_dir(args[1], linenum, prog);
			*exitstatus = 1;
		}
		else
		{
			if (access(args[1], X_OK) == 0)
			{
				_stat = chdir(args[1]);
				if (_stat != 0)
					perror("cd");
			else
			{
				if (_getenv("OLDPWD") == NULL)
					_setenv("OLDPWD", dir_name, 0);
				else
					_setenv("OLDPWD", dir_name, 1);
				if (getcwd(dir_name, 1024) == NULL)
					perror("getcwd:");
				_setenv("PWD", dir_name, 1);
			}
			}
			else
			{
				permissiondenied(args[1], linenum, prog);
				*exitstatus = 1;
			}
		}
	}
	else
	{
		not_dir(args[1], linenum, prog);
		*exitstatus = 1;
	}
}
