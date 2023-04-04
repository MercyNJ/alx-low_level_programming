#include "lists.h"

/**
 * sum_listint - Calculates sum of all the
 *               data(n) of a listint_t list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: If the list is empty - 0.
 *         Otherwise - the sum of all the data.
 */

int sum_listint(listint_t *head)
{
	listint_t *temp;

	int sum = 0;

	if (head == NULL)
		return (0);

	temp = NULL;
	temp = head;

	while (temp != NULL)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
