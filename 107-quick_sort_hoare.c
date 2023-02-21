#include "sort.h"

/**
 * swap - Swaps to integers
 *
 * @a: First value
 * @b: Second value
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition_hoare - Function that finds the partition,
 * for the quicksort using Hoare's partition scheme
 *
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 *
 * Return: Pivot index
 */
size_t partition_hoare(int *array, int low, int high, size_t size)
{
	int i, j;
	int pivot = array[low];

	/* Index of smaller elements */
	i = low - 1;
	/* Index of higher elements */
	j = high + 1;

	while (low < high)
	{
		/* Find leftmost element >= to pivot */
		while (array[i] < pivot)
			i++;
		/* Find rightmost element <= to pivot */
		while (array[j] > pivot)
			j--;
		/* If two pointers met */
		if (i >= j)
			return (j);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
	return (high);
}

/**
 * quicksort_hoare - Recursive function that sorts an array of integers,
 * in ascending order using the Quick sort algorithm
 *
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
	int p_idx;

	if (low < high)
	{
		/* Partition array based on pivot */
		p_idx = partition_hoare(array, low, high, size);

		/* Sort items bfr pivot */
		quicksort_hoare(array, low, p_idx, size);
		/* Sort items aftr pivot */
		quicksort_hoare(array, p_idx + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Function that sorts an array of integers,
 * in ascending order using the Quick sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size < 2)
		return;

	low = 0;
	high = size - 1;

	quicksort_hoare(array, low, high, size);
}
