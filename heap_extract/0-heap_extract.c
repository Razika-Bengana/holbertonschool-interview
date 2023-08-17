#include "binary_trees.h"

/**
 * heap_size - program that calculates the size of a binary heap
 *
 * @root: a pointer to the root of the heap
 *
 * Return: the size of the heap
 */

size_t heap_size(const heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * heapify_down - program that restores the Max Heap property by moving
 * the node down
 *
 * @root: a pointer to the root of the heap
 *
 * Return: nothing (void)
 */

void heapify_down(heap_t **root)
{
	heap_t *node = *root;

	while (1)
	{
		heap_t *largest = node;
		heap_t *left = node->left;
		heap_t *right = node->right;
		int temp;

		if (left != NULL && left->n > largest->n)
			largest = left;

		if (right != NULL && right->n > largest->n)
			largest = right;

		if (largest != node)
		{
			temp = node->n;
			node->n = largest->n;
			largest->n = temp;
			node = largest;
		}
		else
		{
			break;
		}
	}
}

/**
 * heap_extract - program that extracts the root node of a Max Binary Heap
 *
 * @root: the double pointer to the root node of the heap
 *
 * Return: the value stored in the root node, or 0 on failure
 */

int heap_extract(heap_t **root)
{
	int extracted_value;
	sie_t size;
	heap_t *last_node;

	if (root == NULL || *root == NULL)
		return (0);

	extracted_value = (*root)->n;
	size = heap_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	last_node = *root;

	while (last_node->right != NULL)
	{
		if (heap_size(last_node->right) == size - 1)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}

	(*root)->n = last_node->n;
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	heapify_down(root);

	free(last_node);

	return (extracted_value);
}
