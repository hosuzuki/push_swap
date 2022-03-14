#include <push_swap.h>

static char	*expand_record(char **recording, size_t size)
{
	char	*tmp;

	tmp = (char *)ft_calloc((size * 2) + 1, sizeof(char));
	if (!tmp)
	{
		exit_with_status(EXPAND_RECORD); // add free all, chnange the argments.
	}
//	ft_memset(tmp, 1, size * 2);
	tmp[size * 2] = '\0';
	ft_memcpy(tmp, *recording, size);
	free(*recording);
	return (tmp);
}

void	recorder(char **rec, int cmd) //???
{
	static char		**recording;
	static size_t	size;
	static size_t	i;

	if(rec && cmd == 0)
	{
		recording = rec;
		size = ft_strlen(*rec);
		i = 0;
	}
	else if (rec == NULL) // ???
	{
		if (size == i)
		{
			*recording = expand_record(recording, size);
			size *= 2;
		}
		(*recording)[i++] = cmd;
	}
}

static char	*allocate_record(size_t size, t_stack *stack_a, t_sort *sort, char **rec)
{
	char	*record;

//	record = (char *)malloc(sizeof(char) * size + 1);
	record = (char *)ft_calloc(size + 1, sizeof(char));
	if (!record)
	{
		free_stack(stack_a, stack_a->val);
		free_sort(sort);
		free(rec);
		exit_with_status(ALLOC_RECORD);
	}
	return (record);
}

static char	**allocate_rec(t_stack *stack_a, t_sort *sort)
{
	char		**rec;

	rec = (char **)malloc(sizeof(char *));
	if (!rec)
	{
		free_stack(stack_a, stack_a->val);
		free_sort(sort);
		exit_with_status(ALLOC_REC);
	}
	return (rec);
}

//// can i just use free_all?

char	**record_array(size_t size, t_stack *stack_a, t_sort *sort)
{
	char		**rec;
	char		*record;

	rec = allocate_rec(stack_a, sort);
	record = allocate_record(size, stack_a, sort, rec);
//	ft_memset(record, 1, size);
	record[size] = '\0';
	*rec = record;
//	vals_storage(NULL, NULL, NULL, rec);
	recorder(rec, 0);
	return (rec);
}
