#include "push_swap.h"

static void	renumber_index(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack->next;
	i = 0;
	while (tmp != stack)
	{
		tmp->index = i + 1;
		tmp = tmp->next;
		i++;
	}
	stack->val = i;
}

static t_stack	*locate_max(t_stack *stack)
{
	t_stack	*ret;
	int		max;
//	size_t		max;

	stack = stack->next;
	max = stack->val;
	ret = stack;
	while (stack->index != 0)
	{
		if (stack->val > max)
		{
			max = stack->val;
			ret = stack;
		}
		stack = stack->next;
	}
	return (ret);
}

void	set_max(t_stack *stack, t_storage *storage)
{
	t_stack	*max;
	size_t	size;

	renumber_index(stack);
	max = locate_max(stack);
	size = stack->val;
//	if (max->index - 1 <= (size - max->index + 1))
	if (max->index <= (size / 2))
	{
		while (stack->next != max)
//		{
//			if (max->index == 2)
//				swap(stack, ab);
//			else
				rot_up(stack, storage);
//		}
	}
	else
	{
		while (stack->next != max)
			rot_down(stack, storage);
	}
}

static t_stack	*locate_min(t_stack *stack)
{
	t_stack	*ret;
	int		min;
//	size_t	min;

	stack = stack->next;
	min = stack->val;
	ret = stack;
	while (stack->index != 0)
	{
		if (stack->val < min)
		{
			min = stack->val;
			ret = stack;
		}
		stack = stack->next;
	}
	return (ret);
}

void set_min(t_stack *stack, t_storage *storage)
{
	t_stack	*min;
	size_t	size;
//	size_t	spot;

	renumber_index(stack);
	min = locate_min(stack);
	if (min == stack->next)
		return ;
//	spot = min->index;
	size = stack->val;
//	if (min->index - 1 <= (size - min->index + 1))
	if (min->index <= (size / 2)) 
	{
		while (stack->next != min)
		{
//			if (spot == 2) 
//				swap(stack, ab);
//			else
				rot_up(stack, storage);
		}
	}
	else
	{
		while (stack->next != min)
			rot_down(stack, storage);
	}
}

