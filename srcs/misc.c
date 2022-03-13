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
