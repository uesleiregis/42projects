/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:59:20 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/23 17:12:27 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		str[i++];
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}
