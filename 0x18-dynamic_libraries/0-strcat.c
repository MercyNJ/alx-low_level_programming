#include "main.h"
#include <stdio.h>

/**
 * _strcat - Concatenates two strings and
 * overwites the terminating null byte at end of dest and
 * adds a terminating null byte
 *
 * @dest: The destination value
 * @src: The source value
 * Return: A pointer to the resulting string dest
 */

/* The concatenation function */

char *_strcat(char *dest, char *src)

{
	int i;

	int j;

	i = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	j = 0;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
