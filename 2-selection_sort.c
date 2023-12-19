#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swapped.
 * @b: The second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmpk;

	tmpk = *a;
	*a = *b;
	*b = tmpk;
}

/**
 * selection_sort - Sort our array of integers in ascending order
 *                  using our selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Printing the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, k;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (k = i + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
