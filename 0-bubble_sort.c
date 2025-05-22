#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort -  sorts an array of integers in ascending order using
 *                the Bubble sort algorithm
 * @array: pointer to the given array
 * @size: number of elements in the given array
 * Description: - outer loop, for each iteration build the sorted part of the array with positions from size-i to size-1
 *              - inner loop, compares adjacent elements, place the largest unsorted element at the end(0 to size-i-1)
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, flag, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)                  /* outer loop to build sorted part(size-i to size-1) */
	{
		flag = 0;                               /* set flag to 0, means no swap occurs yet */

		for (j = 0; j < size - 1 - i; j++)      /* inner loop to handle the unsorted part by comparing and swapping elements */
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;    /* largest one bubble to the end */
				flag = 1;               /* indiates swap occurred */
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
