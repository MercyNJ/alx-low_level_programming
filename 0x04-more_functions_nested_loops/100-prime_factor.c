#include <stdio.h>
#include <math.h>

/**
 * main - Prints the largest prime factor of number 612852475143
 * Return: Always 0 (Success)
 */

int main(void)
{
	long num = 612852475143;
	long divider = 2;
	long large_prime = 0;

	while (num != 1)
	{
		if (num % divider == 0)
		{
			num = num / divider;
			large_prime = divider;
		}
		divider += 1;
	}
	printf("%ld\n", large_prime);
	return (0);
}
