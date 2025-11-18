#include "push_swap.h"

t_stack	*ft_lstnew(int value)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->next = NULL;
    new->prev = NULL;
    new->value = value;
    return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

int		ft_lstsize(t_stack *lst)
{
    int i;

    i = 0;
    while (lst)
    {    
        i++;
        lst = lst->next;
    }
    return (i);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
    if (!lst || !new)
        return ;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
    new->next = *lst;
    new->prev = NULL;
    (*lst)->prev = new;
    *lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
    t_stack *last;
    if (!lst || !new)
        return ;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
    last = ft_lstlast(*lst);
    new->next = NULL;
    new->prev = last;
    last->next = new;
}

void	ft_lstclear(t_stack **lst)
{
    t_stack *tmp;

    if (!lst || !*lst)
        return ;
    while (*lst)
    {
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp);
    }
    *lst = NULL;
}

void init_stack(t_stack **lst, char **av, int size)
{
    t_stack *new;
    int i = 0;

    while (i < size)
    {
        new = ft_lstnew(atoi(av[i]));
        ft_lstadd_back(lst, new);
        i++;
    }
}
