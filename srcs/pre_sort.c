#include "push_swap.h"

static int	*sorted_array(t_stack *stack)
{
	int	*a;

	a = (int *)malloc(sizeof(int) * stack->val);
	if (!a)
		shutdown(SORTED_MALLOC_ERROR);

t_sort	*pre_sort(t_stack *stack)
{
	t_sort	*sort;

	sort = (t_sort *)malloc(sizeof(t_sort));
	if (!sort || !stack)
		shutdown(PRESORT_ERROR);
	sort->array = sorted_array(stack);

