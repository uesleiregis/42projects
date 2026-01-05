/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x_up_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ueslei <ueslei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:06:06 by ueslei            #+#    #+#             */
/*   Updated: 2026/01/04 17:00:44 by ueslei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_x_up_fd(unsigned int n, int fd)
{
	char	*hex;
	char	c;

	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		if (ft_putnbr_x_up_fd(n / 16, fd) == -1)
			return (-1);
	}
	c = hex[n % 16];
	return (write(fd, &c, 1));
}
