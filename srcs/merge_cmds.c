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

static void	merge_sa_sb(char *cmds, size_t i, size_t j)
{
	cmds[i] = OFF;
	cmds[j] = SS;
}

void	merge_cmds(char *cmds, size_t i, size_t j)
{
	if ((cmds[i] == SA && cmds[j] == SB) || (cmds[i] == SB && cmds[j] == SA))
		merge_sa_sb(cmds, i, j);
	else if (cmds[i] == RA)
	{
		while (cmds[j] == RA || cmds[j] == RR)
			j++;
		if (cmds[j] == RB)
			merge_ra_rb(cmds, i, j);
	}
	else if (cmds[i] == RB)
	{
		while (cmds[j] == RB || cmds[j] == RR)
			j++;
		if (cmds[j] == RA)
			merge_ra_rb(cmds, i, j);
	}
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
