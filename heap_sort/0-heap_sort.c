#include "sort.h"

/**
 * getParentIndex - Get the index of the parent node in a binary heap
 *
 * @index: Index of the current node
 * Return: Index of the parent node
 */

int getParentIndex(int index)
{
	return ((index - 1) / 2);
}

/**
 * getLeftChildIndex - Get the index of the left child node in a binary heap
 *
 * @index: Index of the current node
 * Return: Index of the left child node
 */

int getLeftChildIndex(int index)
{
	return ((2 * index) + 1);
}

/**
 * heapify - Rearrange the elements in the array to form a valid max heap
 *
 * @array: The array to be converted to a max heap
 * @size: Size of the array
 */

void heapify(int *array, size_t size)
{
	int start;

	start = getParentIndex(size - 1);

	while (start >= 0)
	{
		siftDown(array, size, start, size - 1);
		start--;
	}
}

/**
 * siftDown - Perform the sift-down operation to maintain the max heap property
 *
 * @array: The array representing the binary heap
 * @size: Size of the array
 * @start: The index from which to start sift-down
 * @end: The index where to stop sift-down
 */

void siftDown(int *array, size_t size, int start, int end)
{
	int root, swap, temp, child;

	root = start;

	while (getLeftChildIndex(root) <= end)
	{
		child = getLeftChildIndex(root);
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */

void heap_sort(int *array, size_t size)
{
	int iEnd, temp;

	if (!array || size < 2)
		return;

	heapify(array, size);

	iEnd = (int)size - 1;
	while (iEnd > 0)
	{
		temp = array[iEnd];
		array[iEnd] = array[0];
		array[0] = temp;
		print_array(array, size);
		iEnd--;
		siftDown(array, size, 0, iEnd);
	}
}
