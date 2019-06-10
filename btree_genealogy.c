#include "btree.h"

t_tree	*parent(t_tree *node)
{
	return (node == NULL ? NULL : node->parent);
}

t_tree	*grandparent(t_tree *node)
{
	return (parent(node) == NULL ? NULL : parent(parent(node)));
}

t_tree	*brother(t_tree *node)
{
	if (parent(node) == NULL)
		return (NULL);
	if (node == parent(node)->left)
		return (parent(node)->right);
	return (parent(node)->left);
}

t_tree	*uncle(t_tree *node)
{
	if (grandparent(node) == NULL)
		return (NULL);
	return (brother(parent(node)));
}
