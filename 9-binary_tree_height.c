#include "binary_trees.h"

/**
 * binary_tree_height - function that creates a binary tree node
 *
 * @tree: is a pointer to the parent node of the node to create
 *
 * Return: Your function must return a pointer to the new node,
 *         or NULL on failure
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		height_l = 1 + binary_tree_height(tree->left);
	else
		height_l = 0;

	if (tree->right != NULL)
		height_r = 1 + binary_tree_height(tree->right);
	else
		height_r = 0;

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}


