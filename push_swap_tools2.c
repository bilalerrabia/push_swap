/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:00:18 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/16 11:47:02 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{	
	t_stack	*first;
	t_stack	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->pver = first;
	second->next = first;
	second->pver = NULL;
	first->pver = second;
	*a = second;
}

void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->pver = first;
	second->next = first;
	second->pver = NULL;
	first->pver = second;
	*b = second;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "sa\nsb\n", 6);
}

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*prev;

	if (!a || !*a || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	prev = last->pver;
	prev->next = NULL;
	last->pver = NULL;
	last->next = *a;
	(*a)->pver = last;
	*a = last;
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*prev;

	if (!b || !*b || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	prev = last->pver;
	prev->next = NULL;
	last->pver = NULL;
	last->next = *b;
	(*b)->pver = last;
	*b = last;
}
