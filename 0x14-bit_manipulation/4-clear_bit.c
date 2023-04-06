#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0.
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 if successful, -1 if not
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int count;
	unsigned int value;

	if (index > 64)
		return (-1);

	value = index;

	for (count = 1; value > 0; count *= 2, value--)
		;

	if ((*n >> index) & 1)
		*n -= count;

	return (1);
}
