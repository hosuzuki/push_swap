#include "push_swap.h"

static t_stack	*alloc_stack(t_stack *sentinel, size_t i)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		free_stack(sentinel, i);
		shutdown(ALLOC_ERROR);
	}
	return (stack);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*sentinel;
	t_stack *tmp;
	int		i;

	sentinel = (t_stack *)malloc(sizeof(t_stack));
	if(!sentinel)
		exit(SENTINEL_ERROR);
	sentinel->index = 0;
	tmp = sentinel;
	i = 0;
	while (i + 1 < argc)
	{
		tmp->next = alloc_stack(sentinel, i);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		tmp->index = i + 1;
		tmp->next = NULL;
		tmp->val = atoi_and_errcheck(argv[i + 1], sentinel, i + 1);
		i++;
	}
	tmp->next = sentinel;
	sentinel->prev = tmp;
	sentinel->val = i;
	vals_storage(sentinel, NULL, NULL, NULL);
	return (sentinel);
}

void	re_index(t_stack *stack)
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
