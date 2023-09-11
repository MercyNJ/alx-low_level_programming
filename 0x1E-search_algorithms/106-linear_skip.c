#include "search_algos.h"

/**
 * linear_skip - Search for a value in a sorted skip list of ints
 *
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where the value is located,
 *         or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current_node, *search_node;

	if (list == NULL)
		return (NULL);

	for (current_node = search_node = list;
			search_node->next != NULL && search_node->n < value;)
	{
		current_node = search_node;
		if (search_node->express != NULL)
		{
			search_node = search_node->express;
			printf("Value checked at index [%ld] = [%d]\n",
					search_node->index, search_node->n);
		}
		else
		{
			while (search_node->next != NULL)
				search_node = search_node->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			current_node->index, search_node->index);

	for (; current_node->index < search_node->index &&
			current_node->n < value; current_node = current_node->next)
		printf("Value checked at index [%ld] = [%d]\n",
				current_node->index, current_node->n);
	printf("Value checked at index [%ld] = [%d]\n",
			current_node->index, current_node->n);

	return (current_node->n == value ? current_node : NULL);
}
