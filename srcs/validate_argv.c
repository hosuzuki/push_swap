#include "push_swap.h"

void	scan_dupulicates(t_stack *a, t_storage *storage)
{
	t_stack *tmp;

	a = a->next;
	while (a->next->index != 0)
	{
		tmp = a->next;
		while (tmp->index != 0)
		{
			if (a->val == tmp->val)
			{
				write(2, "Error\n", 6);
				free_all_and_exit(storage, SCAN_DUPLICATES);
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
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
			exit (VALIDATE_ARG1);
		if (str[0] == '-' && str[1] != '\0')
			i++;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
			{
				write(2, "Error\n", 6);
				exit (VALIDATE_ARG2);
			}
			i++;
		}
		j++;
	}
}
