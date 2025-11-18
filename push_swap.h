#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
    struct s_stack  *prev;
} t_stack;


void    sort_final_rotation(t_stack **stack_a);
void    sort_large(t_stack **stack_a, t_stack **stack_b);
void    sort_three(t_stack **stack_a);
int     is_sorted(t_stack *stack);
void    sort_small(t_stack **stack_a, t_stack **stack_b);
void    assign_indices(t_stack *stack_a);


t_stack *ft_lstnew(int value);
t_stack *ft_lstlast(t_stack *head);
int     ft_lstsize(t_stack *head);
void    ft_lstadd_front(t_stack **stack, t_stack *new_node);
void    ft_lstadd_back(t_stack **stack, t_stack *new_node);


void sa(t_stack **a);
void sb(t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);

void    free_stack(t_stack **stack);
void    ft_swap(t_stack **stack);
void    ft_push(t_stack **from, t_stack **to);
void    ft_rotate(t_stack **stack);
void    ft_reverse_rotate(t_stack **stack);



long    ft_atol(const char *str);
void    error_exit(void);
void    ft_putstr(char *str);

#endif