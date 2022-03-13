#include "push_swap.h"

int	is_digit_str(int as, char *argv[])
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	while (j < as)
	{
		i = 0;
		str = argv[j];
		if (str[0] == '\0')
			return (0);
		if (str[0] == '-' && str[1] != '\0')
			i++;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			if (str[i])
				i++;
		}
		j++;
	}
	return (1);
}

int	validate_number(
