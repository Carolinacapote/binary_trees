#include "binary_trees.h"

/**
 * tree_depth - function that creates a binary tree node
 *
 * @tree: is a pointer to the parent node of the node to create
 *
 * Return: Your function must return a pointer to the new node,
 *         or NULL on failure
 */
size_t tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->parent == NULL)
		return (0);

	return (1 + tree_depth(tree->parent));
}

/**
 * tree_sibling - function that finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: a pointer to the sibling node, if node or parent is NULL
 */
binary_tree_t *tree_sibling(const binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first->parent == second)
		return ((binary_tree_t *)second);

	if (second->parent == first)
		return ((binary_tree_t *)first);

	if (first == second)
		return ((binary_tree_t *)first);

	if (tree_depth(first) > tree_depth(second))
		return (binary_trees_ancestor(first->parent, second));

	if (tree_depth(first) < tree_depth(second))
		return (binary_trees_ancestor(first, second->parent));

	if (tree_sibling(first) != second)
		return (binary_trees_ancestor(first->parent, second->parent));

	return (first->parent);
}
