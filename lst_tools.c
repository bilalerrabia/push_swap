#include "push_swap.h"

t_stack *ft_lstnew(int value)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->index = -1;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}

t_stack *ft_lstlast(t_stack *head)
{
    if (!head)
        return (NULL);
    while (head->next)
        head = head->next;
    return (head);
}

int     ft_lstsize(t_stack *head)
{
    int i = 0;
    while (head)
    {
        head = head->next;
        i++;
    }
    return (i);
}

// IMPORTANT: add_front must handle 'prev' pointers
void    ft_lstadd_front(t_stack **stack, t_stack *new_node)
{
    if (!new_node)
        return ;
    new_node->next = *stack;
    new_node->prev = NULL;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}

// IMPORTANT: add_back must handle 'prev' pointers
void    ft_lstadd_back(t_stack **stack, t_stack *new_node)
{
    t_stack *last;

    if (!new_node)
        return ;
    if (!*stack)
    {
        *stack = new_node;
        new_node->prev = NULL; // Ensure prev is null for head
        return ;
    }
    last = ft_lstlast(*stack);
    last->next = new_node;
    new_node->prev = last;
    new_node->next = NULL;
}