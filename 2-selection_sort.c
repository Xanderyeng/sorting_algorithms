#include "sort.h"
/**
 *  selection_sort - function that sort a list of number wuth selection
 *  @array: given array
 *  @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, j, k;
	int tmp;

	if (array != NULL && size > 1)
	{
		while (i <= (size - 2))
		{
			tmp = array[i];
			k = i;
			for (j = i + 1; j < size; j++)
			{
				if (tmp > array[j])
				{
					tmp = array[j];
					k = j;
				}
			}
			array[k] = array[i];
			array[i] = tmp;
			if (k != i)
				print_array(array, size);
			i++;
		}
	}
}
