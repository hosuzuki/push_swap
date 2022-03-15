#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int					val;
	size_t			index;
	struct s_stack	*prev;
	struct s_stack	*next;
} t_stack;

typedef struct s_storage
{
	t_stack	*a;
	t_stack	*b;
	int	*sorted;
	char	*cmds;
	size_t cmds_len;
	int	first_flag;
}	t_storage;

enum error_handling
{
	CONTINUE,
	ERROR,
	MAIN1,
	MAIN2,
	INIT_STORAGE,
	VALIDATE_ARGV1,
	VALIDATE_ARGV2,
	SCAN_DUPLICATES,
	ALLOC_STACK,
	ATOI_PS,
	INIT_SORTED_ARRAY,
	INIT_CMDS_ARRAY,
	RECORD_CMDS,
};

# define ON 0
# define OFF 1
# define NOT_SORTED -1
# define ALREADY_SORTED -2
# define SA 2
# define SB 3
# define PB 4 // change?
# define PA 5
# define RRA 6
# define RRB 7
# define RA 8
# define RB 9
# define RR 10
# define RRR 11
# define SS 12 // change this to 4

// init_stack.c
t_stack	*init_stack(int argc, char **argv, t_storage *storage);

// free.c
void	free_all_and_exit(t_storage *storage, enum error_handling status);
void	free_stack(t_stack *stack);

// init_sorted_array.c
int	*init_sorted_array(t_stack *a, t_storage *storage);

// init_cmds_array.c
char	*init_cmds_array(t_stack *a, t_storage *storage);
void	record_cmds(t_storage *storage, int cmd);

// select_algo.c
void	case_two(t_stack *stack, t_storage *storage);
void	case_three(t_stack *stack, t_storage *storage);
int select_algo(t_stack *a, t_stack *b, t_storage *storage);

// sort_stacks
void	sort_stacks(t_storage *storage, size_t l, size_t r);

// sort_stack_b
void sort_stack_b(t_storage *storage, size_t l, size_t r);

// set_min_max_val.c
void	set_max(t_stack *stack, t_storage *storage);
void set_min(t_stack *stack, t_storage *storage);

// operations.c
void	swap(t_stack *stack, t_storage *storage);
int	push(t_stack *stack1, t_stack *stack2, t_storage *storage);
void	rot_down(t_stack *stack, t_storage *storage);
int	rot_up(t_stack *stack, t_storage *storage);

// optimize_cmds.c
void	optimize_cmds(char *cmds);

// print_cmds
void	print_cmds(char *cmds);


// double_act.c
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif
