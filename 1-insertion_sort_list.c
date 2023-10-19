#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = current;
			if (current->next != NULL)
				current->next->prev = prev;
			
			prev->next = current->next;
			current->prev = prev->prev;
			
			current->next = prev;
			prev->prev = current;
			
			if (prev == *list)
				*list = current;
			
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
