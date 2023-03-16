#include <stdlib.h>
#include "main.h"

/**
 * _calloc - Allocates memory for nmemb elements
 * of size bytes each
 *
 * @nmemb: The number of elements in the array
 * @size: Bytes for each element
 *
 * Return: a void pointer to allocated memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		ptr[i] = 0;

	return (ptr);

}
