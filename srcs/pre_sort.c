#include "push_swap.h"

static int	partition(int *sort, size_t left, size_t right)
{
	size_t	l;
	size_t	r;
	int		tmp;

	l = left;
	r = right;
	while (l < r)
	{
		while (sort[r] >= sort[left] && r > left)
			r--;
		if (l >= r)
			break;
		tmp = sort[l];
		sort[l] = sort[r];
		sort[r] = tmp;
	}
	if (l == left)
		return (l + 1);
	return (l);
}

static void	quick_sort(int *sort, size_t left, size_t right)
{
	size_t part;

	if(left >= right)
		return ;
	part = parition(sort, left, right);
	quick_sort(sort, left, part - 1);
	quick_sort(sort, part, right);
}

static int	*sorted_array(t_stack *stack)
{
	int	*a;

	a = (int *)malloc(sizeof(int) * stack->val);
	if (!a)
		shutdown(SORTED_MALLOC_ERROR);
	while (stack->index != 0)
	{
		a[stack->index - 1] = stack->val;
		stack = stack->next;
	}
	quick_sort(a, 0, stack->val - 1);
	return (a);
}

t_sort	*pre_sort(t_stack *stack)
{
	t_sort	*sort;

	sort = (t_sort *)malloc(sizeof(t_sort));
	if (!sort || !stack)
		shutdown(PRESORT_ERROR);
	sort->array = sorted_array(stack);
	sort->size = stack->val;
	vals_strage(NULL, NULL, sort, NULL);
	return (sort);
}
