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

static void size_branch(t_stack *stack_a, t_stack *stack_b, t_sort *sort)
{
	size_t	size;
	
	size = stack_a->val;
	if (is_sorted(stack_a))
		return ;
	if (size == 2)
		case_two(stack_a);
	else if (size == 3)
		case_three(stack_a);
	else if (size <= 6)
		case_ngt_six(stack_a, stack_b);
	else
		case_gt_six(stack_a, stack_b, sort);
}

*/

# include <stdio.h> // this have be away

int main(int argc, char **argv) // hve to be much simpler/ get argv /sort/print command/
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_sort	*sort;
	char	**record;
	
	if (argc < 2)
		return (0);
	stack_a = validate_number(argc - 1, argv + 1);
	
	t_stack	*tmp = stack_a;
	printf("argv: ");
	for (int i = 0; i < argc - 1 ; i++)
	{
		tmp = tmp->next;
		printf(" %d", tmp->val);
//		printf("[%d]: %d\n", i + 1, tmp->val);
	}
	printf("\n");



	sort = pre_sort(stack_a);

	for (int i = 0; i < argc - 1 ; i++)
		printf("[%d]: %d\n", i + 1, sort->array[i]);
	


	stack_b = init_stack(0, NULL);

	


	record = record_array(stack_a->val * 20, stack_a, sort);
/*
 * if (!sort || !record || is_sorted(stack_a))
		shutdown(MAIN_SORT_ERROR);
	size_branch(stack_a, stack_b, sort);
	player(*record);
*/
	free_all(stack_a, stack_b, sort, NULL);
	//	free_stack(stack_a, argc - 1);
//	free_stack(stack_b, 0);

	return (0);
}
