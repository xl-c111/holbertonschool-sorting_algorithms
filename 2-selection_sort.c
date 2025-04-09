#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: pointer to the given array
 * @size: number of elements in the given array
 * Description: - outer loop for each iteration, select the current smallest value in the unsorted part(from i to size -2)
 *                           and place it at the end of the sorted part (from 0 to i-1)
 *              - inner loop to compare the unsorted part(i+1 to size-1) to see if there is a smaller one
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)   /* outer: to build the sorted part (from 0 to i-1) */
	{
		min_index = i;               /* sets min_index (the index of the current minimum) to i initially */

		for (j = i + 1; j < size; j++) /* inner: compare the rest array(i+1 to size-1) to see if there is a smaller one */
		{
			if (array[j] < array[min_index])
			{
				min_index = j;       /* found a new min, update min_index */
			}
		}
		if (i != min_index)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}

