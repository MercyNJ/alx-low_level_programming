#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1
 *         1 On Success
 */

int create_file(const char *filename, char *text_content)
{
	int fd, contentLen = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (contentLen = 0; text_content[contentLen];)
			contentLen++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (write(fd, text_content, contentLen) == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}


