#include "main.h"

/**
 * flip_bits - returns the number of bits you would
 * need to flip to get from one number to another
 * @n: number one.
 * @m: number two.
 *
 * Return: number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int variation;
	int count;

	variation = n ^ m;
	count = 0;

	while (variation)
	{
		count++;
		variation &= (variation - 1);
	}

	return (count);
}
