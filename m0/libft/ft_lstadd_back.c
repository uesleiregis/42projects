/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:04:26 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/07 13:42:29 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while ((temp -> next != NULL))
		temp = temp -> next;
	temp -> next = new;
}
/*
#include <stdio.h>
int     main(void)
{
        t_list  a;
        t_list  b;
        t_list  c;
        t_list  d;
        t_list  *current;

        a.next = &b;
        b.next = &c;
        c.next = NULL;
        d.next = NULL;
        a.content = "Felipe";
        b.content = "Jose";
        c.content = "Hillebrand";
        d.content = "Ferreira";
        current = &a;
        ft_lstadd_back(&current, &d);
        while (current != NULL)
        {
                printf("%s ", (char *)current->content);
                current = current->next;
        }
        printf("\n");
        return (0);
}
*/