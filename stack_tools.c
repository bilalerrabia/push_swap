#include "push_swap.h"


void    free_stack(t_stack **stack)
{
    t_stack *tmp;
    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}
void ft_swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    
    if (!stack || ft_lstsize(*stack) < 2)
        return ;
    
    first = *stack;
    second = (*stack)->next;
    
    *stack = second; // Update head

    first->next = second->next;
    if (first->next)
        first->next->prev = first;
    
    first->prev = second;
    second->prev = NULL; // New head has no prev
    second->next = first;
}

void    ft_push(t_stack **from, t_stack **to)
{
    t_stack *tmp;

    if (!from || !*from)
        return ;
    
    tmp = *from;
    *from = (*from)->next;
    
    if (*from)
        (*from)->prev = NULL;
    
    // Clean links of the node moving
    tmp->next = NULL;
    tmp->prev = NULL;
    
    ft_lstadd_front(to, tmp);
}

void    ft_rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *new_head;

    if (!stack || !*stack || !(*stack)->next)
        return ;
        
    first = *stack;
    new_head = first->next;
    
    new_head->prev = NULL;
    first->next = NULL;
    first->prev = NULL;
    
    *stack = new_head;
    ft_lstadd_back(stack, first); // Handles the re-linking to last
}
    
void    ft_reverse_rotate(t_stack **stack)
{
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    
    last = ft_lstlast(*stack);
    
    // Detach last
    if (last->prev)
        last->prev->next = NULL;
    
    last->prev = NULL;
    last->next = NULL;
    
    ft_lstadd_front(stack, last);
}

/* --- 4. OPERATION WRAPPERS (For printing) --- */

void sa(t_stack **a) { ft_swap(a); ft_putstr("sa"); }
void sb(t_stack **b) { ft_swap(b); ft_putstr("sb"); }
void pa(t_stack **a, t_stack **b) { ft_push(b, a); ft_putstr("pa"); }
void pb(t_stack **a, t_stack **b) { ft_push(a, b); ft_putstr("pb"); }
void ra(t_stack **a) { ft_rotate(a); ft_putstr("ra"); }
void rb(t_stack **b) { ft_rotate(b); ft_putstr("rb"); }
void rra(t_stack **a) { ft_reverse_rotate(a); ft_putstr("rra"); }
void rrb(t_stack **b) { ft_reverse_rotate(b); ft_putstr("rrb"); }
