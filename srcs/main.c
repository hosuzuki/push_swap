#include "push_swap.h"

static void	scan_dupulicates(t_stack *a, t_storage *storage)
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

static void	validate_argv(int argc, char **argv)
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
			exit (VALIDATE_ARGV1);
		if (str[0] == '-' && str[1] != '\0')
			i++;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
			{
				write(2, "Error\n", 6);
				exit (VALIDATE_ARGV2);
			}
			i++;
		}
		j++;
	}
}
static t_storage	*init_storage(void)
{
	t_storage	*storage;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	*sorted;
	char	*cmds;

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

int main(int argc, char **argv)
{
	t_storage	*storage;

	if (argc < 2)
		return (MAIN1);
	validate_argv(argc, argv);
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
	free_all_and_exit(storage, 0);
	return (0);
}
