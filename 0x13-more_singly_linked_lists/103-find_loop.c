#include "lists.h"

/**
 * find_listint_loop - Finds the loop contained in
 *                     a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: If there is no loop - NULL.
 *         If available - the address of the node where the loop starts.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *temp;
	listint_t *prev;

	temp = head;
	prev = head;

	while (head && temp && temp->next)
	{
		head = head->next;
		temp = temp->next->next;

		if (head == temp)
		{
			head = prev;
			prev = temp;
			while (1)
			{
				temp = prev;
				while (temp->next != head && temp->next != prev)
				{
					temp = temp->next;
				}
				if (temp->next == head)
					break;

				head = head->next;
			}
			return (temp->next);
		}
	}
	return (NULL);
}
