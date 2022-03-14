#include "push_swap.h"

static int	count_more_than_pivot(t_stack *stack, int pv, int lv, int rv)
{
	t_stack	*head;
	int		count;

	count = 0;
	head = stack;
	stack = stack->next;
	while (stack != head && lv <= stack->val && stack->val <= rv)
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
		rot_down(a, 1);
		pr_count--;
	}
	while (r_count > 0)
	{
		rot_down(b, 2);
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
	while (0 < c)
	{
		if (stacks->b->next->val > stacks->sort->array[p[1]]) // val > 1/4
		{
			p_count += push_with_count(stacks); 
			c--;
		}
		else if (stacks->b->next->val > stacks->sort->array[p[0]]) // val > 1/2
		{
			p_count += push_with_count(stacks);
			pr_count += rot_up_with_count(stacks->a, 1);
			c--;
		}
		else
			r_count += rot_up_with_count(stacks->b, 2);
	}
	replace(stacks, p_count, r_count, pr_count);
}

void sort_stack_b(t_stacks *stacks, size_t l, size_t r)
{
	int		count;
//	size_t	*p;
	size_t p[2];

//	p = NULL;
	p[0] = (l + r) /2;
	p[1] = (p[0] + r) /2;
	count = count_more_than_pivot(stacks->b, stacks->sort->array[p[0]],
			stacks->sort->array[l], stacks->sort->array[r]);
	if (l <= r && r - l <= 9) //where the 9 comes from? 
	{
		push_all_to_a(stacks, l, r); 
		return ;
	}
	divide(stacks, p, count); // 
	sort_stack_b(stacks, p[1] + 1, r); //3/4 + 1 ~ r
	sort_stack_b(stacks, p[0] + 1, p[1]);// 1/2 +1  ~  3/4
	sort_stack_b(stacks, l, p[0]); // l ~ 1/2
}
