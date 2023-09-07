#include "lists.h"

/**
 * find_listint_loop - Program that finds the loop in a linked list using
 * Floyd's Cycle Detection Algorithm
 *
 * Floyd's Cycle Detection Algorithm, also known as the "tortoise and hare"
 * algorithm, is a method to detect cycles or loops in a data structure
 * by using two pointers that move at different speeds through the structure;
 * if there is a cycle, these pointers will eventually meet;
 * otherwise, they will reach the end of the structure without meeting
 *
 * @head: a pointer to the head of the linked list
 *
 * Return: the address of the node where the loop starts,
 * or NULL if there is no loop
 */


listint_t *find_listint_loop(listint_t *head)
{
	if (head == NULL || head->next == NULL)
	{
		return (NULL);
	}

	listint_t *tortoise = head;
	listint_t *hare = head;


	while (hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;      /* Move tortoise one step */
		hare = hare->next->next;        /* Move hare two steps */

		if (tortoise == hare)
		{
			/* The pointers have met, indicating a loop exists */
			tortoise = head; /* Reset tortoise to the head */
			while (tortoise != hare)
			{
				/* Move both pointers one step at a time until they meet */
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (tortoise); /* Return the node where the loop starts */
		}
	}

	return (NULL);
}
