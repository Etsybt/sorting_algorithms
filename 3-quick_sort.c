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
	if (size < 2)
		return;
	lomuto_partition(array, size, size - 1, 0);
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme for Quick sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @high: The pivot element index.
 * @low: The start index of the partition.
 */
void lomuto_partition(int *array, size_t size, int high, int low)
{
	int pivot = array[high];
	int n = low - 1;
	int m, t;

	for (m = low; m < high; m++)
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
	if (array[high] != array[n + 1])
	{
		t = array[n + 1];
		array[n + 1] = array[high];
		array[high] = t;
		print_array(array, size);
	}
	if (n + 1 < high)
		lomuto_partition(array, size, high, n + 1);
	if (n + 1 > low)
		lomuto_partition(array, size, n, low);
}
