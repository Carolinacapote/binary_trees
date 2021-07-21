#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 *
 * @parent: is a pointer to the parent node of the node to create
 *
 * @value: is the value to put in the new node
 *
 * Return: Your function must return a pointer to the new node,
 *         or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;

	if (parent == NULL)
		parent = new_node;
	else
		new_node->parent = parent;

	return (new_node);
}



