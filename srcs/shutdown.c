#include "push_swap.h"

void	shutdown(enum error_handling msg)
{
	vals_storage(NULL, NULL, NULL, NULL);
	exit(msg);
}
