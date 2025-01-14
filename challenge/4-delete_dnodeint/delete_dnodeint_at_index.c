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
	dlistint_t *saved_head, *tmp;
	unsigned int p;

	if (*head == NULL) /* Check if the list is empty */
		return (-1);

	saved_head = *head;
	p = 0;

	/* Traverse the list to find the node at the given index */
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}

	if (p != index || *head == NULL) /* Index out of range */
	{
		*head = saved_head; /* Restore head */
		return (-1);
	}

	if (index == 0) /* Deleting the first node */
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
			tmp->prev = NULL;
	}
	else /* Deleting a node other than the first */
	{
		(*head)->prev->next = (*head)->next; /* Update the prev node's next pointer */
		if ((*head)->next)
			(*head)->next->prev = (*head)->prev; /* Update the next node's prev pointer */
		free(*head);
		*head = saved_head; /* Restore head */
	}

	return (1);
}
