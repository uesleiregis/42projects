/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ueslei <ueslei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:48:11 by uregis-d          #+#    #+#             */
/*   Updated: 2026/01/04 17:00:46 by ueslei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		n *= -1;
	}
	if (n >= 10)
	{
		if (ft_putnbr_fd(n / 10, fd) == -1)
			return (-1);
	}
	c = (n % 10) + '0';
	return (write(fd, &c, 1));
}
// int main(void)
// {
//     ft_putnbr_fd(137, 1);
//     return (0);
// }
