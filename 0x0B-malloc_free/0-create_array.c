#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates array of size size & assigns
 * char c.
 *
 * @size: The array size
 * @c: The character to assign
 *
 * Description: Creating an array
 * Return: pointer to array (Success)
 *         NULL (fail)
 */

char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	str = malloc(sizeof(char) * size);

	if (size == 0 || str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		str[i] = c;
	return (str);
}
