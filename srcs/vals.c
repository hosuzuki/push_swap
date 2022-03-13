#include "push_swap.h"

void	vals_storage(t_stack *stack, t_stacks *stacks, t_sort *sort, char **record)
{
	static t_stack	*st[2]; //forbidden
	static t_stacks	*sts;
	static t_sort	*s;
	static char 		**r;

	if (!stack && !stacks && !sort && !record)
	{
		if (r)
			free_all(st[0], st[1], s, *r);
		else
			free_all(st[0], st[1], s, NULL);
		free(sts);
		free(r);
		return ;
	}
	if (stack && !st[0])
		st[0] = stack; // stack_a will be stored here.
	else if (stack && !st[1] && st[0] != stack)
		st[1] = stack; // stack_b will be stored here.
	if (stacks)
		sts = stacks;
	if (sort)
		s = sort;
	if (record)
		r = record;
}

