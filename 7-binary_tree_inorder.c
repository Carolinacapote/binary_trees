#include "binary_trees.h"

/**
 * binary_tree_inorder - function that deletes an entire binary tree
 *
 * @tree: is a pointer to the root node of the tree to delete
 *
 * @func: is a pointer to the root node of the tree to delete
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}



