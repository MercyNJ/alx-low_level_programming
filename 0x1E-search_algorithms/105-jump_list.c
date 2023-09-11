#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list
 *             using Jump search algorithm.
 *
 *  @list: Pointer to the head of the list to search in.
 *  @size: Number of nodes in list
 *  @value: Value to search for.
 *
 *  Return: Pointer to the first node where value is located,
 *          or NULL if not found.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, jump_dist;
	listint_t *current_node, *jump;

	if (list == NULL || size == 0)
		return (NULL);

	step = 0;
	jump_dist = sqrt(size);
	for (current_node = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		current_node = jump;
		for (step += jump_dist; jump->index < step; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			current_node->index, jump->index);

	for (; current_node->index < jump->index && current_node->n < value;
			current_node = current_node->next)
		printf("Value checked at index [%ld] = [%d]\n",
				current_node->index, current_node->n);
	printf("Value checked at index [%ld] = [%d]\n",
			current_node->index, current_node->n);

	return (current_node->n == value ? current_node : NULL);
}
