#include "main.h"
#include <stdio.h>

/**
 * error_check - Checks if a file can be opened.
 * @file_from: The source file.
 * @file_to: The destination file.
 *
 * @argv: Arguments vector.
 *
 * Return: Nothing.
 */

void error_check(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - The entry point
 * @argc: Arguments count.
 * @argv: Arguments vector.
 *
 * Return: Always 0(Success)
 */

int main(int argc, char *argv[])
{
	int file_from, file_to, close_result;
	ssize_t read_count, write_count;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_check(file_from, file_to, argv);

	read_count = 1024;
	while (read_count == 1024)
	{
		read_count = read(file_from, buff, 1024);
		if (read_count == -1)
			error_check(-1, 0, argv);
		write_count = write(file_to, buff, read_count);
		if (write_count == -1)
			error_check(0, -1, argv);
	}

	close_result = close(file_from);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	close_result = close(file_to);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
	return (0);
}
