#include "search_algos.h"

/**
 * recursive_advanced_binary - program that uses recursive binary search
 * to finds the index of the first occurrence of a value in a sorted array
 *
 * @array: a pointer to the first element of the array to search in
 * @low: the index of the lower bound of the subarray
 * @high: the index of the upper bound of the subarray
 * @value: the value to search for
 *
 * Return: the index where the value is located, or -1 if not found
 */

int recursive_advanced_binary(int *array, int low, int high, int value)
{
	int i, mid;

	if (high >= low)
	{
		printf("Searching in array:");
		for (i = low; i <= high; ++i)
		{
			printf(" %d", array[i]);
			if (i != high)
			{
				printf(",");
			}
		}
		printf("\n");

		mid = low + (high - low) / 2;

/* If the value is found, check if it's the first occurrence */
		if (array[mid] == value)
		{
			if (mid == low || array[mid - 1] != value)
				return (mid);
			else
				return (recursive_advanced_binary(array, low,
								  mid - 1, value));
		}

/* If the value is greater, search the left subarray */
		if (array[mid] > value)
			return (recursive_advanced_binary(array, low,
							  mid - 1, value));

/* If the value is smaller, search the right subarray */
		return (recursive_advanced_binary(array, mid + 1, high, value));
	}

/* Value not found */
	return (-1);
}

/**
 * advanced_binary - program that uses binary search to search for
 * the first occurrence of a value in a sorted array
 *
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: the index where the value is located,
 * or -1 if not found or array is NULL
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_advanced_binary(array, 0, size - 1, value));
}
