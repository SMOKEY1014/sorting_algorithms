#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion Sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *upnext;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	upnext = (*list)->next;

	while (upnext != NULL)
	{
		listint_t *current = upnext->prev;

		while (current != NULL && current->n > upnext->n)
		{
			/* Swap the nodes */
			if (current->prev != NULL)
				current->prev->next = upnext;
			if (upnext->next != NULL)
				upnext->next->prev = current;

			current->next = upnext->next;
			upnext->prev = current->prev;
			upnext->next = current;
			current->prev = upnext;

			/* Update the head of the list if needed */
			if (upnext->prev == NULL)
				*list = upnext;

			/* Move to the previous node */
			current = upnext->prev;
		}
		upnext = upnext->next;
		print_list(*list);
	}
}
