#include "binary_trees.h"

/**
 * tree_height - function that creates a binary tree node
 *
 * @tree: is a pointer to the parent node of the node to create
 *
 * Return: Your function must return a pointer to the new node,
 *         or NULL on failure
 */
int tree_height(const binary_tree_t *tree)
{
	int height_l;
	int height_r;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		height_l = 1 + tree_height(tree->left);
	else
		height_l = 0;

	if (tree->right != NULL)
		height_r = 1 + tree_height(tree->right);
	else
		height_r = 0;

	if (height_l == 0 && height_r == 0)
		height_l = 1;

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: Balance factor or 0 if the tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_height(tree->left) - tree_height(tree->right));
}
