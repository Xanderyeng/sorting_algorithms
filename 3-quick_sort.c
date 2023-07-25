#include "sort.h"
/**
* partition - This function takes last element as pivot, places
* the pivot element at its correct position in sorted
* array, and places all smaller (smaller than pivot)
* to left of pivot and all greater elements to right
* of pivot
* @arr: pointer to array index
* @low: low value in the array.
* @high: hightest value in array
* @size: size of array.
* Return: return pivot sort
*/
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1), j, tmp;

	for (j = low; j <= (high - 1); j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			if (arr[i] != arr[j])
				print_array(arr, size);
		}
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;
	if (arr[i + 1] != arr[high])
		print_array(arr, size);
	return (i + 1);
}
/**
* quickSort - function that implements QuickSort
* @arr: Array to be sorted,
* @low: Starting index,
* @high: Ending index
* @size: size of array.
*/
void quickSort(int arr[], int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = 0;

		pi = partition(arr, low, high, size);
		quickSort(arr, low, (pi - 1), size);
		quickSort(arr, pi + 1, high, size);
	}
}
/**
* quick_sort - funtion that sorts an array with lomuto
* @array: array to sort
* @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	quickSort(array, 0, size - 1, size);
}
