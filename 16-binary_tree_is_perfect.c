#include "binary_trees.h"

/**
 * subtree_complete - function that checks if a node is a leaf
 *
 * @tree: is a pointer to the node to check
 *
 * Return: return 1 if the tree is coplete, otherwise 0
 */
int subtree_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL && tree->right != NULL)
		return (1 && subtree_complete(tree->left)
			&& subtree_complete(tree->right));

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (subtree_complete(tree->left) && subtree_complete(tree->right));
}

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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: return 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree_height(tree->left) == tree_height(tree->right))
		return (subtree_complete(tree));
	return (0);
}
