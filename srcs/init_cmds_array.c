#include <push_swap.h>

char	*init_cmds_array(t_stack *a, t_storage *storage)
{
	char	*cmds;
	size_t size;

	size = a->val * 20;
	cmds = (char *)ft_calloc(size, sizeof(char));
	if (!cmds)
		free_all_and_exit(storage, INIT_CMDS_ARRAY);
//	ft_memset(record, 1, size);
//	record[size] = '\0'; // needed?
//	*rec = record;
//	vals_storage(NULL, NULL, NULL, rec);
//	recorder(rec, 0);
	return (cmds);
}