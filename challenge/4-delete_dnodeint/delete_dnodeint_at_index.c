#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int p;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;			/* Start from the head */
	for (p = 0; p < index; p++) /* Traverse to the target node */
	{
		if (current == NULL)
			return (-1);
		current = current->next;
	}

	if (current == NULL) /* If the index is out of bounds */
		return (-1);

	if (current->prev) /* Update the previous node's next pointer */
		current->prev->next = current->next;
	else /* If deleting the head node */
		*head = current->next;

	if (current->next) /* Update the next node's prev pointer */
		current->next->prev = current->prev;

	free(current); /* Free the node */
	return (1);
}
