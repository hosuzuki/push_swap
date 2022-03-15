#include <push_swap.h>

void	record_cmds(t_storage *storage, int cmd)
{
	static size_t i;
	char *tmp;

//	i = 0;
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

char	*init_cmds_array(t_stack *a, t_storage *storage)
{
	char	*cmds;
	size_t size;

	size = a->val * 20;
	cmds = (char *)ft_calloc(size, sizeof(char));
	if (!cmds)
		free_all_and_exit(storage, INIT_CMDS_ARRAY);
//	ft_memset(record, 1, size);
	storage->cmds_len = size;
	return (cmds);
}
