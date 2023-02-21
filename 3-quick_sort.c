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
 * partition - Function that finds the partition,
 * for the quicksort using Lomuto scheme
 *
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 *
 * Return: Pivot index
 */
size_t partition(int *array, int low, int high, size_t size)
{
	int i, j;
	int pivot = array[high];

	/* Index of smaller elements */
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Recursive function that sorts an array of integers,
 * in ascending order using the Quick sort algorithm
 *
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p_idx;

	if (low < high)
	{
		/* Partition array based on pivot */
		p_idx = partition(array, low, high, size);

		/* Sort items bfr pivot */
		quicksort(array, low, p_idx - 1, size);
		/* Sort items aftr pivot */
		quicksort(array, p_idx + 1, high, size);
	}
}

/**
 * quick_sort - Function that sorts an array of integers,
 * in ascending order using the Quick sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size < 2)
		return;

	low = 0;
	high = size - 1;

	quicksort(array, low, high, size);
}
