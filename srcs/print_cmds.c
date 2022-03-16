/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/17 07:59:48 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_a_cmd(char c)
{
	if (c == SA)
		write(1, "sa\n", 3);
	else if (c == SB)
		write(1, "sb\n", 3);
	else if (c == PB)
		write(1, "pb\n", 3);
	else if (c == PA)
		write(1, "pa\n", 3);
	else if (c == RA)
		write(1, "ra\n", 3);
	else if (c == RB)
		write(1, "rb\n", 3);
	else if (c == RR)
		write(1, "rr\n", 3);
	else if (c == RRA)
		write(1, "rra\n", 4);
	else if (c == RRB)
		write(1, "rrb\n", 4);
	else if (c == RRR)
		write(1, "rrr\n", 4);
}

void	print_cmds(char *cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i])
	{
		while (cmds[i] == OFF)
			i++;
		if (!cmds[i])
			break ;
		print_a_cmd(cmds[i]);
		i++;
	}
}
