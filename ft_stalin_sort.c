/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stalin_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:21:48 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/16 11:41:07 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_stack *a)
{
	int		big;
	t_stack	*tmp;

	big = INT_MIN;
	tmp = a;
	while (tmp)
	{
		if (tmp->value > big)
			big = tmp->value;
		tmp = tmp->next;
	}
	return (big);
}

void	sort_three(t_stack **a)
{
	int	biggest;

	biggest = find_biggest(*a);
	if ((*a)->value == biggest)
	{
		ra(a);
		write(1, "ra\n", 3);
	}
	else if ((*a)->next->value == biggest)
	{
		rra(a);
		write(1, "rra\n", 4);
	}
	if ((*a)->value > (*a)->next->value)
	{
		sa(a);
		write(1, "sa\n", 3);
	}
}

void	ft_stalin_sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) <= 2)
	{
		if (!is_sorted(*a, *b))
		{
			ra(a);
			write(2, "ra\n", 3);
		}
	}
	else
		sort_small(a, b);
}
