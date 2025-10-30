#include "libft.h"

void ft_lstclear(t_list **lst, void(*del)(void *))
{
    t_list  *temp;
    t_list  *actual;
    
    temp = *lst;
    if(!lst || !*lst)
        return;
    while(temp)
    {
        del(temp -> content);
        actual = temp;
        temp = temp -> next;
        free(actual);
    }
    *lst = NULL; 
}