/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:04:03 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:10:09 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*p;
	char	*res;

	res = NULL;
	p = (char *)str;
	while (*p)
	{
		if (*p == (char)c)
			res = p;
		p++;
	}
	if ((char)c == '\0')
		return (p);
	return (res);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%s",strrchr("mamae eu quero", 'm'));
// 	return (0);
// }
