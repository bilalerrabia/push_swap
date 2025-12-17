/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:27:51 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/16 17:26:12 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error_bonus(t_stack **a, t_stack **b, char *move)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	free(move);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	tester(t_stack **a, t_stack **b)
{
	if (is_sorted(*a, *b))
	{
		write(1, "OK\n", 3);
		free_stack(a);
		free_stack(b);
		exit (0);
	}
	else
	{
		write(2, "Error\n", 6);
		free_stack(a);
		free_stack(b);
		exit(1);
	}
}

void	ft_main_loop_2(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strcmp(move, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(move, "rb\n"))
		rb(b);
	else if (!ft_strcmp(move, "ra\n"))
		ra(a);
	else if (!ft_strcmp(move, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(move, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(move, "ss\n"))
		ss(a, b);
	else
		ft_error_bonus(a, b, move);
	free(move);
}

void	ft_main_loop(t_stack **a, t_stack **b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!ft_strcmp(move, "pb\n"))
			pb(a, b);
		else if (!ft_strcmp(move, "pa\n"))
			pa(a, b);
		else if (!ft_strcmp(move, "sb\n"))
			sb(b);
		else if (!ft_strcmp(move, "sa\n"))
			sa(a);
		else if (!ft_strcmp(move, "rra\n"))
			rra(a);
		else
			ft_main_loop_2(a, b, move);
		move = get_next_line(0);
	}
	tester(a, b);
}
