#include "push_swap.h"

void	exit_with_number(enum error_handling number)
{
//	vals_storage(NULL, NULL, NULL, NULL);
	exit(number);
}

void	print_error_and_exit(enum error_handling number)
{
	write(2, "Error\n", 6);
	exit_with_number(number);
}
