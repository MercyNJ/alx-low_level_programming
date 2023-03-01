#include "main.h"

/**
 * _strtcat - Concatenates two strings and
 * overwites the terminating null byte at end of dest and
 * adds a terminating null byte
 *
 * @dest: The destination value
 * @src: The source value
 * Return: void
 */

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
