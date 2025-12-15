/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:37:19 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/15 11:10:04 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_args_size(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack **a)
{
	ft_lstclear(a);
}

void	invalid_exit(int argc, char **args, int size)
{
	if (argc == 2)
		free_all(args, size);
	ft_error();
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	if (argc == 2)
		size = ft_args_size(args);
	else
		size = argc - 1;
	if (!is_valids(args, size))
		invalid_exit(argc, args, size);
	ft_stack_init(&a, args, size);
	if (argc == 2)
		free_all(args, size);
	ft_hitler_sort(&a, &b);
	free_stack(&a);
}
