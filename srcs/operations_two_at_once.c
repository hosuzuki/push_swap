#include "push_swap.h"

void	ss(t_stack *a, t_stack *b, t_storage *storage)
{
	swap(a, storage);
	swap(b, storage);
}

void	rr(t_stack *a, t_stack *b, t_storage *storage)
{
	rot_up(a, storage);
	rot_up(b, storage);
}

void	rrr(t_stack *a, t_stack *b, t_storage *storage)
{
	rot_down(a, storage);
	rot_down(b, storage);
}
