#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd, bytes_r, bytes_w;
	char *buff;

	if (filename == NULL)
		return (0);

	buff = malloc(sizeof(char) * letters);

	if (buff == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	bytes_r = read(fd, buff, letters);
	bytes_w = write(STDOUT_FILENO, buff, bytes_r);

	if (fd == -1 || bytes_r == -1 || bytes_w == -1 || bytes_w != bytes_r)
	{
		free(buff);
		return (0);
	}

	free(buff);
	close(fd);

	return (bytes_w);
}
