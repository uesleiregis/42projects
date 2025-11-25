/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:00:14 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/06 17:43:53 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (n == 0 || (!dest && !src))
		return (dest);
	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
		ft_memcpy(d, s, n);
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
