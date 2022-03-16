/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:53 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/16 22:04:04 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_b(t_storage *storage, int r_count)
{
	while (0 < r_count && storage->first_flag == OFF)
	{
		rot_down(storage->b, storage);
		r_count--;
	}
}

static int	push_and_rot_up_b(t_storage *storage)
{
	push(storage->a, storage->b, storage);
	rot_up(storage->b, storage);
	return (1);
}

static void	push_small_to_b(t_storage *storage, size_t x, size_t y, int count)
{
	int	r_count;

	r_count = 0;
	while (0 < count)
	{
		if (storage->a->next->val <= storage->sorted[x])
		{
			if (storage->first_flag == ON)
				r_count += push_and_rot_up_b(storage);
			else
				push(storage->a, storage->b, storage);
			count--;
		}
		else if (storage->a->next->val <= storage->sorted[y])
		{
			if (storage->first_flag == OFF)
				r_count += push_and_rot_up_b(storage);
			else
				push(storage->a, storage->b, storage);
			count--;
		}
		else
			rot_up(storage->a, storage);
	}
	reverse_rotate_b(storage, r_count);
}

static int	count_pivot_or_less(t_stack *a, int pivot)
{
	t_stack	*head;
	int		count;

	count = 0;
	head = a;
	a = a->next;
	while (a != head)
	{
		if (a->val <= pivot)
			count++;
		a = a->next;
	}
	return (count);
}

void	sort_stacks(t_storage *storage, size_t l, size_t r)
{
	int		count;
	size_t	x;
	size_t	y;

	if (r - l <= 2)
	{
		if (storage->a->val == 3)
			case_three(storage->a, storage);
		else if (storage->a->val == 2)
			case_two(storage->a, storage);
		return ;
	}
	y = (l + r) / 2;
	x = (l + y) / 2;
	count = count_pivot_or_less(storage->a, storage->sorted[y]);
	push_small_to_b(storage, x, y, count);
	storage->first_flag = OFF;
	sort_stacks(storage, y + 1, r);
	sort_stack_b(storage, x + 1, y);
	sort_stack_b(storage, l, x);
}
