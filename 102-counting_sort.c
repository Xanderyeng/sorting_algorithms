#include "sort.h"

/**
 * counting_sort - function that sorts an array
 * of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to order
 * @size: len the of array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *aux, i = 0, *count = NULL, max = 0;

	if (size == 0 || size == 1)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	max = max + 1;
	count = malloc(max * sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i <= max; ++i)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, max);
	aux = malloc(size * sizeof(int));
	if (aux == NULL)
	{
		free(count);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		aux[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = aux[i];
	free(count), free(aux);
}
