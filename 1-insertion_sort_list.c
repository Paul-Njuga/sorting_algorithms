#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swap_node, *next_swap;

	if (list == NULL || *list == NULL)
		return;
	swap_node = (*list)->next;
	while (swap_node != NULL)
	{
		/* Store pointer to next for iteration */
		next_swap = swap_node->next;
		while (swap_node->prev != NULL && swap_node->prev->n > swap_node->n)
		{
			/* Assignments for node(nxt) bfr swap_node */
			swap_node->prev->next = swap_node->next;
			/* Assignments for node(prev) aftr swap_node */
			if (swap_node->next != NULL)
				swap_node->next->prev = swap_node->prev;

			/* Assignments for swap_node */
			swap_node->next = swap_node->prev;
			swap_node->prev = swap_node->next->prev;

			/* Assignments for node(prev) bfr swap_node */
			swap_node->next->prev = swap_node;

			if (swap_node->prev == NULL)
				/* Set head to swap_node */
				*list = swap_node;
			else
				/* Make appropriate assignment */
				swap_node->prev->next = swap_node;
			print_list(*list);
		}
		/* Update swap_node */
		swap_node = next_swap;
	}
}
