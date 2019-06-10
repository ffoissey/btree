#include "btree.h"

t_tree		*btree_new(void const *data, size_t data_size)
{
	t_tree		*new;

	if (!(new = (t_tree *)malloc(sizeof(t_tree))))
		return (NULL);
	ft_bzero(new, sizeof(t_tree));
	if (data != NULL && data_size > 0)
	{
		if (!(new->data = malloc(data_size)))
		{
			free(new);
			return (NULL);
		}
	}
	new->data_size = data_size;
	ft_memcpy(new->data, data, data_size);
	return (new);
}

static void	btree_sub_add(t_tree *root, t_tree *new, int (*f)(void *, void *))
{
	if (root != NULL && f(root->data, new->data) > 0)
	{
		if (root->left != LEAF)
		{
			btree_sub_add(root->left, new, f);
			return ;
		}
		else
			root->left = new;
	}
	else if (root != NULL)
	{
		if (root->right != LEAF)
		{
			btree_sub_add(root->right, new, f);
			return ;
		}
		else
			root->right = new;
	}
	new->parent = root;
/*	new->left = LEAF;
	new->right = LEAF;
	new->color = RED;*/
}

t_tree	*btree_add_extend(t_tree *root, t_tree *new, int (*f)(void *, void *))
{
	if (new == NULL)
		return (root);
	if (root == NULL)
		root = new;
	else
		btree_sub_add(root, new, f);
	btree_balance(new);
	root = new;
	while (parent(root) != NULL)
		root = parent(root);
	return (root);
}

void	btree_add(t_tree **root, t_tree *new, int (*f)(void *, void *))
{
	*root = btree_add_extend(*root, new, f);
}


static void	sub_free_btree(t_tree *node, void (*f)(void *))
{
	if (node != LEAF)
	{
		sub_free_btree(node->left, f);
		sub_free_btree(node->right,f );
		f(node->data);
		free(node);
	}
}

void	free_btree(t_tree **root, void (*f)(void *))
{
	sub_free_btree(*root, f);
	*root = NULL;
}
