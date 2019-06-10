#include "btree.h"

void	btree_rotleft(t_tree *node)
{
	t_tree	*tmp;

	tmp = node->right;
	node->right = tmp->left;
	if (tmp->left != LEAF)
		tmp->left->parent = node;
	tmp->parent = parent(node);
	if (parent(node) == NULL)
	{
		tmp->left = node;
	}
	else if (node == node->parent->left)
		node->parent->left = tmp;
	else
		node->parent->right = tmp;
	tmp->left = node;
	node->parent = tmp;
}

void	btree_rotright(t_tree *node)
{
	t_tree	*tmp;

	tmp = node->left;
	node->left = tmp->right;
	if (tmp->right != LEAF)
		tmp->right->parent = node;
	tmp->parent = parent(node);
	if (parent(node) == NULL)
	{
		tmp->right = node;
	}
	else if (node == node->parent->right)
		node->parent->right = tmp;
	else
		node->parent->left = tmp;
	tmp->right = node;
	node->parent = tmp;
}
