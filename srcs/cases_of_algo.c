#include "push_swap.h"

static void	case_two(t_stack *stack)
{
	int	a;
	int	b;

	a = stack->next->val;
	b = stack->next->next->val;
	if (a > b)
		swap(stack, 1);
}

static void	case_three(t_stack *stack)
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

static void	case_four_to_six(t_stack *a, t_stack *b)
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

static int	scan_sort_order(t_stack *a)
{
	a = a->next;
	while (a->next->index != 0)
	{
		if (a->val > a->next->val)
			return (NOT_SORTED);
		a = a->next;
	}
	return (ALREADY_SORTED);
}

int select_algo(t_stack *a, t_stack *b, t_storage *storage)
{
	size_t	size;
	
	size = a->val;
	if (ALREADY_SORTED == scan_sort_order(a))
		return (ALREADY_SORTED);
	if (size == 2)
		case_two(a);
	else if (size == 3)
		case_three(a);
	else if (size <= 6)
		case_four_to_six(a, b);
	else
		sort_stacks(storage, 0, storage->a>val - 1);
	return (CONTINUE);
}

