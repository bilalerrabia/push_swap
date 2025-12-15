/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:18:20 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/07 09:18:48 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_init(t_stack **a, char **args, int size)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (i < size)
	{
		new = ft_lstnew(ft_atol(args[i]));
		if (!new)
		{
			ft_lstclear(a);
			return ;
		}
		ft_lstadd_back(a, new);
		i++;
	}
}
