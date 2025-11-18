/* ************************************************************************** */
/* */
/* checker.c - The Validator Program                                          */
/* */
/* Description:                                                               */
/* 1. Parses the initial stack arguments.                                     */
/* 2. Reads instructions (sa, pb, etc.) from Stdin.                           */
/* 3. Executes them on the stack.                                             */
/* 4. Prints "OK" if sorted, "KO" if not.                                     */
/* */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/* --- 1. STRUCTURES (Same as push_swap) --- */

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

/* --- 2. STRING UTILS --- */

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

long ft_atol(const char *str)
{
    long res = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-') sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

/* --- 3. STACK UTILS --- */

t_node *ft_lstnew(int value)
{
    t_node *new = malloc(sizeof(t_node));
    if (!new) return (NULL);
    new->value = value;
    new->next = NULL;
    return (new);
}

void ft_lstadd_back(t_node **stack, t_node *new)
{
    t_node *last;
    if (!new) return;
    if (!*stack) { *stack = new; return; }
    last = *stack;
    while (last->next) last = last->next;
    last->next = new;
}

void free_stack(t_node **stack)
{
    t_node *tmp;
    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}

/* --- 4. OPERATIONS (Silent) --- */
/* Note: Unlike push_swap, these do NOT print anything. */

void swap(t_node **stack)
{
    t_node *first;
    t_node *second;

    if (!*stack || !(*stack)->next) return;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void push(t_node **dest, t_node **src)
{
    t_node *temp;

    if (!*src) return;
    temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
}

void rotate(t_node **stack)
{
    t_node *first;
    t_node *last;

    if (!*stack || !(*stack)->next) return;
    first = *stack;
    last = *stack;
    while (last->next) last = last->next;
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void reverse_rotate(t_node **stack)
{
    t_node *last;
    t_node *prev;

    if (!*stack || !(*stack)->next) return;
    last = *stack;
    prev = NULL;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}

/* --- 5. EXECUTION LOGIC --- */

void execute_cmd(char *line, t_node **a, t_node **b)
{
    if (!ft_strcmp(line, "sa\n")) swap(a);
    else if (!ft_strcmp(line, "sb\n")) swap(b);
    else if (!ft_strcmp(line, "ss\n")) { swap(a); swap(b); }
    else if (!ft_strcmp(line, "pa\n")) push(a, b);
    else if (!ft_strcmp(line, "pb\n")) push(b, a);
    else if (!ft_strcmp(line, "ra\n")) rotate(a);
    else if (!ft_strcmp(line, "rb\n")) rotate(b);
    else if (!ft_strcmp(line, "rr\n")) { rotate(a); rotate(b); }
    else if (!ft_strcmp(line, "rra\n")) reverse_rotate(a);
    else if (!ft_strcmp(line, "rrb\n")) reverse_rotate(b);
    else if (!ft_strcmp(line, "rrr\n")) { reverse_rotate(a); reverse_rotate(b); }
    else error_exit(); // Invalid instruction
}

/* Simple function to read line by line from stdin */
void read_and_exec(t_node **a, t_node **b)
{
    char    buf[1];
    char    line[5]; // Max instruction len is 3 + \n + \0 = 5
    int     i;
    int     ret;

    i = 0;
    while ((ret = read(0, buf, 1)) > 0)
    {
        line[i++] = buf[0];
        if (buf[0] == '\n')
        {
            line[i] = '\0';
            execute_cmd(line, a, b);
            i = 0;
        }
        // If instruction is too long (should not happen with valid input)
        if (i >= 4) 
            error_exit();
    }
}

/* --- 6. VALIDATION --- */

int is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

/* --- 7. MAIN --- */

int main(int argc, char **argv)
{
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    int     i;
    long    val;

    if (argc < 2)
        return (0);

    // 1. Parse Args
    i = 1;
    while (i < argc)
    {
        val = ft_atol(argv[i]);
        if (val > INT_MAX || val < INT_MIN) error_exit();
        // Duplicate check should go here for strict compliance
        ft_lstadd_back(&stack_a, ft_lstnew((int)val));
        i++;
    }

    // 2. Read and Execute Instructions
    read_and_exec(&stack_a, &stack_b);

    // 3. Final Check
    if (is_sorted(stack_a) && stack_b == NULL)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);

    // Cleanup
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}