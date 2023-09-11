#include "search_algos.h"

/**
 * interpolation_search - Search value in a sorted arry using interpolation.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 *  Return: Index value is located, or -1 if not found/array is NULL.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t pos, pos1, pos2;

	if (array == NULL || size == 0)
		return (-1);
	while (low <= high && value >= array[low] && value <= array[high])
	{
		pos1 = (high - low) / (array[high] - array[low]);
		pos2 = (value - array[low]);
		pos = low + (pos1 * pos2);

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}
	printf("Value checked array[%lu] is out of range\n", high);
	return (-1);
}

