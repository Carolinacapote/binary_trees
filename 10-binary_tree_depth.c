#include "binary_trees.h"

/**
 * binary_tree_depth - function that creates a binary tree node
 *
 * @tree: is a pointer to the parent node of the node to create
 *
 * Return: Your function must return a pointer to the new node,
 *         or NULL on failure
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->parent == NULL)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}
