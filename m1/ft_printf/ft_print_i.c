/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ueslei <ueslei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:04:25 by ueslei            #+#    #+#             */
/*   Updated: 2026/01/04 04:04:26 by ueslei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_print_i(int n, int fd)
{
	long	x;
	int		count;

    count = 0;
    x = (long)n;
    if(x < 0)
    {
		x = -x;
        count++;
    }
	if(x == 0)
		count++;
    while(x > 0)
    {
		x/=10;
		count++;
    }
	ft_putnbr_fd(n, fd);
    return (count);
}