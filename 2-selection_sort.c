#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t n, m, index;
	int t;

	for (n = 0; n < size - 1; n++)
	{
		index = n;
		for (m  = n + 1; m < size; m++)
		{
			if (array[m] < array[index])
				index = m;
		}
		if (index != n)
		{
			t = array[n];
			array[n] = array[index];
			array[index] = t;
			print_array(array, size);
		}
	}
}
