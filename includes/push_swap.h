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

typedef struct s_sort
{
	int		*array;
	size_t	size;
} t_sort;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_sort	*sort;
}	t_stacks;

enum error_handling
{
	CONTINUE,
	ERROR,
	STR_IS_ALL1,
	STR_IS_ALL2,
	INIT_STACK,
	ALLOC_STACK,
	NO_DUPLICATE,
	ATOI_WITH,
	PRE_SORT1,
	PRE_SORT2,
	ALLOC_RECORD,
	ALLOC_REC,


	/*
  ALLOC_ERROR,
	INVALID_INPUT,
	STACK_ERROR,
	PRESORT_ERROR,
	SORTED_MALLOC_ERROR,
	MAIN_STACK_ERROR,
	MAIN_SORT_ERROR,
	CASE_GT,
	SHAM_ERROR,
*/
};

//validate_number.c
t_stack	*validate_number(int argc, char **argv);


//exit.c
void	exit_with_status(enum error_handling status);
void	print_error_and_exit(enum error_handling status);

//free
void	free_stack(t_stack *stack, int count);
void	free_all(t_stack *stack1, t_stack *stack2, t_sort *sort, char *record);

// pre_sort.c
t_sort	*pre_sort(t_stack *stack);

// recorder.c
char	**record_array(size_t size);
void	recorder(char **record, int act);
void	player(char *record);





// arg_check.c
int		is_sorted(t_stack *stack);
int		is_digit_str(int as, char *av[]);
int		atoi_and_errcheck(char *str, t_stack *stack, size_t i);
int		is_unique(t_stack *stack);

// base_act.c
void	swap(t_stack *stack, int ab);
void	push(t_stack *stack1, t_stack *stack2, int ab);
void	r_rot(t_stack *stack, int ab);
void	rot(t_stack *stack, int ab);

// few_args.c
void	case_two(t_stack *stack);
void	case_three(t_stack *stack);
void	case_ngt_six(t_stack *stack1, t_stack *stack2);

// vals.c
void	vals_storage(t_stack *stack, t_stacks *stacks,
			t_sort *sort, char **record);

// shutdown.c
void	shutdown(enum error_handling msg);
void	error_exit(void);

// init_node.c
t_stack	*init_stack(int args, char *argv[]);
void	re_index(t_stack *stack);

// many_args_atob.c
void	atob(t_stacks *stacks, size_t l, size_t r, int first);

// many_args_btoa.c
void	btoa(t_stacks *stacks, size_t l, size_t r);

// many_args_btoa2.c
int		btoa_push(t_stacks *stacks);
int		btoa_rot(t_stack *stack, int ab);
void	btoa_pushall(t_stacks *stacks, size_t l, size_t r);

// optimizer.c
void	optimizer(char *record);

// search_val.c
void	set_min(t_stack *stack, int ab);
void	set_max(t_stack *stack, int ab);

// double_act.c
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif
