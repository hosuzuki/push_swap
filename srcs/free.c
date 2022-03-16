/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:48 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/16 21:26:48 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = stack;
	stack = stack->next;
	while (stack != head)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	free (head);
}

void	free_all(t_storage *storage)
{
	if (storage->a)
		free_stack(storage->a);
	if (storage->b)
		free_stack(storage->b);
	if (storage->sorted)
		free (storage->sorted);
	if (storage->cmds)
		free (storage->cmds);
	if (storage)
		free (storage);
}

void	free_all_and_exit(t_storage *storage, enum e_error_handling status)
{
	free_all(storage);
	exit (status);
}
