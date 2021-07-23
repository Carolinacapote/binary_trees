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

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}

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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: return 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int pow_result = 0;

	if (tree == NULL)
		return (0);
	_pow(pow_result, 2, (tree_height(tree) + 1));
	return (tree_size(tree) == pow_result - 1);
}

/**
 * complete - auxiliar binary_tree_complete function
 * @tree: pointer to the node to tranverse.
 * Return: 1 if tree is complete, otherwise 0
 */
int complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right)
		return (0);

	if (tree->left && tree->right == NULL)
		return (tree->parent->right->left == NULL);

	return (complete(tree->left) && complete(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: is a pointer to the root node of the tree to traverse
 *
 * Return: 1 if the tree is complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_perfect(tree) == 1)
		return (1);

	if (tree_height(tree->left) == tree_height(tree->right)
	    || tree_height(tree->right) + 1 == tree_height(tree->left))
	{
		return (complete(tree));
	}

	return (0);
}
