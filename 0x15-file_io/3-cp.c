#include "main.h"
#include <stdio.h>

/**
 * error_check - Checks if a file can be opened.
 * @srcFile: The source file.
 * @destFile: The destination file.
 *
 * @argv: Arguments vector.
 *
 * Return: Nothing.
 */

void error_check(int srcFile, int destFile, char *argv[])
{
	if (srcFile == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (destFile == -1)
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
	int srcFile, destFile, close_result;
	ssize_t read_count, write_count;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp srcFile destFile");
		exit(97);
	}

	srcFile = open(argv[1], O_RDONLY);
	destFile = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_check(srcFile, destFile, argv);

	read_count = 1024;
	while (read_count == 1024)
	{
		read_count = read(srcFile, buff, 1024);
		if (read_count == -1)
			error_check(-1, 0, argv);
		write_count = write(destFile, buff, read_count);
		if (write_count == -1)
			error_check(0, -1, argv);
	}

	close_result = close(srcFile);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", srcFile);
		exit(100);
	}

	close_result = close(destFile);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", destFile);
		exit(100);
	}
	return (0);
}
