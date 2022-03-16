/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two_at_once.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/16 21:26:51 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b, t_storage *storage)
{
	swap(a, storage);
	swap(b, storage);
}

void	rr(t_stack *a, t_stack *b, t_storage *storage)
{
	rot_up(a, storage);
	rot_up(b, storage);
}

void	rrr(t_stack *a, t_stack *b, t_storage *storage)
{
	rot_down(a, storage);
	rot_down(b, storage);
}
