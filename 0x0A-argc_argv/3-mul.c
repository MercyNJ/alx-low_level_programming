#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Prints multiplication of 2 numbers
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 if true, 1 if false
 */

int main(int argc, char *argv[])
{
	int x;
	int y;

	if (argc == 3)
	{
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		printf("%d\n", x * y);
		return (0);
	}
	printf("Error\n");
	return (1);
}
