#include "sort.h"


/**
 * counting_sort - Program that performs counting sort on an array
 * based on a specific digit
 *
 * @array: the array to sort
 * @size: the size of the array
 * @digit: the place value to sort the array on (1s, 10s, 100s, etc.)
 *
 * Return: nothing (void)
 */

void counting_sort(int *array, size_t size, int digit)
{
	int output[size];
	int count[10] = {0};
	int d;
	size_t i;
	int j;

/* Count occurrences of each digit at the given place */
	for (i = 0; i < size; i++)
	{
		d = (array[i] / digit) % 10;
		count[d]++;
	}

/* Calculate the position of each element */
	for (j = 1; j < 10; j++)
	{
		count[j] += count[j - 1];
	}

/* Build the output array */
	for (j = size - 1; j >= 0; j--)
	{
		d = (array[j] / digit) % 10;
		output[count[d] - 1] = array[j];
		count[d]--;
	}

/* Copy the output array to the original array */
	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
}

/**
 * radix_sort - Program that performs radix sort on an array
 * of non-negative integers
 *
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: nothing (void)
 */

void radix_sort(int *array, size_t size)
{

/* Find the maximum element to determine the number of digits */
	int max;
	size_t i;
	int digit;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

/* Perform counting sort for each digit */
	for (digit = 1; max / digit > 0; digit *= 10)
	{
		counting_sort(array, size, digit);
		print_array(array, size);
	}
}
