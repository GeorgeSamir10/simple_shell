#include "main.h"

/**
* _gethistoryfile - gets history file
* @_inf: struct of arguments
* Return: allocated string file history
*/

char _gethistoryfile(info_t *_inf)
{
	char *buff, *d;

	d = _getenv(_inf, "HOME=");
	if (!d)
		return (NULL);
	buff = malloc(sizeof(char) * _strlen(d) + _strlen(HIST_FILE + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, d);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
* _writehistory - create file or exits file
* @_inf: struct of arguments
* Return: 1 (success), -1 (failure)
*/

int _writehistory(info_t *_inf)
{
	ssize_t filed;
	char *Fname = _gethistoryfile(_inf);
	list_t *N = NULL;

	if (!Fname)
		return (-1);
	filed = open(Fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(FNAME);
	if (filed == -1)
		return (-1);
	for (N = _inf->history; N; N = N->next)
	{
		_putsfd(N->str, filed);
		_putsfd('\n', filed);
	}
	_putsfd(BUF_FLUSH, filed);
	close(filed);
	return (1);
}

/**
* _readhistory - reads history from file
* @_inf: struct contains arguments
* Return: hystcount on success
*/

int _readhistory(info_t *_inf)
{
	int j, final = 0, Lcount = 0;
	ssize_t filed, Readlen, Fsize = 0;
	struct stat st;
	char *buff = NULL, *Fname = _gethistoryfile(_inf);

	if (!Fname)
		return (0);
	filed = open(Fname, O_RDONLY);
	free(Fname);
	if (filed == -1)
		return (0);
	if (!fstat(filed, &st))
		Fsize = st.st_size;
	if (Fsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (Fsize + 1));
	if (!buff)
		return (0);
	Readlen = read(filed, buff, Fsize);
	buff[Fsize] = 0;
	if (Readlen <= 0)
		return (free(buff), 0);
	close(filed);
	for (j = 0; j < fsize; j++)
		if (buff[j] == '\n')
		{
			buff[j] = 0;
			_buildhistorylist(_inf, buff + final, Lcount++);
			final = j + 1;
		}
	if (final != j)
		_buildhistorylist(_inf, buff + final, Lcount++);
	free(buff);
	_inf->histcount = Lcount;
	while (_inf->histcount-- >= HIST_MAX)
		delete_node_at_index(&(_inf->history), 0);
	_renumberhistory(_inf);
	return (_inf->histcount);
}


/**
* _buildhistorylist - add entry to a history list
* @_inf: struct contains arguments
* @buff: buffer
* @Lcount: line count
* Return: 0 (Success)
*/

int _buildhistorylist(info_t *_inf, char *buff, int Lcount)
{
	list_t *N = NULL;

	if (_inf->history)
		N = _inf->history;
	add_node_end(&N, buff, Lcount);
	if (!_inf->history)
		_inf->history = N;
	return (0);
}

/**
* _renumberhistory - history linkedlist renumbered
* @_inf: struct contain arguments
* Return: new histcount
*/

int _renumberhistory(info *_inf)
{
	list_t *N = _inf->history;
	int j = 0;

	while (N)
	{
		N->num = j++;
		N = N->next;
	}
	return (_inf->histcount = j);
}
