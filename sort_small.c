/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:20:06 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/16 13:26:32 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;
	int	min_pos;

	size = ft_lstsize(*a);
	while (size > 3)
	{
		min_pos = find_min_pos(*a);
		move_to_top(a, min_pos, size);
		pb(a, b);
		write(1, "pb\n", 3);
		size--;
	}
	sort_three(a);
	while (*b)
	{
		pa(a, b);
		write(1, "pa\n", 3);
	}
}

void	move_to_top(t_stack **stack, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			ra(stack);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (pos++ < size)
		{
			rra(stack);
			write(1, "rra\n", 4);
		}
	}
}

int	find_min_pos(t_stack *stack)
{
	t_stack	*tmp;
	int		min;
	int		pos;
	int		min_pos;

	tmp = stack;
	min = tmp->value;
	pos = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}
