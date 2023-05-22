#include "main.h"

/**
 * _memcpy - The entry point
 * @dest: destination memory area
 * @src: source memory area
 * @n: input
 * Return: Always 0 (Success)
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
