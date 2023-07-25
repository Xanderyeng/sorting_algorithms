#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked
 * list of integers in ascending order
 * @list: list of elements linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (list != NULL && *list != NULL)
	{
		current = *list;
		while (current->next != NULL)
		{
			current = current->next;
			if (current->prev->n > current->n)
			{
				if (current->next == NULL)
				{
					current->next = current->prev;
					current->prev->next = NULL;
				}
				else
				{
					current->prev->next = current->next;
					current->next->prev = current->prev;
					current->next = current->prev;
				}
				if (current->prev != *list)
				{
					current->prev = current->prev->prev;
					current->prev->next = current;
					if (current->next != NULL)
						current->next->prev = current;
					current = current->prev;
				}
				else
				{
					current->prev = NULL;
					if (current->next != NULL)
						current->next->prev = current;
					*list = current;
				}
				print_list(*list);
			}
		}
	}
}
