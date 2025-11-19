#include "push_swap.h"

void    assign_indices(t_stack *stack_a)
{
    t_stack *ptr;
    t_stack *check;
    int     rank;

    ptr = stack_a;
    while (ptr)
    {
        rank = 0;
        check = stack_a;
        while (check)
        {
            if (check->value < ptr->value)
                rank++;
            check = check->next;
        }
        ptr->index = rank;
        ptr = ptr->next;
    }
}

int     is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void    sort_three(t_stack **stack_a)
{
    if (is_sorted(*stack_a))
        return ;
    if ((*stack_a)->index == 2)
        ra(stack_a);
    else if ((*stack_a)->next->index == 2)
        rra(stack_a);
    
    if ((*stack_a)->index > (*stack_a)->next->index)
        sa(stack_a);
}

void    sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
    int pushed;

    size = ft_lstsize(*stack_a);
    pushed = 0;
    while (size > 3 && pushed < 2)
    {
        if ((*stack_a)->index < 2)
        {
            pb(stack_a, stack_b);
            pushed++;
        }
        else
            ra(stack_a);
        size = ft_lstsize(*stack_a);
    }
    sort_three(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b);
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

void    sort_large(t_stack **stack_a, t_stack **stack_b)
{
    int     i;
    int     range;
    int     size;
    
    size = ft_lstsize(*stack_a);
    if (size <= 100)
        range = 15;
    else
        range = 30;

    i = 0;
    // Phase 1: A -> B (Chunking)
    while (*stack_a)
    {
        if ((*stack_a)->index <= i)
        {
            pb(stack_a, stack_b);
            rb(stack_b);
            i++;
        }
        else if ((*stack_a)->index <= i + range)
        {
            pb(stack_a, stack_b);
            i++;
        }
        else
            ra(stack_a);
    }

    // Phase 2: B -> A (Greedy Max)
    while (*stack_b)
    {
        int max_idx = -1;
        int max_pos = 0;
        int b_size = ft_lstsize(*stack_b);
        t_stack *curr = *stack_b;

        // Find max rank
        while (curr) {
            if (curr->index > max_idx) max_idx = curr->index;
            curr = curr->next;
        }
        
        // Find position
        curr = *stack_b;
        while (curr) {
            if (curr->index == max_idx) break;
            max_pos++;
            curr = curr->next;
        }

        // Rotate B (Optimized direction)
        if (max_pos <= b_size / 2)
        {
            while ((*stack_b)->index != max_idx)
                rb(stack_b);
        }
        else
        {
            while ((*stack_b)->index != max_idx)
                rrb(stack_b);
        }
        pa(stack_a, stack_b);
    }
}

void ft_hetler_sort(t_stack **stack_a,t_stack **stack_b)
{
    int size;

    assign_indices(*stack_a);
    if (is_sorted(*stack_a))
    {
        free_stack(stack_a);
        exit(0);
    }
    size = ft_lstsize(*stack_a);
    if (size <= 5)
        sort_small(stack_a, stack_b, size);
    else
        sort_large(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    int size;
    char **args;

    if (argc < 2)
        return (0);
    if (argc == 1 || argv[1][0] == '\0')
        error_exit();
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
        args = argv + 1;

    size =  args_size(args);

    if (!is_valid_values(args, size))
    {
        if (argc == 2)
            free_all(args, size);
        error_exit();
    }
    stack_init(&stack_a, args, size);
    if (argc == 2)
        free_all(args, size);
    ft_hetler_sort(&stack_a, &stack_b);
    free_stack(&stack_a);
    // free_stack(&stack_b);
}
