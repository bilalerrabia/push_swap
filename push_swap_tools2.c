/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:00:18 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/08 15:46:53 by berrabia         ###   ########.fr       */
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
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}
