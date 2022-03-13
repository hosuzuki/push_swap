#include "push_swap.h"

static int	int_range(char c, int sign, long long res)
{
	if (sign == 1 && res > (INT_MAX - (c - '0')) / 10) // need to check how it works.
		return (ERROR);
	else if(sign == -1 && (-1 * res) < (INT_MIN + (c - '0')) / 10)
		return (ERROR);
	return (CONTINUE);
}

static int	atoi_with_error_handle(char *str, t_stack *stack, size_t count)
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
		if (ERROR == int_range(str[i], sign, res))
		{
			free_stack(stack, count);
			print_error_and_exit(ATOI_WITH);
		}
		res = res * 10 + (str[i++] - '0');
	}
	return ((int)(res * sign));
}

static t_stack	*alloc_stack(t_stack *head, size_t i)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		if (head != NULL)
			free_stack(head, i);
		exit_with_number(ALLOC_STACK);
	}
	return (stack);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*head;
	t_stack *tmp;
	int		i;

	head = alloc_stack(NULL, 0);
	//	head = (t_stack *)malloc(sizeof(t_stack));
//	if(!head)
//		exit(INIT_STACK);
	head->index = 0;
	tmp = head;
	i = 0;
	while (i < argc)
	{
		tmp->next = alloc_stack(head, i);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		tmp->index = i + 1;
		tmp->next = NULL;
//		tmp->val = atoi_and_errcheck(argv[i + 1], head, i + 1);
//		tmp->val = atoi_and_errcheck(argv[i], head, i);
		tmp->val = atoi_with_error_handle(argv[i], head, i + 1);
		i++;
	}
	tmp->next = head;
	head->prev = tmp;
	head->val = i;
//	vals_storage(head, NULL, NULL, NULL); //this have to be activated
	return (head);
}
