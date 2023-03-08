#include "main.h"

int find_sqrt(int num, int root);

int _sqrt_recursion(int n);

/**
 * find_sqrt - Finds the natural square root of a number
 * @num: The number to find the square root of
 * @root: The test root
 *
 * Return: The square root - if number has a natural one
 *        -1 if number has no natural square root
 */

int find_sqrt(int num, int root)
{
	if ((root * root) == num)
		return (root);

	if (root == num / 2)
		return (-1);

	return (find_sqrt(num, root + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to return square root of
 *
 * Return: The square root of n - if its a natural one
 *         -1 if not a natural one
 */

int _sqrt_recursion(int n)
{
	int root = 0;

	if (n < 0)
		return (-1);

	if (n == 1)
		return (1);

	return (find_sqrt(n, root));
}
