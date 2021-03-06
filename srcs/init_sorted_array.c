/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorted_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:49 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/17 07:18:10 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_in_sorted_array(int *sort, size_t a, size_t b)
{
	int	tmp;

	tmp = sort[a];
	sort[a] = sort[b];
	sort[b] = tmp;
}

static int	partition(int *sort, int pivot, size_t left, size_t right)
{
	size_t	l;
	size_t	r;

	l = left;
	r = right;
	while (1)
	{
		while (l < right && sort[l] < pivot)
			l++;
		while (left < r && pivot < sort[r])
			r--;
		if (l >= r)
			break ;
		swap_in_sorted_array(sort, l, r);
	}
	if (l == left)
		return (l + 1);
	return (l);
}

static void	quick_sort(int *sort, size_t left, size_t right)
{
	size_t	part;

	if (left >= right)
		return ;
	part = partition(sort, sort[left], left, right);
	quick_sort(sort, left, part - 1);
	quick_sort(sort, part, right);
}

int	*init_sorted_array(t_stack *a, t_storage *storage)
{
	int		*sorted;
	t_stack	*tmp;

	sorted = (int *)malloc(sizeof(int) * a->val);
	if (!sorted)
		free_all_and_exit(storage, INIT_SORTED_ARRAY);
	tmp = a->next;
	while (tmp->index != 0)
	{
		sorted[tmp->index - 1] = tmp->val;
		tmp = tmp->next;
	}
	quick_sort(sorted, 0, a->val - 1);
	return (sorted);
}
