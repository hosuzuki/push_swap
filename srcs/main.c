/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:50 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/16 21:26:50 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (MAIN1);
	validate_argv(argc - 1, argv + 1);
	storage = init_storage();
	storage->a = init_stack(argc - 1, argv + 1, storage);
	storage->b = init_stack(0, NULL, storage);
	scan_dupulicates(storage->a, storage);
	storage->sorted = init_sorted_array(storage->a, storage);
	storage->cmds = init_cmds_array(storage->a, storage);
	if (ALREADY_SORTED == select_algo(storage->a, storage->b, storage))
		free_all_and_exit(storage, MAIN2);
	optimize_cmds(storage->cmds);
	print_cmds(storage->cmds);
	free_all(storage);
	return (0);
}
