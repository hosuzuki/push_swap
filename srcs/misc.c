


static void	print_command(char c)
{
	if (c == 2)
		write(1, "sa\n", 3);
	else if (c == 3)
		write(1, "sb\n", 3);
	else if (c == 4)
		write(1, "pb\n", 3);
	else if (c == 5)
		write(1, "pa\n", 3);
	else if (c == 6)
		write(1, "rra\n", 4);
	else if (c == 7)
		write(1, "rrb\n", 4);
	else if (c == 8)
		write(1, "ra\n", 3);
	else if (c == 9)
		write(1, "rb\n", 3);
	else if (c == 10)
		write(1, "rr\n", 3);
	else if (c == 11)
		write(1, "rrr\n", 4);
}

	void	player(char *record)
{
	size_t	i;

	i = 0;
	optimizer(record);
	while (record[i])
	{
		while (record[i] == 1)
			i++;
		if (!record[i])
			break ;
		print_command(record[i]);
		i++;
	}
	vals_storage(NULL, NULL, NULL, NULL);
}

void	re_index(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack->next;
	i = 0;
	while (tmp != stack)
	{
		tmp->index = i + 1;
		tmp = tmp->next;
		i++;
	}
	stack->val = i;
}
