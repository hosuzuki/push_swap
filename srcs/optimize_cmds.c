#include "push_swap.h"

static size_t	merge_ra_rb(char *cmds, size_t i, size_t j)
{
	cmds[i] = 1;
	cmds[j] = RR;
	return (-1);
}

static size_t	merge_rra_rrb(char *cmds, size_t i, size_t j)
{
	cmds[i] = RRR;
	cmds[j] = 1;
	return (-1);
}

static size_t	offset(char *cmds, size_t i, size_t j)
{
	cmds[i] = 1;
	cmds[j] = 1;
	return (-1);
}

static size_t	merge_and_offset(char *cmds, size_t i, size_t j)
{
	char	a;
	char	b;

	a = cmds[i];
	b = cmds[j];
	if ((a == PB && b == PA) || (a == PA && b == PB))
		i = offset(cmds, i, j);
	else if ((a == RRB && b == RB) || (a == RB && b == RRB))
		i = offset(cmds, i, j);
	else if ((a == RRA && b == RA) || (a == RA && b == RRA))
		i = offset(cmds, i, j);
	else if ((a == RA && b == RB) || (a == RB && b == RA))
		i = merge_ra_rb(cmds, i, j);
	else if (a == RRA)
	{
		while (cmds[j] == RRA || cmds[j] == RRR || cmds[j] == 1)
			j++;
		if (cmds[j] == RRB)
			i = merge_rra_rrb(cmds, i, j);
	}
	return (i);
}

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
