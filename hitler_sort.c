/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitler_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:19:20 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/15 11:34:33 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_hitler_sort(t_stack **a, t_stack **b)
{
	ft_calc_index(*a);
	if (is_sorted(*a, *b))
		return ;
	if (ft_lstsize(*a) <= 10)
		ft_stalin_sort(a, b);
	else
		ft_chunksort(a, b);
}

void	ft_calc_index(t_stack *a)
{
	int		i;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!a)
		return ;
	tmp2 = a;
	while (tmp2)
	{
		tmp1 = a;
		i = 0;
		while (tmp1)
		{
			if (tmp1->value < tmp2->value)
				i++;
			tmp1 = tmp1->next;
		}
		tmp2->index = i;
		tmp2 = tmp2->next;
	}
}
