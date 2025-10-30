#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *temp;
    temp = *lst;
    if(!new)
        return;
    if(!(*lst))
    {
        // se a lista estiver vazia, new passa a ser o primeiro nó.
        *lst = new;
        return;
    }    
    while((temp -> next != NULL))
    {
        temp = temp -> next;
    }
    temp -> next = new;
    new -> next = NULL;
}