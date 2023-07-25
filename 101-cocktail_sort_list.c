#include "sort.h"
/**
 * swap - change node linked list
 * @nodo: xxx
 * @nodo_1: yyyy
 * @list: linked list
 * Return: Nothing
 */

void swap(listint_t *nodo, listint_t *nodo_1, listint_t **list)
{
	if (nodo_1->next != NULL)
		nodo_1->next->prev = nodo;

	if (nodo->prev != NULL)
	{
		nodo_1->prev = nodo->prev;
		nodo_1->prev->next = nodo_1;
	}
	else
	{
		nodo_1->prev = NULL;
		*list = nodo_1;
	}

	nodo->prev = nodo->next;
	nodo->next = nodo_1->next;
	nodo->prev->next = nodo;
	nodo_1->next = nodo;

}

/**
 * cocktail_sort_list - function that sorts a doubly
 * linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: linked list
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	int flag = 1;

	if (list == NULL || *list == NULL)
		return;

	current = *list;

	while (flag != 0)
	{
		flag = 0;
		while (current != NULL && current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap(current, current->next, list);
				print_list(*list);
				flag = 1;
			}
			else
			{
				current = current->next;
			}
		}
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap(current->prev, current, list);
				print_list(*list);
				flag = 1;
			}
			else
			{
				current = current->prev;
			}
		}
	}
}
