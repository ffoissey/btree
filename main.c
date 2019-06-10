#include "btree.h"

static void	print_btree(t_tree *node, int deep)
{
	char	*str;
	int		i;

	i = 0;
	if (node != LEAF)
	{
		while (i < deep)
		{
			i++;
			if (i == deep)
				ft_putstr("  |-->");
			else
				ft_putstr("  |   ");
		}
		str = node->data;
		if (node->color == RED)
			ft_printf("[\033[31m%s\033[0m]\n", str);
		else
			ft_printf("[\033[30m%s\033[0m]\n", str);
		print_btree(node->left, deep + 1);
		print_btree(node->right, deep + 1);
	}
	else
	{
		while (i < deep)
		{
			i++;
			if (i == deep)
				ft_putstr("  |-->");
			else
				ft_putstr("  |   ");
		}
		ft_printf("(\033[30m%s\033[0m)\n", "LEAF");
	}
		
}

void	free_str(void *ptr)
{
	char	*str;

	str = ptr;
	ft_strdel(&str);
}

int		ft_strcmpare(void *ptr1, void *ptr2)
{
	return (strcmp((char *)ptr1, (char *)ptr2));
}

int		main(int ac, char **av)
{
	t_tree	*tree;

	tree = NULL;
	ac--;
	while (ac > 0)
	{
		btree_add(&tree, btree_new(av[ac--], sizeof(av[ac])), ft_strcmpare);
		print_btree(tree, 0);
		ft_putendl("\n");
	}
	free_btree(&tree, free_str);
	return (0);
}
