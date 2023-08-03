#include "binary_trees.h"

/**
 * bst_remove - removes a node from BST
 * @root: root node
 * @value: value to be searched and removed
 * Return: pointer to new root node
 */
bst_t *bst_remove(bst_t *root_node, int value)
{
	bst_t *node_t;

	node_t = bst_search(root_node, value);

	if (node_t)
	{
		if (binary_tree_is_leaf(node_t) == 1)
		{
			if (node_t == node_t->parent->left)
			{
				node_t->parent->left = NULL;
			}
			if (node_t == node_t->parent->right)
			{
				node_t->parent->right = NULL;
			}
			free(node_t);
			return (root_node);
		}
		if (node_t->right && node_t->right->left)
		{
			root_node = right_left_case(node_t, root_node);
		}
		else if (node_t->right)
		{
			root_node = right_case(node_t, root_node);
		}
		else
		{
			if (node_t->parent)
			{
				node_t->parent->right = node_t->left;
			}
				node_t->left->parent = node_t->parent;
			if (root_node == node_t)
			{
				root_node = node_t->left;
			}
			free(node_t);
		}
	}
	return (root_node);
}


/**
 * bst_search - bst search
 * @tree: pointer to the tree's root
 * @value: the search value
 * Return: pointer to the value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *search_node = (bst_t *)tree;

	if (!tree)
	{
		return (NULL);
	}

	while (search_node)
	{
		if (value == search_node->n)
		{
			return (search_node);
		}
		if (value < search_node->n)
		{
			search_node = search_node->left;
		}
		else if (value > search_node->n)
		{
			search_node = search_node->right;
		}
	}

	return (NULL);
}

/**
 * right_case - removes a node from a BST for node->right
 * @root: tree root
 * @node: node to delete
 * Return: pointer the tree root
 */
bst_t *right_case(bst_t *node, bst_t *root)
{
	node->right->left = node->left;
	node->right->parent = node->parent;
	if (node->parent)
	{
		if (node == node->parent->left)
		{
			node->parent->left = node->right;
		}
		if (node == node->parent->right)
		{
			node->parent->right = node->right;
		}
	}
	if (node->left)
	{
		node->left->parent = node->right;
	}
	if (root == node)
	{
		root = node->right;
	}
	free(node);

	return (root);
}

/**
 * right_left_case - removes a node right to left
 * @root: root
 * @node: node to be deleted
 * Return: the tree root
 */
bst_t *right_left_case(bst_t *node, bst_t *root)
{
	node->right->left->right = node->right;
	node->right->left->parent = node->parent;
	node->right->left->left = node->left;
	if (node->left)
	{
		node->left->parent = node->right->left;
	}
		node->right->parent = node->right->left;
	if (root == node)
	{
		root = node->right->left;
	}
	else
	{
		if (node == node->parent->left)
		{
			node->parent->left = node->right->left;
		}
		if (node == node->parent->right)
		{
			node->parent->right = node->right->left;
		}
	}
	node->right->left = NULL;
	free(node);

	return (root);
}


/**
 * binary_tree_is_leaf - checks if its a leaf
 * @node: pointer to the node
 * Return: return 1 if node or 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int leaf = 0;

	if (node && !(node->left) && !(node->right))
	{
		leaf = 1;
	}

	return (leaf);
}
