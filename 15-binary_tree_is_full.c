#include "binary_trees.h"

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of a binary tree
 * If tree is NULL, the function must return 0
 **/
int tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}
/**
* binary_tree_is_full - function that checks if a binary tree is full
* @tree:  pointer to the root node of the tree to check
* Return: 1 if the tree is full, otherwise 0.
**/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_size(tree) % 2);
}
