/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:00:32 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/20 11:40:03 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
// #include <stdio.h>
// int main()
// {
//     char buffer[10];
//     size_t  i;

//     i = 0;

//     ft_memset(buffer, 'A', sizeof(buffer));

//     while( i < sizeof(buffer))
//     {
//         printf("%02X\n",(unsigned char)buffer[i]);
//         i++;
//     }
//     return (0);
// }
