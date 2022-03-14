#include "push_swap.h"

static int	count_pivot_or_less(t_stack *stack, int pv, int lv, int rv)
{
	t_stack	*head;
	int		count;

	count = 0;
	head = stack;
	stack = stack->next;
	while (stack != head && lv <= stack->val && stack->val <= rv) // does lv and rv needed?
	{
		if (stack->val <= pv)
			count++;
		stack = stack->next;
	}
	return (count);
}

static void	replace_atob(t_stacks *stacks, int r_count, int first)
{
	while ( r_count > 0 && first == 0)
	{
		rot_down(stacks->b, 2);
		r_count--;
	}
}

static int	push_rot_up(t_stacks *stacks, int r_count)
{
	push(stacks->a, stacks->b, 1);
	rot_up(stacks->b, 2); // why?
	r_count++;
	return (r_count);
}

static void	move_small_number_to_b(t_stacks *stacks, size_t *p, int count, int first)
{
	int	r_count;

	r_count = 0; 
	// count = how many numbers are below pivot
	while (0 < count)
	{
		if (stacks->a->next->val <= stacks->sort->array[p[0]]) //val <=  1/4 part
		{
			if (first == 1)// ???
				r_count = push_rot_up(stacks, r_count);
			else
				push(stacks->a, stacks->b, 1);
			count--;
		}
		else if (stacks->a->next->val <= stacks->sort->array[p[1]]) // val <=1/2
		{
			if (first == 0) // ??
				r_count = push_rot_up(stacks, r_count);
			else
				push(stacks->a, stacks->b, 1);
			count--;
		}
		else if (stacks->a->next->val > stacks->sort->array[p[0]]) //val > 1/4  this have to p[1] or could be just else
			rot_up(stacks->a, 1);
	}
	replace_atob(stacks, r_count, first);//??
}

void	sort_stacks(t_stacks *stacks, size_t l, size_t r, int first)
{
	int		count;
//	size_t	p[2];
	size_t	*p;

	p = NULL;
	if (r - l <= 2)
	{
		if (stacks->a->val == 3)
			case_three(stacks->a);
		else if (stacks->a->val == 2)
			case_two(stacks->a);
		return ;
	}
	p[1] = (l + r) / 2; //1/2
	p[0] = (l + p[1]) / 2; // 1 / 4
	count = count_pivot_or_less(stacks->a, stacks->sort->array[p[1]],
			stacks->sort->array[l], stacks->sort->array[r]);
	move_small_number_to_b(stacks, p, count, first);// move small number to b
	sort_stacks(stacks, p[1] + 1, r, 0); // 1/2 ~ right
	sort_stack_b(stacks, p[0] + 1, p[1]); //1/4 + 1~  1/2
	sort_stack_b(stacks, l, p[0]); // 0 ~ 1/4
}
