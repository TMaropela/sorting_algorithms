#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swapping two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmpk;

	tmpk = *a;
	*a = *b;
	*b = tmpk;
}

/**
 * lomuto_partition - Order a subset of our array of integers
 * 			 according to
 *                    the lomuto partition scheme (last element is pivot).
 * @array: The array of our integers.
 * @size: The size of our array.
 * @left: The starting index of our subset to order.
 * @right: The ending index of our subset to order.
 *
 * Return: Our final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, top, below;

	pivot = array + right;
	for (top = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (top < below)
			{
				swap_ints(array + below, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swap_ints(array + top, pivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - Implementing the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of our array.
 * @left: The starting index of our array partition to order.
 * @right: The ending index of our array partition to order.
 *
 * Description: Using the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int sect;

	if (right - left > 0)
	{
		sect = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, sect - 1);
		lomuto_sort(array, size, sect + 1, right);
	}
}

/**
 * quick_sort - Sort our array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 * Printing the array after each swap of our elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
