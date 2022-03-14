#include "push_swap.h"

/*static void	print_a_cmd(char c)
{
	if (c == 2)
		write(1, "sa\n", 3);
	else if (c == 3)
		write(1, "sb\n", 3);
	else if (c == 4)
		write(1, "pb\n", 3);
	else if (c == 5)
		write(1, "pa\n", 3);
	else if (c == 6)
		write(1, "rra\n", 4);
	else if (c == 7)
		write(1, "rrb\n", 4);
	else if (c == 8)
		write(1, "ra\n", 3);
	else if (c == 9)
		write(1, "rb\n", 3);
	else if (c == 10)
		write(1, "rr\n", 3);
	else if (c == 11)
		write(1, "rrr\n", 4);
}

*/
static void	print_a_cmd(char c)
{
	if (c == SA)
		write(1, "sa\n", 3);
	else if (c == SB)
		write(1, "sb\n", 3);
	else if (c == SS) // added
		write(1, "ss\n", 3);
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

void	print_cmds(char *record)
{
	size_t	i;

	i = 0;
//	optimize_cmds(record);
	while (record[i])
	{
		while (record[i] == 1)
			i++;
		if (!record[i])
			break ;
		print_a_cmd(record[i]);
		i++;
	}
//	vals_storage(NULL, NULL, NULL, NULL);
}
