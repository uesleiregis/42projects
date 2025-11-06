/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:03:49 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/06 21:04:59 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*actual;

	temp = *lst;
	if (!lst || !*lst)
		return ;
	while (temp)
	{
		del(temp -> content);
		actual = temp;
		temp = temp -> next;
		free(actual);
	}
	*lst = NULL;
}
