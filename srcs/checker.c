/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:48 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/17 07:26:12 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	execute_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		swap(a, NULL);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		swap(b, NULL);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ss(a, b, NULL);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		push(b, a, NULL);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		push(a, b, NULL);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		rot_up(a, NULL);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rot_up(b, NULL);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rr(a, b, NULL);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		rot_down(a, NULL);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		rot_down(b, NULL);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		rrr(a, b, NULL);
	else
		return (ERROR);
	return (CONTINUE);
}

static void	print_result(t_stack *a, t_stack *b, int error_flag)
{
	if (error_flag == ON)
		write(1, "Error\n", 6);
	else if (scan_sort_order(a) == ALREADY_SORTED && b->val == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static void	receive_cmds(t_stack *a, t_stack *b)
{
	char	*cmd;
	int		error_flag;

	error_flag = OFF;
	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		if (ERROR == execute_cmd(a, b, cmd))
		{
			error_flag = ON;
			free (cmd);
			break ;
		}
		free (cmd);
	}
	print_result(a, b, error_flag);
}

static t_storage	*init_storage(void)
{
	t_storage	*storage;
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*sorted;
	char		*cmds;

	storage = (t_storage *)malloc(sizeof(t_storage));
	if (!storage)
		exit (INIT_STORAGE);
	stack_a = NULL;
	stack_b = NULL;
	sorted = NULL;
	cmds = NULL;
	storage->a = stack_a;
	storage->b = stack_b;
	storage->sorted = sorted;
	storage->cmds = cmds;
	storage->cmds_len = 0;
	storage->first_flag = ON;
	return (storage);
}

int	main(int argc, char **argv)
{
	t_storage	*storage;

	if (argc < 2)
		return (CHECKER_MAIN);
	validate_argv(argc - 1, argv + 1);
	storage = init_storage();
	storage->a = init_stack(argc - 1, argv + 1, storage);
	storage->b = init_stack(0, NULL, storage);
	scan_dupulicates(storage->a, storage);
	receive_cmds(storage->a, storage->b);
	free_all(storage);
	return (0);
}
