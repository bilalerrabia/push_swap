#include "push_swap.h"

void stack_init(t_stack **stack_a, char **args, int size)
{
    int i;
    t_stack *tmp;

    i = 0;
    while (i < size)
    {
        tmp = ft_lstnew(ft_atol(args[i]));
        ft_lstadd_back(stack_a, tmp);
        i++;
    }
}
