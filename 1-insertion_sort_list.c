#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: a pointer points to the head pointer of a doubly linked list
 * Description: - start from the second element, compare the current element with elements in the sorted part,
 *                if the current element is smaller, move the larger element one position back
 *              - swap current with prev by re-linking their prev and next pointers:
 *                1, prev->prev->next → current
 *                2, current->prev → prev->pre
 *                3, prev->prev → current
 *                4, prev->next → current->next
 *                5, current->next → prev
 *                6, current->next->prev → prev
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next; 
	
        /* if the list is empty or there is only one node in the list, no sorting needed */
	if (list == NULL || *list == NULL || (*list)->next == NULL) 
		return;

	current = (*list)->next;      /* initialize current to point to the second node (since the first node is trivially sorted)*/
	while (current != NULL)
	{
		next = current->next;           /* save the next node before modifying pointer*/
                /* if current has a previous node and its value is smaller than previous node, swap them */
		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;          /* save the previous node before modifying pointer */

			if (prev->prev != NULL)        /* if prev is not head node, update prev->prev->next to point to current */
				prev->prev->next = current;
			else
				*list = current;       /* otherwise current becomes head node, update *list */
			
                        /* update current->prev to point to the node before prev, relinking current to the front of the list */
			current->prev = prev->prev;  
			
			prev->prev = current;          /* prev->prev now points current, because current has moved before it */
			prev->next = current->next;    /* prev->next now points to the node after current */

			if (current->next != NULL)
				current->next->prev = prev;  /* if current originally has a next node, update next's prev ptr to point to prev */

			current->next = prev;          /* set current->next to prev*/
			print_list(*list);
		}
		 current = next;
	}
}
