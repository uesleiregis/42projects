/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:41:18 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/20 17:45:33 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*x;
	unsigned char	*p;
	size_t			i;

	x = malloc(nmemb * size);
	if (x == NULL)
		return (NULL);
	p = (unsigned char *)x;
	i = 0;
	while (i < size * nmemb)
	{
		p[i] = '\0';
		i++;
	}
	return (x);
}
