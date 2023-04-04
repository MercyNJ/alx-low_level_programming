#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *temp1 = NULL;
	const listint_t *temp2 = NULL;
	size_t count = 0;
	size_t new;

	temp1 = head;
	while (temp1 != NULL)
	{
		printf("[%p] %d\n", (void *)temp1, temp1->n);
		count++;
		temp1 = temp1->next;
		temp2 = head;
		new = 0;

		while (new < count)
		{
			if (temp1 == temp2)
			{
				printf("-> [%p] %d\n", (void *)temp1, temp2->n);
				return (count);
			}
			temp2 = temp2->next;
			new++;
		}
		if (head == NULL)
			exit(98);
	}
	return (count);
}
