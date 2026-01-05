/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ueslei <ueslei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:04:28 by ueslei            #+#    #+#             */
/*   Updated: 2026/01/04 16:58:55 by ueslei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_ptr(unsigned long n, int fd)
{
	char	*hex;
	char	c;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		if (ft_putnbr_ptr(n / 16, fd) == -1)
			return (-1);
	}
	c = hex[n % 16];
	return (write(fd, &c, 1));
}

int	ft_print_p(void *ptr, int fd)
{
	unsigned long	addr;
	unsigned long	x;
	int				count;

	if (ptr == NULL)
		return (ft_putstr_fd("(nil)", fd));
	addr = (unsigned long)ptr;
	x = addr;
	if (ft_putstr_fd("0x", fd) == -1)
		return (-1);
	count = 2;
	if (x == 0)
		count++;
	while (x > 0)
	{
		x /= 16;
		count++;
	}
	if (ft_putnbr_ptr(addr, fd) == -1)
		return (-1);
	return (count);
}
