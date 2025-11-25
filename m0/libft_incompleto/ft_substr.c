/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:47:37 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/23 12:49:22 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	str = (char *)(s + start);
	i = 0;
	while (str[i] && i < len)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
// #include <stdio.h>
// int main()
// {
//     // ft_substr
// 	// *s »» string maior
// 	// start »» valor inteiro
// 	// função retorna uma string com os caracteres de *s a partir da 
// 	// posição start da string. 
// 	// len »» é o tamanho máximo dessa nova string (para no fim de s
// 	// ou no tamanho máximo de len)

// 	printf("%s", ft_substr("Mamae eu quero", 6, 4));

// 	return (0);
// }
