#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: head of a list
 *
 * Description: Sets the head to NULL
 * Return: Nothing
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		(*head) = temp;
	}

	head = NULL;
}
