/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:14:40 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/16 17:14:41 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_biggest_to_top(t_stack **b, t_stack **a, int max_pos, int max_idx)
{
	if (max_pos <= ft_lstsize(*b) / 2)
	{
		while ((*b)->index != max_idx)
		{
			rb(b);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		while ((*b)->index != max_idx)
		{
			rrb(b);
			write(1, "rrb\n", 4);
		}
	}
	pa(a, b);
	write(1, "pa\n", 3);
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

int	calc_chunk_size(int size)
{
	int	chunk_size;

	if (size <= 100)
		chunk_size = 17;
	else
		chunk_size = 35;
	return (chunk_size);
}

void	i_hate_25_line_role(t_stack **a, t_stack **b)
{
	pb(a, b);
	rb(b);
	write(1, "pb\nrb\n", 6);
}

void	ft_chunksort(t_stack **a, t_stack **b)
{
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = calc_chunk_size(ft_lstsize(*a));
	while (*a)
	{
		if ((*a)->index < i)
		{
			i_hate_25_line_role(a, b);
			i++;
		}
		else if ((*a)->index < i + chunk_size)
		{
			pb(a, b);
			write(1, "pb\n", 3);
			i++;
		}
		else
		{
			ra(a);
			write(1, "ra\n", 3);
		}
	}
	push_back_greedy(a, b);
}
