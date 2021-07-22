#include "binary_trees.h"

/**
 * tree_sibling - function that finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: a pointer to the sibling node, if node or parent is NULL
 */
binary_tree_t *tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}

/**
 * binary_tree_uncle - function that finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: a pointer to the uncle node, if node or parent is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	return (tree_sibling(node->parent));
}
