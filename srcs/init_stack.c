#include "push_swap.h"

static int	int_range(int sign, long long res, char n)
{
	if (sign == 1 && (long long)INT_MAX < res * 10 + n)
		return (ERROR);
	else if(sign == -1 && (long long)INT_MIN > (-1 * res) * 10 - n)
		return (ERROR);
	return (CONTINUE);
}

static int	atoi_ps(char *str, t_stack *head, t_storage *storage)
{
	size_t		i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]))
	{
		if (ERROR == int_range(sign, res, str[i] - '0'))
		{
			write(1, "Error\n", 6);
			free_stack (head);
			free_all_and_exit(storage, ATOI_PS);
		}
		res = res * 10 + (str[i++] - '0');
	}
	return ((int)(res * sign));
}

static t_stack	*alloc_stack(t_stack *head, t_storage *storage)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		if (head != NULL)
			free_stack (head);
		free_all_and_exit(storage, ALLOC_STACK);
	}
	return (stack);
}

t_stack	*init_stack(int argc, char **argv, t_storage *storage)
{
	t_stack	*head;
	t_stack *tmp;
	int		i;

	head = alloc_stack(NULL, storage);
	head->index = 0;
	tmp = head;
	i = 0;
	while (i < argc)
	{
		tmp->next = alloc_stack(head, storage);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		tmp->index = (size_t)(i + 1);
		tmp->next = NULL;
		tmp->val = atoi_ps(argv[i], head, storage);
		i++;
	}
	tmp->next = head;
	head->prev = tmp;
	head->val = i;
	return (head);
}
