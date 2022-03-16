#include "push_swap.h"

void	case_three_in_b(t_stack *stack, t_storage *storage)
{
	int	a;
	int	b;
	int	c;

	c = stack->next->val;
	b = stack->next->next->val;
	a = stack->next->next->next->val;
	if (b < a && a < c)
		swap(stack, storage);
	else if (c < b && b < a)
	{
		swap(stack, storage);
		rot_down(stack, storage);
	}
	else if (b < c && c < a)
		rot_up(stack, storage);
	else if (a < c && c < b)
	{
		swap(stack, storage);
		rot_up(stack, storage);
	}
	else if (c < a && a < b)
		rot_down(stack, storage);
}

static void	case_six_or_less_in_b(t_stack *a, t_stack *b, size_t size, t_storage *storage)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (size = 2)
	{
		x = b->next->val;
		y = b->next->next->val;
		if (x < y)
			swap(b, storage);
	}
	while (size > 3)
	{
		set_max(b, storage);
		push(b, a, storage);
		size--;
	}
	case_three_in_b(b, storage);
	while (size > 0)
	{
		push(b, a, storage);
		size--;
	}
}

/*
static void	push_all_to_a(t_storage *storage, size_t l, size_t r)
{
	int i;

	i = r - l + 1;
	while (0 < i)
	{
		set_max(storage->b, storage);
		push(storage->b, storage->a, storage);
		i--;
	}
	return ;
}
*/

static void	push_back_to_b(t_storage *storage, int p_count, int ra_count, int rb_count)
{
	t_stack	*a;
	t_stack	*b;

	a = storage->a;
	b = storage->b;
	while (ra_count > 0)
	{
		rot_down(a, storage);
		ra_count--;
	}
	while (rb_count > 0)
	{
		rot_down(b, storage);
		rb_count--;
	}
	while (p_count > 0)
	{
		push(a, b, storage);
		p_count--;
	}
}

static void	push_back_to_a(t_storage *storage, size_t x, size_t y, int count)
{
	int		p_count;
	int		ra_count;
	int		rb_count;

	p_count = 0;
	ra_count = 0;
	rb_count = 0;
	while (0 < count)
	{
		if (storage->b->next->val > storage->sorted[y]) // val > 3/4
		{
			p_count += push(storage->b, storage->a, storage); 
			count--;
		}
		else if (storage->b->next->val > storage->sorted[x]) // val > 1/2
		{
			p_count += push(storage->b, storage->a, storage);
			ra_count += rot_up(storage->a, storage);
			count--;
		}
		else
			rb_count += rot_up(storage->b, storage); // doenn't need to count at last
	}
	push_back_to_b(storage, p_count, ra_count, rb_count);
}

//static int	count_more_than_pivot(t_stack *b, int pv, int lv, int rv)
static int	count_more_than_pivot(t_stack *b, int pv)
{
	t_stack	*head;
	int		count;

	count = 0;
	head = b;
	b = b->next;
	while (b != head)
//	while (b != head && lv <= b->val && b->val <= rv)
	{
		if (b->val > pv) //what if to use >=
			count++;
		b = b->next;
	}
	return (count);
}

void sort_stack_b(t_storage *storage, size_t l, size_t r)
{
	int		count;
	size_t	x;
	size_t	y;

	x = (l + r) / 2; // 1/2
	y = (x + r) / 2; // 3/4
	count = count_more_than_pivot(storage->b, storage->sorted[x]);
	//can be changed
/*
	if (l <= r && r - l <= 9) //where the 9 comes from? 
	{
		push_all_to_a(storage, l, r); 
		return ;
	}
*/
	if (l <= r && r - l <= 5) //where the 9 comes from? 
	{
		case_six_or_less_in_b(storage->a, storage->b, r - l + 1, storage); 
		return ;
	}
	push_back_to_a(storage, x, y, count); // 
	sort_stack_b(storage, y + 1, r); //3/4 + 1 ~ r
	sort_stack_b(storage, x + 1, y);// 1/2 +1  ~  3/4
	sort_stack_b(storage, l, x); // l ~ 1/2
}
