#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	stack = stack->next;
	while (stack->next->index != 0)
	{
		if (stack->val > stack->next->val)
			return (NOT_SORTED);
		stack = stack->next;
	}
	return (ALREADY_SORTED);
}

static int pick_algo_and_sort(t_stack *stack_a, t_stack *stack_b, t_sort *sort)
{
	size_t	size;
	
	size = stack_a->val;
	if (ALREADY_SORTED == is_sorted(stack_a))
		return (ALREADY_SORTED);
	if (size == 2)
		case_two(stack_a);
	else if (size == 3)
		case_three(stack_a);
	else if (size <= 6)
		case_four_to_six(stack_a, stack_b);
	else
		case_seven_or_more(stack_a, stack_b, sort);
//	(void)stack_b; //delete
//	(void)sort; //delete
	return (CONTINUE);
}

/*
# include <stdio.h> // this have be away

static void print_argv(t_stack *stack_a, int argc) // has to be deleted
{
	t_stack	*tmp = stack_a;
	printf("argv: ");
	for (int i = 0; i < argc - 1 ; i++)
	{
		tmp = tmp->next;
		printf(" %d", tmp->val);
//		printf("[%d]: %d\n", i + 1, tmp->val);
	}
	printf("\n");
}

static void print_sort(int argc, t_sort *sort)
{
	printf("sort\n");
	for (int i = 0; i < argc - 1 ; i++)
		printf("[%d]: %d\n", i + 1, sort->array[i]);
}

static void print_stack(t_stack *stack_a, t_stack *stack_b)
{
	printf("stack_a\n");
	int sum = stack_a->val;
	for (int i = 0; i < sum; i++)
	{
		stack_a = stack_a->next;
		printf("%d ", stack_a->val);
	}
	printf("\nstack_b\n");
	sum = stack_b->val;
	for (int i = 0; i < sum; i++)
	{
		stack_b = stack_b->next;
		printf("%d ", stack_b->val);
	}
}
*/

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_sort	*sort;
	char	**record;
	
	if (argc < 2)
		return (0);
	stack_a = validate_argv(argc - 1, argv + 1);
//	print_argv(stack_a, argc); //has to be deleted
	sort = pre_sort(stack_a);
//	print_sort(argc, sort); // has to be deleted
	record = record_array(stack_a->val * 20, stack_a, sort);
	stack_b = init_stack(0, NULL);
	if (ALREADY_SORTED == pick_algo_and_sort(stack_a, stack_b, sort))
	{
		free_all(stack_a, stack_b, sort, *record); // check rec
		return (0); // check does this end correct??
	}
//	print_stack(stack_a, stack_b); // has to be deleted.
	optimize_cmds(*record);
	print_cmds(*record);
//	player(*record);
	
	free_all(stack_a, stack_b, sort, *record);
	//	free_stack(stack_a, argc - 1);
//	free_stack(stack_b, 0);

	return (0);
}
