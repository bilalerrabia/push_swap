/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:37:37 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/15 03:52:05 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a, t_stack *b)
{
	if (ft_lstsize(b) > 0 || !a)
		return (0);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrb(a);
	rra(b);
}

int	ft_lstsize(t_stack *a)
{
	int	i;

	i = 0;
	if (!a)
		return (0);
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}
