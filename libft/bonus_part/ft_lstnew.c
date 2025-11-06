/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:03:07 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/06 21:05:06 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*node;
// 	node = malloc(sizeof(t_list));
// 	if(!node)
// 		return (NULL);
// 	(char *)node->content = (char)content;
// 	return (node->next);
// }

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;
	node = malloc(sizeof(*node));
	if(!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}