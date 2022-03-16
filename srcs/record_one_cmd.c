/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_one_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:52 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/16 21:26:52 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	record_cmds(int cmd, t_storage *storage)
{
	static size_t	i;
	char			*tmp;

	if (storage == NULL)
		return ;
	if (storage->cmds_len < i + 2)
	{
		tmp = (char *)ft_calloc((storage->cmds_len * 2), sizeof(char));
		if (!tmp)
			free_all_and_exit(storage, RECORD_CMDS);
		ft_memcpy(tmp, storage->cmds, storage->cmds_len);
		free(storage->cmds);
		storage->cmds = tmp;
		storage->cmds_len *= 2;
	}
	storage->cmds[i] = cmd;
	i++;
}

void	record_one_cmd(int cmd_a, int cmd_b, t_stack *stack, t_storage *storage)
{
	if (storage == NULL)
		return ;
	if (stack == storage->a)
		record_cmds(cmd_a, storage);
	else
		record_cmds(cmd_b, storage);
}
