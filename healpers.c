#include "push_swap.h"

void    ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
        write(1, &str[i++], 1);
    write(1, "\n", 1);
}

void    error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

long    ft_atol(const char *str)
{
    long    res = 0;
    int     sign = 1;
    int     i = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}