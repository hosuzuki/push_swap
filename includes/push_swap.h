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
	EXPAND_RECORD,


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

# define NOT_SORTED -2
# define ALREADY_SORTED -1

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


// main.c
int		is_sorted(t_stack *stack);

//validate_argv.c
t_stack	*validate_argv(int argc, char **argv);

//init_stack.c
t_stack	*init_stack(int args, char *argv[]);

//exit.c
void	exit_with_status(enum error_handling status);
void	print_error_and_exit(enum error_handling status);

//free.c
void	free_stack(t_stack *stack, int count);
void	free_sort(t_sort *sort);
void	free_all(t_stack *stack1, t_stack *stack2, t_sort *sort, char *record);

// pre_sort.c
t_sort	*pre_sort(t_stack *stack);

// recorder.c
char	**record_array(size_t size, t_stack *stack_a, t_sort *sort);
void	recorder(char **record, int cmd);

// cases_of_algo.c
void	case_two(t_stack *stack);
void	case_three(t_stack *stack);
void	case_four_to_six(t_stack *stack1, t_stack *stack2);
void	case_seven_or_more(t_stack *stack_a, t_stack *stack_b, t_sort *sort);

// operations.c
void	swap(t_stack *stack, int ab);
void	push(t_stack *stack1, t_stack *stack2, int ab);
void	rot_down(t_stack *stack, int ab);
void	rot_up(t_stack *stack, int ab);

// search_val.c
void	set_min(t_stack *stack, int ab);
void	set_max(t_stack *stack, int ab);
//void	renumber_index(t_stack *stack); // can be static?

// sort_stacks.c
void	sort_stacks(t_stacks *stacks, size_t l, size_t r, int first);

// sort_stack_b.c
void	sort_stack_b(t_stacks *stacks, size_t l, size_t r);

// sort_stack_b_utils.c
int		push_with_count(t_stacks *stacks);
int		rot_up_with_count(t_stack *stack, int ab);
void	push_all_to_a(t_stacks *stacks, size_t l, size_t r);

// optimize_cmds.c
void	optimize_cmds(char *record);

	// print_cmds.c
void	print_cmds(char *record);





// vals.c
void	vals_storage(t_stack *stack, t_stacks *stacks,
			t_sort *sort, char **record);

// double_act.c
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif
