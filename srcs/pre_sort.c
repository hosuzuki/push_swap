#include "push_swap.h"

static void	swap_in_sort(int *sort, size_t a, size_t b)
{
	int	tmp;

	tmp = sort[a];
	sort[a] = sort[b];
	sort[b] = tmp;
}

static int	partition(int *sort, size_t left, size_t right)
{
	size_t	l;
	size_t	r;
	int		pivot;

//	if (sort[left] < sort[left + 1])
//		pivot = sort[left + 1];
//	else
//		pivot = sort[left];
	pivot = sort[left];
	l = left;
	r = right;
	while (1)
	{
		while (l < right)
		{
			if (pivot <= sort[l])
				break ;
			l++;
		}
		while (left < r)
		{
			if (sort[r] <= pivot)
				break ;
			r--;
		}
		if (l >= r)
			break ;
		swap_in_sort(sort, l, r);
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
	part = partition(sort, left, right);
	quick_sort(sort, left, part - 1);
	quick_sort(sort, part, right);
}

t_sort	*pre_sort(t_stack *stack)
{
	t_sort	*sort;
	t_stack	*tmp;

	sort = (t_sort *)malloc(sizeof(t_sort));
	if (!sort)
	{
		free_stack(stack, stack->val);
		exit_with_status(PRE_SORT1);
	}
	sort->array =  (int *)malloc(sizeof(int) * stack->val); // don't I need +1?
	if (!sort->array)
	{
		free_stack(stack, stack->val);
		free(sort);
		exit_with_status(PRE_SORT2);
	}
	tmp = stack->next;
	while (tmp->index != 0)
	{
		sort->array[tmp->index - 1] = tmp->val;
		tmp = tmp->next;
	}
	quick_sort(sort->array, 0, stack->val - 1);
	sort->size = stack->val;
//	vals_storage(NULL, NULL, sort, NULL);
	return (sort);
}
