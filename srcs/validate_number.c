#include "push_swap.h"

static int	no_dupulicate(t_stack *stack_a)
{
	t_stack *tmp;

	stack_a = stack_a->next;
	while (stack_a->next->index != 0)
	{
		tmp = stack_a->next;
		while (tmp->index != 0)
		{
			if (stack_a->val == tmp->val)
				return (ERROR);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (CONTINUE);
}

static void	str_is_all_digit(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	while (j < argc)
	{
		i = 0;
		str = argv[j];
		if (str[0] == '\0') // does this really happen?
			exit (STR_IS_ALL1);
		if (str[0] == '-' && str[1] != '\0')
			i++;
		while (str[i])
		{
			if (!ft_isdigit(str[i++]))
				exit (STR_IS_ALL2);
//			if (argv[i])
//				i++;
		}
		j++;
	}
//	return (1);
}

t_stack	*validate_number(int argc, char **argv)
{
	t_stack	*stack_a;
	
	str_is_all_digit(argc, argv);
	stack_a = init_stack(argc, argv);
	if (ERROR == no_dupulicate(stack_a))
	{
		free_stack(stack_a, argc);
		exit_with_number(NO_DUPLICATE);
	}
	return (stack_a);
}
