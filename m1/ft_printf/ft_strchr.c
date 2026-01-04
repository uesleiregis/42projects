/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:01:29 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/20 11:43:50 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	char	*p;

	p = (char *)str;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if ((char)c == '\0' )
		return (p);
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char *world = "que coisa mais linda mais cheia de graça";

	printf("%s\n",ft_strchr(world, 'c'));
	return (0);
}
*/
