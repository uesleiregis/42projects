/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:37:34 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/20 18:11:45 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int static	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (p == NULL)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
