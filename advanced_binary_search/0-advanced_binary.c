#include "search_algos.h"

/**
 * binary_search_recursion - program that searches for a value
 * in a sorted array using recursion
 *
 * @array: the sorted array to search in
 * @value: the value to search for
 * @left: the left index of the current search range
 * @right: the right index of the current search range
 *
 * Return: the index of the found value, or -1 if not found
 */

int binary_search_recursion(int *array, int value, size_t left, size_t right)
{
	size_t middle, current_index;

	if (!array)
		return (-1);

	middle = (left + right) / 2;

/* Print the current search range for visualization */
	printf("Searching in array: ");
	for (current_index = left; current_index <= right; current_index++)
		printf("%i%s", array[current_index], current_index == right ?
		       "\n" : ", ");

	if (array[left] == value)
		return ((int)left);

	if (array[left] != array[right])
	{
		if (array[middle] < value)
			return (binary_search_recursion(array, value,
							middle + 1, right));
		if (array[middle] >= value)
			return (binary_search_recursion(array, value, left,
							middle));
	}

	return (-1);
}

/**
 * advanced_binary - program that searches for a value in a sorted array
 * using advanced binary search
 *
 * @array: The sorted array to search in
 * @size: The size of the array
 * @value: The value to search for
 *
 * Return: the index of the found value, or -1 if not found
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;

	if (!array)
		return (-1);

	return (binary_search_recursion(array, value, left, right));
}
