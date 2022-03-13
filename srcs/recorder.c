#include <push_swap.h>

static char	*sham_realloc(char **reco, size_t size)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (size * 2) + 1);
	if (!tmp)
	{
	
	}
	ft_memset(tmp, 1, size * 2);
	tmp[size * 2] = '\0';
	ft_memcpy(tmp, *reco, size);
	free(*reco);
	return (tmp);
}

void	recorder(char **rec, int act)
{
	static char		**recording;
	static size_t	size;
	static size_t	index;

	if(rec && act == 0)
	{
		recording = rec;
		size = ft_strlen(*rec);
		index = 0;
	}
	else if (rec == NULL)
	{
		if (size == index)
		{
			*recording = sham_realloc(reco, size);
			size = size * 2;
		}
		(*reco)[index++] = act;
	}
}

static char	*allocate_record(size_t size, t_stack *stack_a, t_sort *sort, char **rec)
{
	char	*record;

//	record = (char *)malloc(sizeof(char) * size + 1);
	record = (char *)ft_calloc(sizeof(char) * size + 1);
	if (!record)
	{
		free_stack(stack_a);
		free_sort(sort);
		free(rec);
		exit_with_status(ALLOC_RECORD);
	}
	return (record);
}

static char	*allocate_rec(size_t size, t_stack *stack_a, t_sort *sort)
{
	char		**rec;

	rec = (char **)malloc(sizeof(char *));
	if (!rec)
	{
		free_stack(stack_a);
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

	rec = allocate_rec(size, stack_a, sort);
	record = allocate_record(size, stack_a, sort, rec);
//	ft_memset(record, 1, size);
	record[size] = '\0';
	*rec = record;
//	vals_storage(NULL, NULL, NULL, rec);
	recorder(rec, 0);
	return (rec);
}
