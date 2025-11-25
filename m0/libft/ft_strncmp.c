/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:02:51 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/05 20:13:25 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (str1[i] && str2[i] && i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char) str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char) str1[i] - (unsigned char)str2[i]);
	return (0);
}
// #include <stdio.h>
// int main()
// {
//     printf("%d\n", ft_strncmp("casa", "cada", 3));
//     return (0);
// }
