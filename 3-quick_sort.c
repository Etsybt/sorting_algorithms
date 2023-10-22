#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array
 * @size: size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - Recursive helper function for Quick sort
 * @array: The array to be sorted
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: Number of elements in the array
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
	int idx;

	if (low < high)
	{
		idx = lomuto_partition(array, low, high, size);
		_quick_sort(array, low, idx - 1, size);
		_quick_sort(array, idx + 1, high, size);
	}
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme for Quick sort
 *
 * @array: The array to be sorted.
 * @high: The pivot element index.
 * @low: The start index of the partition.
 * @size: The size of the array.
 * Return: the final position of the pivot.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int n = low - 1;
	int m, t;

	for (m = low; m <= high - 1; m++)
	{
		if (array[m] < pivot)
		{
			n++;
			if (n != m)
			{
				t = array[n];
				array[n] = array[m];
				array[m] = t;
				print_array(array, size);
			}
		}
	}
	if (n + 1 != high)
	{
		t = array[n + 1];
		array[n + 1] = array[high];
		array[high] = t;
		print_array(array, size);
	}
	return (n + 1);
}
