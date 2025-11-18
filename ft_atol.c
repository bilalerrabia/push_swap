#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	res;
	int		flag;
	int		i;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	flag = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	return ((res * flag));
}

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}