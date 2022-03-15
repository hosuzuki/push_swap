#include "push_swap.h"

void	case_two(t_stack *stack)
{
	int	a;
	int	b;

	a = stack->next->val;
	b = stack->next->next->val;
	if (a > b)
		swap(stack, 1);
}

void	case_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->next->val;
	b = stack->next->next->val;
	c = stack->next->next->next->val;
	if (b < a && a < c)
		swap(stack, 1);
	else if (c < b && b < a)
	{
		swap(stack, 1);
		rot_down(stack, 1);
	}
	else if (b < c && c < a)
		rot_up(stack, 1);
	else if (a < c && c < b)
	{
		swap(stack, 1);
		rot_up(stack, 1);
	}
	else if (c < a && a < b)
		rot_down(stack, 1);
}

void	case_four_to_six(t_stack *a, t_stack *b)
{
	size_t	size;
	size_t	count;

	size = a->val;
	count = 0;
	while (size - count > 3)
	{
		set_min(a, 1);
		push(a, b, 1);
		count++;
	}
	case_three(a);
	while (b->val > 0)
		push(b, a, 2);
}
