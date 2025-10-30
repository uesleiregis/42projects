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