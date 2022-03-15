#include "push_swap.h"

static void	push_all_to_a(t_stacks *stacks, size_t l, size_t r)
{
	int i;

	i = r - l + 1;
	while (0 < i)
	{
		set_max(stacks->b, 2);
		push(stacks->b, stacks->a, 2);
		i--;
	}
	return ;
}

static void	push_back_to_b(t_storage *storage, int p_count, int ra_count, int rb_count)
{
	t_stack	*a;
	t_stack	*b;

	a = storage->a;
	b = storage->b;
	while (ra_count > 0)
	{
		rot_down(a, 1);
		ra_count--;
	}
	while (rb_count > 0)
	{
		rot_down(b, 2);
		rb_count--;
	}
	while (p_count > 0)
	{
		push(a, b, 1);
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
			p_count += push(storage->b, storage->a, 2); 
			count--;
		}
		else if (storage->b->next->val > storage->sorted[x]) // val > 1/2
		{
			p_count += push(storage->b, storage->a, 2);
			ra_count += rot_up(storage->a, 1);
			count--;
		}
		else
			rb_count += rot_up(storage->b, 2); // doenn't need to count at last
	}
	push_back_to_b(storage, p_count, ra_count, rb_count);
}

static int	count_more_than_pivot(t_stack *b, int pv, int lv, int rv)
{
	t_stack	*head;
	int		count;

	count = 0;
	head = b;
	b = b->next;
	(void)lv;// delete
	(void)rv;//delete
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

	x = (l + r) /2; // 1/2
	y = (x + r) /2; // 3/4
	count = count_more_than_pivot(storage->b, storage->sort->array[x],
			storage->sort->array[l], storage->sort->array[r]);
	//can be changed
	if (l <= r && r - l <= 9) //where the 9 comes from? 
	{
		push_all_to_a(storage, l, r); 
		return ;
	}
	push_back_to_a(storage, x, y, count); // 
	sort_stack_b(storage, y + 1, r); //3/4 + 1 ~ r
	sort_stack_b(storage, x + 1, y);// 1/2 +1  ~  3/4
	sort_stack_b(storage, l, x); // l ~ 1/2
}
