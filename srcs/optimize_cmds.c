/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/16 21:26:51 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static size_t	merge_ra_rb(char *cmds, size_t i, size_t j)
{
	cmds[i] = OFF;
	cmds[j] = RR;
}

static size_t	merge_rra_rrb(char *cmds, size_t i, size_t j)
{
	cmds[i] = OFF;
	cmds[j] = RRR;
}
*/

static void	offset(char *cmds, size_t i, size_t j)
{
	cmds[i] = OFF;
	cmds[j] = OFF;
}

static void	offset_and_merge(char *cmds, size_t i, size_t j)
{
	char	a;
	char	b;

	a = cmds[i];
	b = cmds[j];
	if ((a == PB && b == PA) || (a == PA && b == PB))
		offset(cmds, i, j);
	else if ((a == RRA && b == RA) || (a == RA && b == RRA))
		offset(cmds, i, j);
	else if ((a == RRB && b == RB) || (a == RB && b == RRB))
		offset(cmds, i, j);
	else
		merge_cmds(cmds, i, j);
}

void	optimize_cmds(char *cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i + 1])
	{
		offset_and_merge(cmds, i, i + 1);
		i++;
	}
}

/*
void	optimize_cmds(char *cmds)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (cmds[i + 1])
	{
		while (cmds[i] == 1)
			i++;
		j = i + 1;
		while (cmds[j] == 1)
			j++;
		if (cmds[j] == 0)
			break ;
		i = merge_and_offset(cmds, i, j);
		i++;
		if (!cmds[i])
			break ;
	}
}
*/
