#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to an
 * unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int res, pow;
	int length;

	if (b == NULL)
		return (0);

	for (length = 0; b[length]; length++)
	{
		if (b[length] != '0' && b[length] != '1')
			return (0);
	}

	for (pow = 1, res = 0, length--; length >= 0; length--, pow *= 2)
	{
		if (b[length] == '1')
			res += pow;
	}
	return (res);
}
