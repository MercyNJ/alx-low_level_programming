#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to find the bit in
 * @index: given index at which we check the bit
 * Return: the value of a bit at the given index
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int value;

	if (index > 64)
		return (-1);

	value = n >> index;

	return (value & 1);
}
