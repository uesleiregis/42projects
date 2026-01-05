/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ueslei <ueslei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:04:45 by ueslei            #+#    #+#             */
/*   Updated: 2026/01/04 04:04:46 by ueslei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x_up(unsigned int n, int fd)
{
	unsigned long	x;
	int				count;

	count = 0;
	x = (unsigned long)n;
	if (x == 0)
		count++;
	while (x > 0)
	{
		x /= 16;
		count++;
	}
	if (ft_putnbr_x_up_fd(n, fd) == -1)
		return (-1);
	return (count);
}
