/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/17 08:11:30 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_rra_rrb(char *cmds, size_t i, size_t j)
{
	cmds[i] = OFF;
	cmds[j] = RRR;
}

static void	merge_ra_rb(char *cmds, size_t i, size_t j)
{
	cmds[i] = OFF;
	cmds[j] = RR;
}

static void	merge_cmds(char *cmds, size_t i, size_t j)
{
	if ((cmds[i] == RA && cmds[j] == RB)
		|| (cmds[i] == RB && cmds[j] == RA))
		merge_ra_rb(cmds, i, j);
	else if (cmds[i] == RRA)
	{
		while (cmds[j] == RRA || cmds[j] == RRR)
			j++;
		if (cmds[j] == RRB)
			merge_rra_rrb(cmds, i, j);
	}
	else if (cmds[i] == RRB)
	{
		while (cmds[j] == RRB || cmds[j] == RRR)
			j++;
		if (cmds[j] == RRA)
			merge_rra_rrb(cmds, i, j);
	}
}

static void	offset(char *cmds, size_t i, size_t j)
{
	cmds[i] = OFF;
	cmds[j] = OFF;
}

void	optimize_cmds(char *cmds)
{
	size_t	i;
	char		a;
	char		b;

	i = 0;
	a = cmds[i];
	b = cmds[i + 1];
	while (cmds[i + 1])
	{
		if ((a == PB && b == PA) || (a == PA && b == PB))
			offset(cmds, i, i + 1);
		else if ((a == RRA && b == RA) || (a == RA && b == RRA))
			offset(cmds, i, i + 1);
		else if ((a == RRB && b == RB) || (a == RB && b == RRB))
			offset(cmds, i, i + 1);
		else
			merge_cmds(cmds, i, i + 1);
		i++;
	}
}
