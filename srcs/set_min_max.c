/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:52 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/17 12:17:18 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	renumber_index(t_stack *stack)
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

/*
static t_stack	*locate_max(t_stack *stack)
{
	t_stack	*ret;
	int		max;

	stack = stack->next;
	max = stack->val;
	ret = stack;
	while (stack->index != 0)
	{
		if (stack->val > max)
		{
			max = stack->val;
			ret = stack;
		}
		stack = stack->next;
	}
	return (ret);
}
*/

/*
void	set_max(t_stack *stack, t_storage *storage)
{
	t_stack	*max;
	size_t	size;

	renumber_index(stack);
	max = locate_max(stack);
	size = stack->val;
	if (max->index <= (size / 2))
	{
		while (stack->next != max)
			rot_up(stack, storage);
	}
	else
	{
		while (stack->next != max)
			rot_down(stack, storage);
	}
}
*/

int	set_max(t_stack *stack, int count, t_storage *storage)
{
	t_stack	*tmp;
	t_stack	*max;
	int			max_val;
	int			r;

	tmp = stack->next;
	max = tmp;
	max_val = tmp->val;
	r = 0;
	while (0 < count)
	{
		if (max_val < tmp->val)
		{
			max_val = tmp->val;
			max = tmp;
		}
		tmp = tmp->next;
		count--;
	}
	while (stack->next != max)
		r += rot_up(stack, storage);
	return (r);
}

static t_stack	*locate_min(t_stack *stack)
{
	t_stack	*ret;
	int		min;

	stack = stack->next;
	min = stack->val;
	ret = stack;
	while (stack->index != 0)
	{
		if (stack->val < min)
		{
			min = stack->val;
			ret = stack;
		}
		stack = stack->next;
	}
	return (ret);
}

void	set_min(t_stack *stack, t_storage *storage)
{
	t_stack	*min;
	size_t	size;

	renumber_index(stack);
	min = locate_min(stack);
	if (min == stack->next)
		return ;
	size = stack->val;
	if (min->index <= (size / 2))
	{
		while (stack->next != min)
			rot_up(stack, storage);
	}
	else
	{
		while (stack->next != min)
			rot_down(stack, storage);
	}
}
