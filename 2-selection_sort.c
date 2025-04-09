#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: pointer to the given array
 * @size: number of elements in the given array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, i_min, temp;

	for (i = 0; i < size - 1; i++)
	{
		i_min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i_min])
			{
				i_min = j;
			}
		}
		temp = array[i];
		array[i] = array[i_min];
		array[i_min] = temp;
	}
}

