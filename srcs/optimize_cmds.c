#include "push_swap.h"

static size_t	merge_ra_rb(char *record, size_t i, size_t j)
{
	record[i] = 1;
	record[j] = RR;
	return (-1);
}

static size_t	merge_rra_rrb(char *record, size_t i, size_t j)
{
	record[i] = RRR;
	record[j] = 1;
	return (-1);
}

static size_t	offset(char *record, size_t i, size_t j)
{
	record[i] = 1;
	record[j] = 1;
	return (-1);
}


/*
 static size_t	merge_and_offset(char *record, size_t i, size_t j)
{
	
	if ((record[i] == PB && record[j] == PA)
			|| (record[i] == PA && record[j] == PB))
		i = offset(record, i, j);
	else if ((record[i] == RRB && record[j] == RB)
			|| (record[i] == RB && record[j] == RRB))
		i = offset(record, i, j);
	else if ((record[i] == RRA && record[j] == RA)
			|| (record[i] == RA && record[j] == RRA))
		i = offset(record, i, j);
	else if ((record[i] == RA && record[j] == RB)
			|| (record[i] == RB && record[j] == RA))
		i = merge_ra_rb(record, i, j);
	else if (record[i] == RRA)
	{
		while (record[j] == RRA || record[j] == RRR || record[j] == 1)
			j++;
		if (record[j] == RRB)
			i = merge_rra_rrb(record, i, j);
	}
	return (i);
}
*/
static size_t	merge_and_offset(char *record, size_t i, size_t j)
{
	char	a;
	char	b;

	a = record[i];
	b = record[j];
	if ((a == PB && b == PA) || (a == PA && b == PB))
		i = offset(record, i, j);
	else if ((a == RRB && b == RB) || (a == RB && b == RRB))
		i = offset(record, i, j);
	else if ((a == RRA && b == RA) || (a == RA && b == RRA))
		i = offset(record, i, j);
	else if ((a == RA && b == RB) || (a == RB && b == RA))
		i = merge_ra_rb(record, i, j);
	else if (a == RRA)
	{
		while (record[j] == RRA || record[j] == RRR || record[j] == 1)
			j++;
		if (record[j] == RRB)
			i = merge_rra_rrb(record, i, j);
	}
	return (i);
}

void	optimize_cmds(char *record)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
//	while (record[i] != 0 && record[i] != 1)
//		i++;
// if (record[i] == 0)//???
//		record[i] = 0;
	i = 0;
	while (record[i + 1])
	{
		while (record[i] == 1)
			i++;
		j = i + 1;
		while (record[j] == 1)
			j++;
		if (record[j] == 0)
			break ;
		i = merge_and_offset(record, i, j);
		i++;
		if (!record[i])
			break ;
	}
}
