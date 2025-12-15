/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:14:40 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/15 11:38:08 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_biggest_to_top(t_stack **b, t_stack **a, int max_pos, int max_idx)
{
	if (max_pos <= ft_lstsize(*b) / 2)
	{
		while ((*b)->index != max_idx)
			rb(b);
	}
	else
	{
		while ((*b)->index != max_idx)
			rrb(b);
	}
	pa(a, b);
}

void	push_back_greedy(t_stack **a, t_stack **b)
{
	int		max_idx;
	int		max_pos;
	t_stack	*curr;

	max_idx = ft_lstsize(*b) - 1;
	while (*b)
	{
		max_pos = 0;
		curr = *b;

		curr = *b;
		while (curr)
		{
			if (curr->index == max_idx)
				break ;
			max_pos++;
			curr = curr->next;
		}
		move_biggest_to_top(b, a, max_pos, max_idx);
		max_idx--;
	}
}

void	ft_chunksort(t_stack **a, t_stack **b)
{
	int	i;
	int	chunk_size;

	i = 0;
	if (ft_lstsize(*a) <= 100)
		chunk_size = 17;
	else
		chunk_size = 35;
	while (*a)
	{
		if ((*a)->index < i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index < i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	push_back_greedy(a, b);
}
