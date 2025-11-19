#include "push_swap.h"

int     args_size(char **args)
{
    int i;

    i = 0;
    if (!args)
        return (0);
    while (args[i])
        i++;
    return (i);
}

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}
int is_valid_values(char **args, int size)
{
    int i;
    int j;
    long val;

    i = 0;
    while (i  < size)
    {
        j = 0;
        val = ft_atol(args[i]);
        if (val > INT_MAX || val < INT_MIN)
            return (0);
        while (args[i][j])
        {
            while (args[i][j] == ' ' || (args[i][j] >= 9 && args[i][j] <= 13))
                j++;
            if (args[i][j] == '-' || args[i][j] == '+')
                j++;
            while (args[i][j])
            {
                if (!ft_isdigit(args[i][j]))
                    return (0);
                j++;
            }
        }
        i++;
    }
    return (1);
}