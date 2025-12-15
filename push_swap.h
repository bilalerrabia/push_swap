/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:45:17 by berrabia          #+#    #+#             */
/*   Updated: 2025/12/15 04:01:14 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s{
	int			value;
	int			index;
	struct s	*next;
	struct s	*pver;
}	t_stack;

void		ft_stack_init(t_stack **a, char **args, int size);

void		ft_calc_index(t_stack *a);
void		ft_error(void);

long		ft_atol(char *arg);

char		**ft_split(char const *s, char c);
char		**free_all(char **res, int j);
int			ft_args_size(char **args);

int			is_valids(char **args, int size);
int			is_valid(char *arg);
void		invalid_exit(int argc, char **args, int size);

t_stack		*ft_lstnew(int value);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *a);
void		ft_lstclear(t_stack **a);
void		ft_lstadd_front(t_stack **a, t_stack *new);

void		free_stack(t_stack **a);

void		ft_chunksort(t_stack **a, t_stack **b);
void		push_back_greedy(t_stack **a, t_stack **b);
void		ft_hitler_sort(t_stack **a, t_stack **b);
void		ft_stalin_sort(t_stack **a, t_stack **b);
int			ft_lstsize(t_stack *a);

void		rb(t_stack **b);
void		ra(t_stack **a);
void		pb(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		sb(t_stack **b);
void		sa(t_stack **a);
void		ss(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

int			is_sorted(t_stack *a, t_stack *b);
void		sort_three(t_stack **a);
int			find_min_pos(t_stack *stack);
void		move_to_top(t_stack **stack, int pos, int size);
void		sort_small(t_stack **a, t_stack **b);
int			find_biggest(t_stack *a);

#endif
