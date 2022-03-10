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

typedef struc s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_sort	*sort;
}	t_stacks;

enum error_handling
{
	SENTINEL_ERROR;
	ALLOC_ERROR;
	INVALID_INPUT;
	STACK_ERROR;
	PRESORT_ERROR;
	SORTED_MALLOC_ERROR;
};

int	is_digit_str(int sum, char *argv[]);
void	free_stack(t_stack *stack, int count);

t_stack	*init_stack(int argc, char **argv);
void	shutdown(enum error_handling msg);

#endif
