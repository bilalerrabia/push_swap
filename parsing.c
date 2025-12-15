/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:45:05 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/07 09:06:16 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char car)
{
	return (car >= '0' && car <= '9');
}

long	ft_atol(char *arg)
{
	int		i;
	long	res;
	int		signe;

	res = 0;
	signe = 1;
	i = 0;
	while (arg[i] == ' ' || arg[i] == '\t' || arg[i] == '\n')
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		if (arg[i++] == '-')
			signe = -1;
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		res *= 10;
		res += (arg[i] - '0');
		i++;
	}
	return (res * signe);
}

int	is_valid(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i])
	{
		if (!is_digit(arg[i]))
			return (0);
		i++;
	}
	if (ft_atol(arg) > INT_MAX || ft_atol(arg) < INT_MIN)
		return (0);
	return (1);
}

int	is_valids(char **args, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (!is_valid(args[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ft_atol(args[i]) == ft_atol(args[j]) && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
