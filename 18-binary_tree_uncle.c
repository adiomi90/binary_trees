#include "binary_trees.h"

/**
 * binary_tree_uncle - search for the uncle of a node
 * @node: a node's pointer
 * Return: pointer to the uncle node or NULL if non
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
	{
		return (NULL);
	}
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - search for siblings
 * @node: siblings node pointer
 * Return: pointer to the sibling node or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
	{
		return (NULL);
	}

	if (node == node->parent->right)
	{
		return (node->parent->left);
	}
	else
	{
		return (node->parent->right);
	}
}
