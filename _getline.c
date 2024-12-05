#include "main.h"

/**
 * _getline - gets all of the input line from stdin
 * @line_ptr: saves the input from stdin
 * @n: the number of characters read form the stdin
 * @fd: filedescriptor to getline from
 * Return: the number of the characters read
 */
ssize_t _getline(char **line_ptr, size_t *n, int fd)
{
	static ssize_t idx;
	char *buffer, ch;
	int bytes_read;
	size_t old_size = 120, new_size;

	buffer = malloc(sizeof(char) * 120);
	if (buffer == NULL)
		return (-1);
	idx = 0;
	do {
		if ((size_t)idx == old_size)
		{
			new_size = old_size + 120;
			buffer = _realloc(buffer, old_size, new_size);
			old_size = new_size;
		}
		bytes_read = read(fd, &ch, 1);
		if (bytes_read == -1 || (bytes_read == 0 && idx == 0))
		{
			free(buffer);
			return (-1);
		}
		if (bytes_read == 0 && idx != 0)
		{
			idx++;
			break;
		}
		buffer[idx] = ch;
		idx++;
	} while (ch != '\n' && ch != ';');
	buffer[idx] = '\0';
	*line_ptr = buffer;
	if (idx < 120)
		*n = 120;
	else
		*n = new_size;
	return (idx);
}
