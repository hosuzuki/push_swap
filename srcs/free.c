#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = stack;
	stack = stack->next;
	while (stack != head)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	free (head);
}


void	free_all_and_exit(t_storage *storage, enum error_handling status)
{
	if (storage->a)
		free_stack(storage->a);
	if (storage->b)
		free_stack(storage->b);
	if (storage->sorted)
		free (storage->sorted);
	if (storage->cmds)
		free (storage->cmds);
	free (storage);
	exit (status);
}
