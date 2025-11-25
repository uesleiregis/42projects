/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:47:37 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/07 13:42:02 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	char	*p;
	size_t	substr_len;

	if (!s)
		return (NULL);
	if (start >= (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	substr_len = ft_strlen(s) - start;
	if (substr_len > len)
		substr_len = len;
	p = (char *)malloc(sizeof(char) * (substr_len + 1));
	if (!p)
		return (NULL);
	str = (char *)(s + start);
	i = 0;
	while (str[i] && i < substr_len)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
//#include <stdio.h>
//int main()
//{
// ft_substr
// *s »» string maior
// start »» valor inteiro
// função retorna uma string com os caracteres de *s a partir da 
// posição start da string. 
// len »» é o tamanho máximo dessa nova string (para no fim de s
// ou no tamanho máximo de len)

//	printf("%s", ft_substr("Mamae eu quero", 0, 0));
//	printf("%s", ft_substr("Mamae eu quero", 1, 0));
	// printf("%s", ft_substr("Mamae eu quero", 6, 4));
//	write(1,"\n",1);
//	printf("%s", ft_substr("Mamae eu quero", 2, 6));
	// write(1,"\n",1);
//	return (0);
//}
