/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihatenorm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:49:42 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/16 17:17:04 by berrabia         ###   ########.fr       */
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
	write(2, "Error\n", 6);
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
