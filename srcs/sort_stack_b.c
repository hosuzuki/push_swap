/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:53 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/16 21:46:30 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	push_back_to_b(t_storage *storage, int p, int ra, int rb)
{
	while (ra > 0)
	{
		rot_down(storage->a, storage);
		ra--;
	}
	while (rb > 0)
	{
		rot_down(storage->b, storage);
		rb--;
	}
	while (p > 0)
	{
		push(storage->a, storage->b, storage);
		p--;
	}
}

static void	push_back_to_a(t_storage *storage, size_t x, size_t y, int count)
{
	int		p_count;
	int		ra_count;
	int		rb_count;

	p_count = 0;
	ra_count = 0;
	rb_count = 0;
	while (0 < count)
	{
		if (storage->b->next->val > storage->sorted[y])
		{
			p_count += push(storage->b, storage->a, storage);
			count--;
		}
		else if (storage->b->next->val > storage->sorted[x])
		{
			p_count += push(storage->b, storage->a, storage);
			ra_count += rot_up(storage->a, storage);
			count--;
		}
		else
			rb_count += rot_up(storage->b, storage);
	}
	push_back_to_b(storage, p_count, ra_count, rb_count);
}

static int	count_more_than_pivot(t_stack *b, int pv)
{
	t_stack	*head;
	int		count;

	count = 0;
	head = b;
	b = b->next;
	while (b != head)
	{
		if (b->val > pv)
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
	push_back_to_a(storage, x, y, count);
	sort_stack_b(storage, y + 1, r);
	sort_stack_b(storage, x + 1, y);
	sort_stack_b(storage, l, x);
}
