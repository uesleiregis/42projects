/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:03:15 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/06 21:05:05 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstclear(t_list **lst, void (*del)(void *))
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*new_node;

	new_list = NULL;
	current = NULL;
	while (lst)
	{
		new_node = malloc(sizeof(*new_node));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node -> content = f(lst -> content);
		new_node -> next = NULL;
		if (!new_list)
			new_list = new_node;
		else
			current -> next = new_node;
		current = new_node;
		lst = lst -> next;
	}
	return (new_list);
}
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list = NULL;       // Ponteiro para a nova lista.
	t_list	*current = NULL;        // o nó atual em cada iteração de new_list
	t_list	*new_node;

	while (lst)
	{
		// Cria o novo nó que terá o conteúdo transformado - resultado de f
		new_node = malloc(sizeof(*new_node));
		if (!new_node)
		{
			// Se a alocação do novo nó falhar, deleto toda a nova lista
			ft_lstclear(&new_list, del);
			return (NULL);
		}
	new_node -> content = f(lst -> content);
	new_node -> next = NULL;
	// Se for o primeiro nó, inicializa a nova lista.
	if(!new_list)
		new_list = new_node;
	else
    		current -> next = new_node;
	current = new_node;         // Atualiza o ponteiro para o último nó
	lst = lst -> next;          // Avança na lista original
    	}
	return (new_list);    // Retorna o início da nova lista.
}
*/
