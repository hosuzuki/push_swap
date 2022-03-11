#include <push_swap.h>

void	recorder(char **record, int act)
{
	static char		**reco;
	static size_t	size;
	static size_t	index;

	if(record && act == 0)
	{
		reco = record;
		size = ft_strlen(*record);
		index = 0;
	}
	else if (record == NULL)
	{
		if (size == index)
		{
			*reco = sham_realloc(reco, size);
			size = size * 2;
		}
		(*reco)[index++] = act;
	}
}

char	**record_array(size_t size)
{
	char		*record;
	char		**ret;

	record = (char *)malloc(sizeof(char) * size + 1);
	ret = (char **)malloc(sizeof(char *));
	if (!record || !ret) // Need free record ore ret?
		return (NULL);
	ft_memset(record, 1 size);
	record[size] = '\0';
	*ret = record;
	vals_storage(NULL, NULL, NULL, ret);
	recorder(ret, 0);
	return (ret);
}

void	player(char *record)
{
	size_t	i;

	i = 0;
	optimizer(record);
	while (record[i])
	{
		while (record[i] == 1)
			i++;
		if (!record[i])
			break ;
		print_command(record[i]);
		i++;
	}
	vals_storage(NULL, NULL, NULL, NULL);
}
