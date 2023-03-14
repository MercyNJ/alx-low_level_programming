#include "main.h"
#include <stdlib.h>

/**
 * _strlen - Count an array
 * @s: An array of elements
 *
 * Return: 1
 */

int _strlen(char *s)
{
	unsigned int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strcpy - Copies an array
 * @src: An array of elements
 * @dest: The destination array
 *
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - Printing a duplicate array
 * @str: An array of elements
 *
 * Return: A pointer to the duplicated string
 */

char *_strdup(char *str)
{
	char *dstr;
	unsigned int size;

	if (str == 0)
	{
		return (NULL);
	}

	size = _strlen(str) + 1;

	dstr = (char *) malloc(size * sizeof(char));

	if (dstr == 0)
	{
		return (NULL);
	}
	_strcpy(dstr, str);
	return (dstr);
}
