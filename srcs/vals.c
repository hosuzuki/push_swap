#include "push_swap.h"

void	free_stack(t_stack *stack, int count)
{
	t_stack	*heap;
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
