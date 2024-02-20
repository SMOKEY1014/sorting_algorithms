#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection Sort algorithm.
 *
 * @array: Pointer to the first element of the array to be sorted.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || !size)
		return;

	/* Outer loop for traversing the array */
	for (i = 0; i < size - 1; i++)
	{
		size_t min_index = i;

		/* Inner loop to find the minimum element in the unsorted portion */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		/* Swap the current element with the minimum element */
		if (min_index != i)
		{
			size_t k;

			int temp = array[i];

			array[i] = array[min_index];
			array[min_index] = temp;

			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}


