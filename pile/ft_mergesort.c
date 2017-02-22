#include "libft.h"

static void		push_min_on_c(t_pile **ab, t_pile **c)
{
	t_pile		*node;

	node = ft_pilepop(ab);
	node->prev = NULL;
	ft_pilepushback(c, node);
}

static void				print(t_pile *elem)
{
	printf("[%i]", *(int*)elem->content);
}

static t_pile			*merge(t_pile **a, t_pile **b ,\
						t_bool (*cmp)(void *a, void *b))
{
	t_pile		*c;

	c = NULL;
	while (*a && *b)
	{
		if (cmp((*a)->content, (*b)->content) == true)
			push_min_on_c(a, &c);
		else
			push_min_on_c(b, &c);
	}
	while (*a)
		push_min_on_c(a, &c);
	while (*b)
		push_min_on_c(b, &c);
	printf("\n");
	ft_pileiter(c, print);
	printf("\n");
	return (c);
}

t_pile				*ft_mergesort(t_pile **pile, \
					t_bool (*cmp)(void *a, void *b))
{
	t_pile			*a;
	t_pile			*b;
	t_pile			*node;
	size_t			len;
	size_t			index;

	len = ft_pilesize(*pile);
	if (len <= 1)
		return (*pile);
	a = NULL;
	b = NULL;
	index = 0;
	while (*pile)
	{
		node = ft_pilepop(pile);
		if (index < len / 2)
			ft_pilepush(&a, node);
		else
			ft_pilepush(&b, node);
		index++;
	}
	a = ft_mergesort(&a, cmp);
	b = ft_mergesort(&b, cmp);
	return (merge(&a, &b, cmp));
}
