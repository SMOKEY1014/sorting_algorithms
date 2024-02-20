#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 *               Bubble Sort algorithm.
 *
 * @array: Pointer to the first element of the array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (!array || !size)
		return;

	/* Outer loop for traversing the array */
	for (i = 0; i < size - 1; i++)
	{
		/* Inner loop for comparison and swapping */
		for (j = 0; j < size - i - 1; j++)
		{
			/* If current element is greater than the next element, swap */
			if (array[j] > array[j + 1])
			{
				temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				/* Print the array after every outer loop iteration */
				print_array(array, size);
			}
		}
	}
}

