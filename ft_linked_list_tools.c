/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:06:50 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/15 11:09:27 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}

t_stack	*ft_lstlast(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

void	ft_lstadd_back(t_stack **a, t_stack *new)
{
	t_stack	*last;

	if (!a || !new)
		return ;
	if (!*a)
	{
		new->next = NULL;
		new->pver = NULL;
		*a = new;
		return ;
	}
	last = ft_lstlast(*a);
	last->next = new;
	new->next = NULL;
	new->pver = last;
}

void	ft_lstclear(t_stack **a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!*a)
		return ;
	tmp1 = *a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}

void	ft_lstadd_front(t_stack **a, t_stack *new)
{
	if (!a || !new)
		return ;
	if (!*a)
	{
		new->next = NULL;
		new->pver = NULL;
		*a = new;
		return ;
	}
	new->next = *a;
	(*a)->pver = new;
	new->pver = NULL;
	*a = new;
}
