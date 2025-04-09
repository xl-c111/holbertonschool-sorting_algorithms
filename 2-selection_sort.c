#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: pointer to the given array
 * @size: number of elements in the given array
 * Description: - outer loop to build the sorted part (from 0 to i-1), and then in each iteration to 
 *                           find the current smallest value in the unsorted part(from i to size -2)
 *              - inner loop to compare the unsorted part(i+1 to size-1) to see if there is a smaller one
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, i_min, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)   /* outer: to build the sorted part (from 0 to i-1) */
	{
		i_min = i;               /* set the index of current min (i_min) to i initially */

		for (j = i + 1; j < size; j++) /* inner: compare the rest array(i+1 to size-1) to see if there is a smaller one */
		{
			if (array[j] < array[i_min])
			{
				i_min = j;       /* found a new min, update i_min */
			}
		}
		if (i != i_min)
		{
			temp = array[i];
			array[i] = array[i_min];
			array[i_min] = temp;
			print_array(array, size);
		}
	}
}

