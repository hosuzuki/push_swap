/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:53 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/17 11:57:37 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	push_all_to_a(t_storage *storage, size_t l, size_t r)
{
	int	count;

	count = r - l + 1;
	while (0 < count)
	{
		set_max(storage->b, storage);
		push(storage->b, storage->a, storage);
		count--;
	}
	return ;
}
*/

static void	push_all_to_a(t_storage *storage, size_t l, size_t r)
{
	int	count;
	int r_count;

	count = r - l + 1;
	while (0 < count)
	{
		r_count = set_max(storage->b, count, storage);
		push(storage->b, storage->a, storage);
		reverse_rotate_b(storage, r_count);
		count--;
	}
	return ;
}

static void	back_to_b_top(t_storage *storage, int p, int ra, int rb)
{
	while (0 < ra)
	{
		rot_down(storage->a, storage);
		ra--;
	}
	while (0 < rb)
	{
		rot_down(storage->b, storage);
		rb--;
	}
	while (0 < p)
	{
		push(storage->a, storage->b, storage);
		p--;
	}
}

static void	split_into_three(t_storage *storage, size_t x, size_t y, int count)
{
	int		p;
	int		ra;
	int		rb;

	p = 0;
	ra = 0;
	rb = 0;
	while (0 < count)
	{
		if (storage->b->next->val > storage->sorted[y])
		{
			p += push(storage->b, storage->a, storage);
			count--;
		}
		else if (storage->b->next->val > storage->sorted[x])
		{
			p += push(storage->b, storage->a, storage);
			ra += rot_up(storage->a, storage);
			count--;
		}
		else
			rb += rot_up(storage->b, storage);
	}
	back_to_b_top(storage, p, ra, rb);
}

static int	count_more_than_pivot(t_stack *b, int pivot)
{
	t_stack	*head;
	int		count;

	count = 0;
	head = b;
	b = b->next;
	while (b != head)
	{
		if (b->val > pivot)
			count++;
		b = b->next;
	}
	return (count);
}

void	sort_stack_b(t_storage *storage, size_t l, size_t r)
{
	int		count;
	size_t	x;
	size_t	y;

	x = (l + r) / 2;
	y = (x + r) / 2;
	count = count_more_than_pivot(storage->b, storage->sorted[x]);
	if (l <= r && r - l <= 25)
	{
		push_all_to_a(storage, l, r);
		return ;
	}
	split_into_three(storage, x, y, count);
	sort_stack_b(storage, y + 1, r);
	sort_stack_b(storage, x + 1, y);
	sort_stack_b(storage, l, x);
}
