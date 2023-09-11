#include "search_algos.h"

/**
 * advanced_binary_recursive - Recursive func for advanced binary search.
 *
 * @array: A pointer to the first element of the array.
 * @left: The left index of the current subarray.
 * @right: The right index of the current subarray.
 * @value: The value to search for.
 *
 * Return: The index where the value is located or -1 if not found.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t midpoint;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (midpoint = left; midpoint < right; midpoint++)
		printf("%d, ", array[midpoint]);
	printf("%d\n", array[midpoint]);

	midpoint = left + (right - left) / 2;
	if (array[midpoint] == value && (
				midpoint == left || array[midpoint - 1] != value))
		return (midpoint);
	if (array[midpoint] >= value)
		return (advanced_binary_recursive(array, left, midpoint, value));
	return (advanced_binary_recursive(array, midpoint + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
