#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	stack = stack->next;
	while (stack->next->index != 0)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_digit_str(int sum, char *argv[])
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (i < sum)
	{
		j = 0;
		str = argv[i];
//		if (str[0] == '\0')
//			return (0);
		if (str[0] == '-' && str[1] != '\0')
			j++;
		while (str[j])
		{
			if (!ft_isdigit(str[j++]))
				return (0);
//			if (str[j])'
		//	j++;
		}
		i++;
	}
	return (1);
}

int	is_unique(t_stack *stack)
{
	t_stack *tmp;

	stack = stack->next;
	while (stack->next->index != 0)
	{
		tmp = stack->next;
		while (tmp->index != 0)
		{
			if (stack->val == tmp->val)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

int atoi_and_errcheck(char *str, t_stack *stack, size_t count)
{
	int		sign;
	long long ans;
	size_t i;

	i = 0;
	ans = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]))
	{
		if ((sign == 1 && ans > (INT_MAX - (str[i] - '0')) / 10) // we can just use INT_MAX  ???
				|| (sign == -1 && (-1 * ans) < (INT_MIN + (str[i] - '0')) / 10))
		{
			write(2, "Error\n", 6);
			free_stack(stack, count);
 			exit(INVALID_INPUT);
		}
		ans = ans * 10 + (str[i++] - '0');
	}
	return ((int)(ans *sign));
}
