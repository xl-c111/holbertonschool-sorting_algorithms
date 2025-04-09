#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: a pointer points to the head pointer of a doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next != NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			current->prev = prev->prev;

			prev->prev = current;
			prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = prev;

			current->next = prev;
			print_list(*list);
		}
		 current = next;
	}
}
