#include <stdio.h>
#include "main.h"

/**
 * main - Printing all arguments passed to program
 * @argc: Arguments count
 * @argv: An array of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
