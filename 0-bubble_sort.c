#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort -  sorts an array of integers in ascending order using
 *                the Bubble sort algorithm
 * @array: pointer to the given array
 * @size: number of elements in the given array
 * Description: - outer loop, for each iteration build the sorted part of array by adding on more 
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, flag, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)                      /* outer loop to control */
	{
		flag = 0;                                   /* set flag to 0, means no swap occurs yet */

		for (j = 0; j < size - 1 - i; j++)          /* */
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
