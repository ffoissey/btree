#include "btree.h" 

/*
** parent and uncle are red
*/

static void	bad_parent_and_uncle_color(t_tree *node)
{
	t_tree *gp;

	gp = grandparent(node);
	parent(node)->color = BLACK;
	uncle(node)->color = BLACK;
	if (gp != NULL)
	{
		gp->color = RED;
		btree_balance(gp);
	}
}

static void	btree_rotation(t_tree *node)
{
	t_tree	*gp;
	t_tree	*p;

	gp = grandparent(node);
	p = parent(node);
	if (gp && gp->left && node == gp->left->right)
	{
		btree_rotleft(p);
		node = node->left;
	}
	else if (gp && gp->right && node == gp->right->left)
	{
		btree_rotright(p);
		node = node->right;
	}
	gp = grandparent(node);
	p = parent(node);
	if (gp && node == p->left)
		btree_rotright(gp);
	else if (gp)
		btree_rotleft(gp); //
	p->color = BLACK;
	gp->color = RED;
}

void	btree_balance(t_tree *node)
{
	if (parent(node) == NULL)
		node->color = BLACK;
	else if (parent(node)->color == BLACK)
		return ;
	else if (uncle(node) != NULL && uncle(node)->color == RED)
		bad_parent_and_uncle_color(node);
	else
		btree_rotation(node);
}
