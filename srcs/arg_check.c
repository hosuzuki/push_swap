#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	stack = stack->next;
	while (stack->next->index != 0)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

