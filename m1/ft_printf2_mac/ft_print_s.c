/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ueslei <ueslei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:04:31 by ueslei            #+#    #+#             */
/*   Updated: 2026/01/04 04:04:32 by ueslei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s, int fd)
{
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (ft_putstr_fd(s, fd) == -1)
		return (-1);
	return (len);
}
