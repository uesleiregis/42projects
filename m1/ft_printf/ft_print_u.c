/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ueslei <ueslei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:04:34 by ueslei            #+#    #+#             */
/*   Updated: 2026/01/04 04:04:35 by ueslei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_print_u(unsigned int n, int fd)
{
	unsigned long	x;
	int		count;

    count = 0;
    x = (unsigned long)n;
	if(x == 0)
		count++;
  while(x > 0)
  {
		x/=10;
		count++;
  }
	ft_putnbr_u_fd(n, fd);
    return (count);
}