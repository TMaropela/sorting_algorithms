#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to be swapped.
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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Printing our array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
