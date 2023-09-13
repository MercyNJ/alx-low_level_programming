#include "search_algos.h"

/**
 * binary_search - Searches for given value using binary search.
 *
 * @array: Pointer to 1st element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index where the value is located, or -1 if not found.
 */

int binary_search(int *array, size_t size, int value)
{
	size_t i, mid;
	size_t start = 0, end = size - 1;

	if (array == NULL)
		return (-1);

	while (start <= end)
	{
		mid = start + (end - start) / 2;
		printf("Searching in array: ");
		for (i = start; i <= end; i++)
		{
			printf("%d", array[i]);
			if (i < end)
				printf(", ");
			else
				printf("\n");
		}
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (-1);
}
