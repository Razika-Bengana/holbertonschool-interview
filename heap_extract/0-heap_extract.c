#include "binary_trees.h"

/**
 * heapify - program that restores the heap property by moving the given node
 * down the tree
 *
 * @current_node: the current node to start the heapify process
 *
 * this function compares the value of the given node with its child nodes, and
 * if necessary, swaps the values to maintain the heap property;
 * it continues this process down the tree until the heap property is restored
 *
 * Return: nothing (void)
 */

void heapify(binary_tree_t *current_node)
{
	binary_tree_t *selected_child = NULL;
	int temp_value = 0;

	while (1)
	{
		if (!current_node->left)
			break;
		else if (!current_node->right)
			selected_child = current_node->left;
		else
		{
			if (current_node->left->n >= current_node->right->n)
				selected_child = current_node->left;
			else
				selected_child = current_node->right;
		}

		if (current_node->n >= selected_child->n)
			break;

		temp_value = current_node->n;
		current_node->n = selected_child->n;
		selected_child->n = temp_value;

		current_node = selected_child;
	}
}

/**
 * count_nodes - program that counts the total number of nodes in the binary
 * tree rooted at the given node
 *
 * @current_node: the root node of the binary tree to count nodes from
 *
 * Return: the total number of nodes in the binary tree
 */

int count_nodes(heap_t *current_node)
{
	int left_count = 0, right_count = 0;

	if (!current_node)
		return (0);

	left_count = count_nodes(current_node->left);
	right_count = count_nodes(current_node->right);

	return (1 + left_count + right_count);
}

/**
 * get_last_node - program that finds and returns the last node in the binary
 * tree rooted at the given node
 *
 * @current_node: the root node of the binary tree to find the last node from
 *
 * Return: the last node in the binary tree
 */

binary_tree_t *get_last_node(heap_t *current_node)
{
	int num_nodes = 0, heap_size = 0;
	binary_tree_t *last_node = NULL;

	heap_size = count_nodes(current_node);

	for (num_nodes = 1; num_nodes <= heap_size; num_nodes <<= 1)
		;
	num_nodes >>= 2;

	for (last_node = current_node; num_nodes > 0; num_nodes >>= 1)
	{
		if (heap_size & num_nodes)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}

	return (last_node);
}

/**
 * heap_extract - program that extracts the root node value from the heap
 * and maintains the heap property
 *
 * this function extracts the value at the root of the heap, replaces it with
 * the value of the last node, and then restores the heap property by moving
 * the newly placed value down the tree using the heapify function
 *
 * @root: a pointer to the root of the heap
 *
 * Return: the extracted value from the root of the heap
 */

int heap_extract(heap_t **root)
{
	binary_tree_t *last_node = NULL, *head_node = NULL;
	int extracted_value = 0;

	if (!root || !*root)
		return (0);

	head_node = *root;
	if (!head_node->left && !head_node->right)
	{
		extracted_value = head_node->n;
		free(head_node);
		*root = NULL;
		return (extracted_value);
	}

	head_node = *root;
	extracted_value = head_node->n;

	last_node = get_last_node(*root);

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	last_node->left = head_node->left;
	last_node->right = head_node->right;
	last_node->parent = head_node->parent;

	if (head_node->left)
		head_node->left->parent = last_node;
	if (head_node->right)
		head_node->right->parent = last_node;

	*root = last_node;
	free(head_node);

	heapify(*root);

	return (extracted_value);
}
