#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_sort	*sort;
	char	**record;
	
	if (args < 2)
		return (0);
	if (!is_digit_str(argc - 1, argv + 1))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_a = init_stack(args, argv);
	stack_b = init_stack(0, NULL);
	if (!stack_a || !stack_b)
		shutdown();
	sort = pre_sort(stack_a);
	record = record_array(stack_a->val * 12);
	if (!is_unique(stack_a))
		error_exit();
	
	return (0);
}
