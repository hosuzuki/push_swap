/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:50 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/16 21:26:50 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, t_storage *storage)
{
	t_stack	*head;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (stack->val < 2)
		return ;
	head = stack;
	tmp1 = head->next;
	tmp2 = head->next->next;
	tmp1->prev->next = tmp2;
	tmp2->next->prev = tmp1;
	tmp1->next = tmp2->next;
	tmp2->prev = tmp1->prev;
	tmp1->prev = tmp2;
	tmp2->next = tmp1;
	record_one_cmd(SA, SB, stack, storage);
}

int	push(t_stack *stack1, t_stack *stack2, t_storage *storage)
{
	t_stack	*head1;
	t_stack	*head2;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (stack1->val < 1)
		return (0);
	head1 = stack1;
	tmp1 = stack1->next;
	head1->next = tmp1->next;
	tmp1->next->prev = head1;
	head2 = stack2;
	tmp2 = stack2->next;
	tmp1->prev = head2;
	tmp1->next = tmp2;
	head2->next = tmp1;
	tmp2->prev = tmp1;
	head1->val--;
	head2->val++;
	record_one_cmd(PB, PA, stack1, storage);
	return (1);
}

int	rot_up(t_stack *stack, t_storage *storage)
{
	t_stack	*head;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (stack->val < 2)
		return (0);
	head = stack;
	tmp1 = head->next;
	tmp2 = head->prev;
	head->next = tmp1->next;
	head->prev = tmp1;
	tmp1->next->prev = head;
	tmp1->prev = tmp2;
	tmp1->next = head;
	tmp2->next = tmp1;
	record_one_cmd(RA, RB, stack, storage);
	return (1);
}

void	rot_down(t_stack *stack, t_storage *storage)
{
	t_stack	*head;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (stack->val < 2)
		return ;
	head = stack;
	tmp1 = head->next;
	tmp2 = head->prev;
	head->prev = tmp2->prev;
	head->next = tmp2;
	tmp1->prev = tmp2;
	tmp2->prev->next = head;
	tmp2->prev = head;
	tmp2->next = tmp1;
	record_one_cmd(RRA, RRB, stack, storage);
}
