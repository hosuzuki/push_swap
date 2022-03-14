#include "push_swap.h"

void	free_stack(t_stack *stack, int count)
{
	t_stack	*head;
	t_stack	*tmp;

	head = stack;
	stack = stack->next;
	while (stack != head && count)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
		count--;
	}
	free(head);
}

void	free_sort(t_sort *sort)
{
	free(sort->array);
	free(sort);
}

void	free_all(t_stack *stack1, t_stack *stack2, t_sort *sort, char *record)
{
	if (stack1)
		free_stack(stack1, stack1->val);
	if (stack2)
		free_stack(stack2, stack2->val);
	if (sort)
		free_sort(sort);
	if (record)
		free(record);
}

// what about ret?? is it freed?

//
/*
void	storage_all(t_stack *stack, t_stacks *stacks, t_sort *sort, char **record)
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
*/
