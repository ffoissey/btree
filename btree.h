#ifndef BTREE_H
# define BTREE_H

# define RED	0
# define BLACK	1
# define LEAF	NULL
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_tree t_tree;

struct	s_tree
{
	t_tree	*left;
	t_tree	*right;
	t_tree	*parent;
	void	*data;
	size_t	data_size;
	int		color;
};

/*
*********************
******* BTREE *******
*********************
*/

void	free_btree(t_tree **root, void (*f)(void *));
t_tree	*btree_new(void const *data, size_t data_size);
void	btree_add(t_tree **root, t_tree *new, int (*f)(void *, void *));

/*
*********************
***** GENEALOGY *****
*********************
*/

t_tree	*parent(t_tree *node);
t_tree	*grandparent(t_tree *node);
t_tree	*brother(t_tree *node);
t_tree	*uncle(t_tree *node);

/*
*********************
******** ROT ********
*********************
*/

void	btree_rotright(t_tree *node);
void	btree_rotleft(t_tree *node);

/*
*********************
****** BALANCE ******
*********************
*/

void	btree_balance(t_tree *node);

#endif
