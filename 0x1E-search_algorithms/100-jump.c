#include "search_algos.h"

/**
 * jump_search - Search a value in a sorted array using Jump search.
 *
 * @array: Pointer to 1st elem of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, current_index, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	for (i = current_index = 0;
			current_index < size && array[current_index] < value;)
	{
		printf("Value checked array[%ld] =", current_index);
		printf(" [%d]\n", array[current_index]);
		i = current_index;
		current_index += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, current_index);
	if (current_index < size - 1)
	{
		current_index = current_index;
	}
	else
	{
		current_index = size - 1;
	}

	for (; i < current_index && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
