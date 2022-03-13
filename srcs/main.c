#include "push_swap.h"

/*
 * static void	case_gt_six(t_stack *stack_a, t_stack *stack_b, t_sort *sort)
{
	t_stacks *stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		shutdown(CASE_GT);
	vals_storage(NULL, stacks, NULL, NULL);
	stacks->a = stack_a;
	stacks->b = stack_b;
	stacks->sort = sort;
	atob(stacks, 0, sort->size - 1, 1);
}
*/

int	is_sorted(t_stack *stack)
{
	stack = stack->next;
	while (stack->next->index != 0)
	{
		if (stack->val > stack->next->val)
			return (NOT_SORTED);
		stack = stack->next;
	}
	return (SORTED);
}

static int pick_algo(t_stack *stack_a, t_stack *stack_b, t_sort *sort)
{
	size_t	size;
	
	size = stack_a->val;
	if (SORTED == is_sorted(stack_a))
		return (SORTED);
	if (size == 2)
		case_two(stack_a);
/*	else if (size == 3)
		case_three(stack_a);
	else if (size <= 6)
		case_four_to_six(stack_a, stack_b);
	else
		case_from_seven(stack_a, stack_b, sort);
*/
	(void)stack_b; //delete
	(void)sort; //delete
	return (CONTINUE);
}


# include <stdio.h> // this have be away

static void print_argv(t_stack *stack_a, int argc, char **argv) // has to be deleted
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


int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_sort	*sort;
	char	**record;
	
	if (argc < 2)
		return (0);
	stack_a = validate_number(argc - 1, argv + 1);
	print_argv(stack_a, argc, argv); //has to be deleted
	sort = pre_sort(stack_a);
	print_sort(argc, sort); // has to be deleted
	record = record_array(stack_a->val * 20, stack_a, sort);
	stack_b = init_stack(0, NULL);
	if (SORTED == pick_algo(stack_a, stack_b, sort))
	{
		free_all(stack_a, stack_b, sort, *record); // check rec
		return (0); // check does this end correct??
	}
	print_stack(stack_a, stack_b); // has to be deleted.
/*
	player(*record);
*/
	free_all(stack_a, stack_b, sort, *record);
	//	free_stack(stack_a, argc - 1);
//	free_stack(stack_b, 0);

	return (0);
}
