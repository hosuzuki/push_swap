#include "push_swap.h"

void	shutdown(enum error_handling msg)
{
	vals_storage(NULL, NULL, NULL, NULL);
	exit(msg);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	shutdown();
}
