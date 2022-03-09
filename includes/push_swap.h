#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int					n;
	size_t			index;
	struct s_list	*prev;
	struct s_list	*next;
} t_node;

typedef struct s_sort
{
	int		*array;
	size_t	size;
} t_sort;



#endif
