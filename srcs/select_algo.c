/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:52 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/17 14:24:41 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_two(t_stack *stack, t_storage *storage)
{
	int	a;
	int	b;

	a = stack->next->val;
	b = stack->next->next->val;
	if (b < a)
		swap(stack, storage);
}

void	case_three(t_stack *stack, t_storage *storage)
{
	int	a;
	int	b;
	int	c;

	a = stack->next->val;
	b = stack->next->next->val;
	c = stack->next->next->next->val;
	if (b < a && a < c)
		swap(stack, storage);
	else if (c < b && b < a)
	{
		swap(stack, storage);
		rot_down(stack, storage);
	}
	else if (b < c && c < a)
		rot_up(stack, storage);
	else if (a < c && c < b)
	{
		swap(stack, storage);
		rot_up(stack, storage);
	}
	else if (c < a && a < b)
		rot_down(stack, storage);
}

static void	case_four_to_six(t_stack *a, t_stack *b, t_storage *storage)
{
	size_t	size;
	size_t	count;

	size = a->val;
	count = 0;
	while (3 < size - count)
	{
		set_min(a, storage);
		push(a, b, storage);
		count++;
	}
	case_three(a, storage);
	while (b->val > 0)
		push(b, a, storage);
}

int	scan_sort_order(t_stack *a)
{
	a = a->next;
	while (a->next->index != 0)
	{
		if (a->val > a->next->val)
			return (NOT_SORTED);
		a = a->next;
	}
	return (ALREADY_SORTED);
}

int	select_algo(t_stack *a, t_stack *b, t_storage *storage)
{
	size_t	size;

	size = a->val;
	if (ALREADY_SORTED == scan_sort_order(a))
		return (ALREADY_SORTED);
	if (size == 2)
		case_two(a, storage);
	else if (size == 3)
		case_three(a, storage);
	else if (size <= 6)
		case_four_to_six(a, b, storage);
	else
		sort_stacks(storage, 0, storage->a->val - 1);
	return (CONTINUE);
}
