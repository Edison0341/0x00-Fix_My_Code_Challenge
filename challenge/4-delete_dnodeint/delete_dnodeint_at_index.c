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

	if (*head == NULL) /* Check if the list is empty */
		return (-1);

	current = *head;							   /* Start from the head node */
	for (p = 0; p < index && current != NULL; p++) /* Traverse to the target node */
	{
		current = current->next;
	}

	if (current == NULL) /* If the index is out of bounds */
		return (-1);

	/* Deleting the first node (head node) */
	if (current == *head)
	{
		*head = current->next; /* Update head pointer */
		if (*head != NULL)
			(*head)->prev = NULL; /* Update the prev pointer of the new head */
	}
	else
	{
		/* Update the prev pointer of the next node */
		if (current->next)
			current->next->prev = current->prev;
		/* Update the next pointer of the prev node */
		if (current->prev)
			current->prev->next = current->next;
	}

	free(current); /* Free the memory of the deleted node */
	return (1);
}
