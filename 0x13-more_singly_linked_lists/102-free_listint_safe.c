#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely (ie.
 *                     can free lists containing loops)
 * @h: A pointer to the address of
 *     the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 *
 * Description: The function sets the head to NULL.
 */

size_t free_listint_safe(listint_t **h)
{
	int variation;
	size_t count = 0;
	listint_t *temp;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		variation = *h - (*h)->next;
		if (variation > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
	}

	*h = NULL;

	return (count);
}
