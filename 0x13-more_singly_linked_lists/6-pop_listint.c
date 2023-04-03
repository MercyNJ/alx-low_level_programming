#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t list.
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 *
 * Return: If the linked list is empty - 0.
 *         The head node's data (n) if not empty
 *
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;

	int temp2;

	if (*head == NULL)
		return (0);

	temp = *head;
	temp2 = (*head)->n;
	*head = (*head)->next;

	free(temp);

	return (temp2);
}
