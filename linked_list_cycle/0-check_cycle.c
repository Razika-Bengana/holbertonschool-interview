#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it
 *
 * @list: A pointer to the head of the linked list.
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */

int check_cycle(listint_t *list)
{
	/*
	 * slow pointer moves one step at a time in the list traversal
	 * fast pointer moves two steps at a time in the list traversal
	*/
	listint_t *slow, *fast;

/* Initialize slow and fast pointers to the start of the list */
	slow = list;
	fast = list;
/*
 * Traverse the list with slow and fast pointers until
 * fast reaches the end or a cycle is detected
*/
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

/* If there is a cycle, slow and fast will eventually meet */
		if (slow == fast)
		{
			return (1);
		}
	}
	return (0);
}
