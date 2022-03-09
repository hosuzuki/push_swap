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

#endif
