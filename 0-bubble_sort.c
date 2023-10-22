#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, m;
	int t, swap;

	if (size < 2)
		return;

	for (n = 0; n < size - 1; n++)
	{
		swap = 0;

		for (m = 0; m < size - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				t = array[m];
				array[m] = array[m + 1];
				array[m + 1] = t;
				swap = 1;
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
