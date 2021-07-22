#include "binary_trees.h"

/**
* binary_tree_nodes - counts the leaves in a binary tree
* @tree:  pointer to the root node of the tree to count the number of leaves
* Return: count of leaves, 0 if tree is NULL
**/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->right != NULL || tree->left != NULL)
		return (1 + binary_tree_nodes(tree->right)
			+ binary_tree_nodes(tree->left));

	return (0);
}
