#include "push_swap.h"

void	exit_with_status(enum error_handling status)
{
//	vals_storage(NULL, NULL, NULL, NULL);
	exit(status);
}

void	print_error_and_exit(enum error_handling status)
{
	write(2, "Error\n", 6);
	exit_with_status(status);
}
