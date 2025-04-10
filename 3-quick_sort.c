#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * lomuto_partition - partition the array using the lomuto scheme
 * @array: a pointer to the  given array
 * @start: start index of sub-array
 * @end: end index of the sub-array(pivot is array[end])
 * @size: number of elements in the array
 * Return: final index of the pivot
 * Description: - start with the pivot at the end of a sub-array
 *              - move all elements smaller than pivot to the left(using partition_index to track where to place them)
 *              - swap the pivot into array[partition_index] 
 *              - after swap: - array[partition_index] == pivot
 *                            - all elements left of the pivot are < pivot
 *                            - all elements left of the pivot are >= pivot
 */

int lomuto_partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];           
	int partition_index = start;   /* keep track of the index where smaller elements than pivot should be placed */
	int i, temp;

	for (i = start; i < end; i++)    
	{
		if (array[i] < pivot)     /* if current element is smaller than the pivot */
		{
			if (array[partition_index] != array[i])     /* avoid unnecessary swap if values are the same */
			{       
				/* every time a smaller element is found: swap it with the element at partition_index */
				temp = array[partition_index];   
				array[partition_index] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			partition_index++;                        /* then increment partition_index */ 
		}
	}
	if (array[partition_index] != array[end])
	{
		temp = array[partition_index];
		array[partition_index] = array[end];     /* swap pivot to its final position */
		array[end] = temp;
		print_array(array, size);
	}
	return (partition_index);  /* return the index where the pivot now lives — its final, sorted, correct position */
}
/**
 * quicksort_recursive - recursively applies quicksort to sub-arrays
 * @array: a pointer to the  given array
 * @start: start index of sub-array
 * @end: end index of the sub-array(pivot is array[end])
 * @size: number of elements in the array
 * Description: only need to recursively sort the left and right subarrays 
 *              pivot is in between them at its correct position, no need to sort anymore
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
	if (array == NULL || size < 2)      /* if the array is null or has fewer than 2 elements, no need to sort */
		return;

	quicksort_recursive(array, 0, size - 1, size);    /* call the recursive function with full array boundaries */
}
