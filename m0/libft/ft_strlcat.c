/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:19:47 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:53:15 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
// #include<bsd/string.h>

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;

	lendest = 0;
	while (lendest < size && dest[lendest])
		lendest++;
	if (lendest == size)
		return (size + ft_strlen(src));
	i = lendest;
	while (*src && i < (size - 1))
	{
		dest[i] = *src;
		src++;
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
/*
int main()
{
    char src[] = "porto";
    char dest[] = "42";
	char src2[] = "porto";
    char dest2[] = "42";
	unsigned int n = 2;
    ft_strlcat(dest, src, n);
    printf("%s\n%s\n", dest, dest2);
    return (0);
}
*/
