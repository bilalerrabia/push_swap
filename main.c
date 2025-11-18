#include "push_swap.h"

int	is_valid_values(int size, char **argv)
{
	int i;
    int j;
    long val;

    i = 0;
    j = 0;
    while (i < size)
    {
        val = ft_atol(argv[i]);
        if (val > INT_MAX || val < INT_MIN)
            return (0);
        j = 0;
        while (argv[i][j])
        {
            while (argv[i][j] == ' ' || (argv[i][j] >= 9 && argv[i][j] <= 13))
                j++;
            if (argv[i][j] == '-' || argv[i][j] == '+')
            {
                j++;
                if (argv[i][j] == '-' || argv[i][j] == '+')
                    return (0);
            }
            while (argv[i][j])
                if (!ft_isdigit(argv[i][j++]))
                    return (0);
        }
        i++;
    }
    return (1);
}

// int main(int argc, char **argv)
// {
//     t_stack *a = NULL;
//     t_stack *b = NULL;
//     char **args;
//     int size;

//     if (argc == 1 || argv[1][0] == '\0')
//         return (1);
//     if (argc == 2)
//     {
//         args = ft_split(argv[1], ' ');
//         size = 0;
//         while (args[size])
//             size++;
//     }
//     else
//     {
//         args = &argv[1];
//         size = argc - 1;
//     }
//     if (!is_valid_values(size, args))
//     {
//         printf("Error\n");
//         if (argc == 2)
//             free_all(args, size);
//         return (1);
//     }
//     init_stack(&a, args, size);
//     if (argc == 2)
//         free_all(args, size);

//     stalin_sort(&a, &b);
//     hetler_sort(&a, &b);
//     t_stack *tmp = a;
//     while (tmp)
//     {
//         printf("|%d|\n ^\n |\n", tmp->value);
//         tmp = tmp->next;
//     }
//     ft_lstclear(&a);
//     ft_lstclear(&b);
// }

