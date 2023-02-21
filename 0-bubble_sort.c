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
 * bubble_sort - function that sorts an array of integers,
 * in ascending order using the Bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool is_swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		is_swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				is_swapped = true;
				print_array((const int *)array, size);
			}
		}
		/* If not swapped, break for optimization */
		if (!is_swapped)
			break;
	}
}
