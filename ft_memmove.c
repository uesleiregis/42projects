/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:00:14 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/20 11:37:35 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;
	unsigned char		*temp;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	temp = (unsigned char *)malloc(n);
	if (!temp)
		return (NULL);
	while (i < n)
	{
		temp[i] = s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d[i] = temp[i];
		i++;
	}
	free(temp);
	return (dest);
}
/*
#include <stdio.h>
int main()
{
    char t1[15] = "Mamae eu quero";
    char t2[15] = "Mamae eu quero";

    ft_memmove(t1 + 5, t1, 5);

    // t1[12] = '\0'; // por causa do printf
    printf("%s\n", t1);
    return (0);
}
*/
