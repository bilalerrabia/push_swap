/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:23:03 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/16 17:17:54 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	ft_main_loop(&a, &b);
	free_stack(&a);
}
