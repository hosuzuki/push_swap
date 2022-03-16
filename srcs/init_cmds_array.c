#include <push_swap.h>

char	*init_cmds_array(t_stack *a, t_storage *storage)
{
	char	*cmds;
	size_t	size;

	size = a->val * 20;
	cmds = (char *)ft_calloc(size, sizeof(char));
	if (!cmds)
		free_all_and_exit(storage, INIT_CMDS_ARRAY);
	storage->cmds_len = size;
	return (cmds);
}
