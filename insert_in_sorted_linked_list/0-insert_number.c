#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to the head of the list
 * @number: number to be inserted
 *
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *current;

/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

/* Initialize the new node */
	new_node->n = number;
	new_node->next = NULL;

/* If the list is empty, insert the new node as the head */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

/* If the number is smaller than the head, insert the new node as the head */
	if (number < (*head)->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

/* Traverse the list to find the correct position to insert the new node */
	current = *head;
	while (current->next != NULL && current->next->n <= number)
	{
		current = current->next;
	}

/* Insert the new node */
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
