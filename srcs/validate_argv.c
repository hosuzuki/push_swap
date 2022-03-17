/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:26:53 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/17 14:00:00 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scan_dupulicates(t_stack *a, t_storage *storage)
{
	t_stack	*tmp;

	a = a->next;
	while (a->next->index != 0)
	{
		tmp = a->next;
		while (tmp->index != 0)
		{
			if (a->val == tmp->val)
			{
				write(1, "Error\n", 6);
				free_all_and_exit(storage, SCAN_DUPLICATES);
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
}

static void	print_error_and_exit(enum e_error_handling status)
{
	write(1, "Error\n", 6);
	exit (status);
}

void	validate_argv(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	while (j < argc)
	{
		i = 0;
		str = argv[j];
		if (str[0] == '\0')
			print_error_and_exit(VALIDATE_ARGV1);
		if (str[0] == '-' && str[1] != '\0')
			i++;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				print_error_and_exit(VALIDATE_ARGV2);
			i++;
		}
		j++;
	}
}
