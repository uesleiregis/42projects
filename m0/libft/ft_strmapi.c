/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:38:46 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/06 12:51:27 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = malloc(sizeof(char) * (1 + ft_strlen((char *) s)));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
// char teste(unsigned int i, char c)
// {
// 	return (c+1);
// }
// #include <stdio.h>
// int main()
// {
// 	char word[] = "isso e um teste";
// 	char *res = ft_strmapi(word, teste);
// 	printf("%s\n", res);
// 	free(res);
// 	return (0);
// }
