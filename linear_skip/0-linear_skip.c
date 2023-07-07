#include "search.h"

/**
 * linear_skip - program that searches for a value in a sorted skip list
 * of integers
 *
 * A skip list is a data structure that enhances the search efficiency of
 * a linked list by adding multiple layers of linked nodes,
 * allowing for faster traversal through the list
 *
 * A node of the express lane is placed every index which
 * is a multiple of the square root of the size of the list
 *
 * list will be sorted in ascending order
 *
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node where the value is located,
 *         or NULL if value is not present in list or if head is NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = NULL, *stop = NULL;

	if (list == NULL)
		return (NULL);

	current = list;
	while (current && current->express && current->express->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       current->express->index, current->express->n);
		current = current->express;
	}
	stop = current;
	while (stop && stop->next != stop->express)
		stop = stop->next;

	if (current->express)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       current->express->index, current->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       current->index, current->express->index);
	}
	else
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
		       current->index, stop->index);
	}
	while (current != stop && current->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       current->index, current->n);
		current = current->next;
	}
	printf("Value checked at index [%lu] = [%i]\n",
	       current->index, current->n);
	if (current == stop)
		return (NULL);

	return (current);
}
