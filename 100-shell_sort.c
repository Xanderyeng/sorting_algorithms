#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers in
 * ascending order using the Shell sort
 * @array: array the number
 * @size: len the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, i = 0, j = 0;
	int temp = 0;

	if (array != NULL && size > 1)
	{
		while (gap < size / 3)
			gap = gap * 3 + 1;

		while (gap > 0)
		{
			for (i = gap; i < size; i++)
			{
				temp = array[i];
				for (j = i; j >= gap && array[j - gap] > temp; j = j - gap)
				{
					array[j] = array[j - gap];
				}
				array[j] = temp;
			}
			gap = (gap - 1) / 3;
			print_array(array, size);
		}
	}
}
