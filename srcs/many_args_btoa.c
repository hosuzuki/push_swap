#include "push_swap.h"

static int	over_pivot(t_stack *stack, int pv, int lv, int rv)
{
	t_stack	*head;
	int		count;

	count = 0;
	head = stack;
	stack = stack->next;
	while (stack != head && stack->val >= lv && stack->val <= rv)
	{
		if (stack->val > pv)
			count++;
		stack = stack->next;
	}
	return (count);
}

static void	replace(t_stacks *stacks, int p_count, int r_count, int pr_count)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	while (pr_count > 0)
	{
		r_rot(a, 1);
		pr_count--;
	}
	while (r_count > 0)
	{
		r_rot(b, 2);
		r_count--;
	}
	while (p_count > 0)
	{
		push(a, b, 1);
		p_count--;
	}
}

static void	divide(t_stacks *stacks, size_t p[], int c)
{
	int		p_count;
	int		r_count;
	int		pr_count;

	p_count = 0;
	r_count = 0;
	pr_count = 0;
	while (c > 0)
	{
		if (stacks->b->next->val > stacks->sort->array[p[1]])
		{
			p_count += btoa_push(stacks);
			c--;
		}
		else if (stacks->b->next->val > stacks->sort->array[p[0]])
		{
			p_count += btoa_push(stacks);
			pr_count += btoa_rot(stacks->a, 1);
		}
		else
			r_count += btoa_rot(stacks->b, 2);
	}
	replace(stacks, p_count, r_count, pr_count);
}

void btoa(t_stacks *stacks, size_t l, size_t r)
{
	int		count;
	size_t	p[2];

	p[0] = (l + r) /2;
	p[1] = (p[0] + r) /2;
	count = over_pivot(stacks->b, stacks->sort->array[p[0]],
			stacks->sort->array[l], stacks->sort->array[r]);
	if (r - l <= 9 && r >= l)
	{
		btoa_pushall(stacks, l, r);
		return ;
	}
	divide(stacks, p, count);
	btoa(stacks, p[1] + 1, r);
	btoa(stacks, p[0] + 1, p[1]);
	btoa(stacks, l, p[0]);
}
