#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * lomuto_partition - partition the array using lomuto scheme
 * @array: a pointer to the  given array
 * @start: start index of sub-array
 * @end: end index of the sub-array(pivot is array[end])
 * @size: number of elements in the array
 * Return: final index of the pivot
 *
 */

int lomuto_partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int partition_index = start;
	int i, temp;

	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			if (array[partition_index] != array[i])
			{
				temp = array[partition_index];
				array[partition_index] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			partition_index++;
		}
	}
	if (array[partition_index] != array[end])
	{
		temp = array[partition_index];
		array[partition_index] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (partition_index);
}
/**
 * quicksort_recursive - recursively applies quicksort to sub-arrays
 * @array: a pointer to the  given array
 * @start: start index of sub-array
 * @end: end index of the sub-array(pivot is array[end])
 * @size: number of elements in the array
 */
void quicksort_recursive(int *array, int start, int end, size_t size)
{
	int partition_index;

	if (start < end)
	{
		partition_index = lomuto_partition(array, start, end, size);
		quicksort_recursive(array, start, partition_index - 1, size);
		quicksort_recursive(array, partition_index + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 *              Quick sort algorithm
 * @array: a pointer to the given array
 * @size: number of elements in the given array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
