#include <stdio.h>

/**
 * swap_int - Swaps the values of 2 integers
 *
 * @a: The 1st integer to be swapped
 * @b: The 2nd integer to be swapped
 *
 * Return: Nothing
 */

void swap_int(int *a, int *b)
/* the function that swaps the values of 2 integers */
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
