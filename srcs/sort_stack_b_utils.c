#include "push_swap.h"

int	push_with_count(t_stacks *stacks)
{
	push(stacks->b, stacks->a, 2);
	return (1);
}

int rot_up_with_count(t_stack *stack, int ab)
{
	rot_up(stack, ab);
	return (1);
}

void	push_all_to_a(t_stacks *stacks, size_t l, size_t r)
{
	int i;

	i = r - l + 1;
	while (0 < i)
	{
		set_max(stacks->b, 2);
		push(stacks->b, stacks->a, 2);
		i--;
	}
	return ;
}
