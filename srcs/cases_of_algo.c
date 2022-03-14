#include "push_swap.h"

void	case_two(t_stack *stack)
{
	int	a;
	int	b;

	a = stack->next->val;
	b = stack->next->next->val;
	if (a > b)
		swap(stack, 1);
}

void	case_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->next->val;
	b = stack->next->next->val;
	c = stack->next->next->next->val;
	if (b < a && a < c) //case 1
		swap(stack, 1);
	else if (c < b && b < a) //case 2
	{
		swap(stack, 1);
		rot_down(stack, 1);
	}
	else if (b < c && c < a) //case 3
		rot_up(stack, 1);
	else if (a < c && c < b) // case 4
	{
		swap(stack, 1);
		rot_up(stack, 1);
	}
	else if (c < a && a < b) // case 5
		rot_down(stack, 1);
}

void	case_four_to_six(t_stack *stack1, t_stack *stack2)
{
	size_t	size;
	size_t	count;

	size = stack1->val;
	count = 0;
	while (size - count > 3)
	{
		set_min(stack1, 1);
		push(stack1, stack2, 1);
		count++;
	}
	case_three(stack1);
	while (stack2->val > 0)
		push(stack2, stack1, 2);
}

void	case_seven_or_more(t_stack *stack_a, t_stack *stack_b, t_sort *sort)
{
	t_stacks *stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit (1); //has to be fixed
//	vals_storage(NULL, stacks, NULL, NULL);
	stacks->a = stack_a;
	stacks->b = stack_b;
	stacks->sort = sort;
	sort_stacks(stacks, 0, sort->size - 1, 1);
}
