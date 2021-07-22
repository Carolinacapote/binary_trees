#include "binary_trees.h"

/**
 * levelorder - function that goes through a binary tree
 * @tree: pointer to the node to tranverse.
 * @func: is a pointer to a function to call for each node.
 * Return: void
 */
void levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
		func(tree->left->n);
	if (tree->right != NULL)
		func(tree->right->n);

	levelorder(tree->left, func);
	levelorder(tree->right, func);
}

/**
 * binary_tree_levelorder - function that goes through a binary tree using
 * level-order traversal
 *
 * @tree: is a pointer to the root node of the tree to traverse
 *
 * @func: is a pointer to a function to call for each node. The value in the
 * node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	levelorder(tree, func);
}
