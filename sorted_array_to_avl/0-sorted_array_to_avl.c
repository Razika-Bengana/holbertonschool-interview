#include "binary_trees.h"

/**
 * create_tree_node - Function that creates a binary tree node
 *
 * @parent: Pointer to the parent node
 * @value: The integer stored in the new node
 *
 * Return: Pointer to the new node of the AVL tree, or NULL on failure
 */

binary_tree_t *create_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * sortedArrayToAVL - Recursive helper function to build an AVL tree
 * from a sorted array of integers
 *
 * @array: Sorted array of integers
 * @start: Starting index of the current subarray
 * @end: Ending index of the current subarray
 * @parent: Pointer to the parent node from the previous recursion frame
 *
 * Return: Pointer to the root node of the new subtree, or NULL on failure
 */

avl_t *sortedArrayToAVL(int *array, int start, int end, avl_t *parent)
{
	avl_t *root = NULL;
	int mid;

	if (!array)
		return (NULL);

	/* Base case: cannot subdivide the array any further */
	if (start > end)
		return (NULL);

	/* Find the middle value as the local root */
	mid = (start + end) / 2;
	root = create_tree_node(parent, array[mid]);
	if (!root)
		return (NULL);

	/* Recursively build the left subtree */
	root->left = sortedArrayToAVL(array, start, mid - 1, root);

	/* Recursively build the right subtree */
	root->right = sortedArrayToAVL(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array of integers
 *
 * @array: Sorted array of integers
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the new AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sortedArrayToAVL(array, 0, (int)(size - 1), NULL));
}
