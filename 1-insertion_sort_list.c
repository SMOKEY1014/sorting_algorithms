#include "sort.h"

/**
 * swap - swaps 2 nodes in a doubly-linked list
 * @a: address of first node
 * @b: address of second node
 *
 * Return: void
 */
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion Sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *upnext, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	upnext = (*list)->next;
	while (upnext)
	{
		current = upnext;
		upnext = upnext->next;
		while (current && current->prev)
		{
			if (current->prev->n > current->n)
			{
				swap(current->prev, current);
				if (!current->prev)
					*list = current;
				print_list((const listint_t *)*list);
			}
			else
				current = current->prev;
		}

	}
}
