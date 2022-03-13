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

static void	free_stackab(t_stack *stack1, t_stack *stack2)
{
	if (stack1)
		free_stack(stack1, stack1->val);
	if (stack2)
		free_stack(stack2, stack2->val);
}

void	free_all(t_stack *stack1, t_stack *stack2, t_sort *sort, char *record)
{
	free(record);
	if (sort)
	{
		free(sort->array);
		free(sort);
	}
	free_stackab(stack1, stack2);
}

