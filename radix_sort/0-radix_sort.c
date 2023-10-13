#include "sort.h"

/**
 * sort_by_current_digit - program that sorts the array based on
 * the current significant digit
 *
 * @array: the array to sort
 * @size: the size of the array
 * @tmp: temporary array used for sorting
 * @exp: the current digit to sort by, represented as a power of 10
 *
 * Return: always returns 0, used for compatibility with other
 * sorting functions
 */
int sort_by_current_digit(int *array, ssize_t size, int *tmp, long exp)
{
	ssize_t i;
	int aux[10] = {0};

	for (i = 0; i < size; i++)
		aux[(array[i] / exp) % 10]++, tmp[i] = 0;
	for (i = 1; i < 10; i++)
		aux[i] += aux[i - 1];
	for (i = size - 1; i >= 0; i--)
		tmp[--aux[(array[i] / exp) % 10]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	return (0);
}

/**
 * radix_sort - Program that sorts an array of integers using
 * Radix sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: nothing (void)
 */

void radix_sort(int *array, size_t size)
{
	size_t i;
	long exp = 1;
	int *tmp, max = INT_MIN;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	for (i = 0; i < size; i++)
		max = array[i] > max ? array[i] : max;

	while (max / exp > 0)
	{
		sort_by_current_digit(array, size, tmp, exp);
		print_array(array, size);
		exp *= 10;
	}
	free(tmp);
}
