#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * list_len - Returns the number of elements in a single linked list
 * @h: A pointer to the list_t list
 *
 * Return: The number of elements in the list
 */

size_t list_len(const list_t *h)
{
	size_t count;

	count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}
