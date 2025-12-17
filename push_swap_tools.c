/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:11:17 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/16 11:46:30 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*to_mov;

	if (ft_lstsize(*a) == 0)
		return ;
	to_mov = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->pver = NULL;
	to_mov->next = NULL;
	to_mov->pver = NULL;
	ft_lstadd_front(b, to_mov);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*to_mov;

	if (ft_lstsize(*b) == 0)
		return ;
	to_mov = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->pver = NULL;
	to_mov->next = NULL;
	to_mov->pver = NULL;
	ft_lstadd_front(a, to_mov);
}

void	rb(t_stack **b)
{
	t_stack	*first;

	if (ft_lstsize(*b) < 2)
		return ;
	first = *b;
	*b = (*b)->next;
	first->next = NULL;
	first->pver = NULL;
	ft_lstadd_back(b, first);
}

void	ra(t_stack **a)
{
	t_stack	*first;

	if (ft_lstsize(*a) < 2)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	first->pver = NULL;
	ft_lstadd_back(a, first);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "ra\nrb\n", 6);
}
