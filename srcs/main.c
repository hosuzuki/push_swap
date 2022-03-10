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

	return (0);
}
