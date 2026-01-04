/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ueslei <ueslei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 01:15:57 by uregis-d          #+#    #+#             */
/*   Updated: 2026/01/04 17:00:27 by ueslei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_is_valid(const char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == '\0')
				return (0);
			if (!ft_strchr("cspdiuxX%", *(str + 1)))
				return (0);
			str++;
		}
		str++;
	}
	return (1);
}

static int	ft_print_args_fd(char c, va_list list, int fd)
{
	if (c == 'c')
		return (ft_print_c((char)va_arg(list, int), fd));
	else if (c == 's')
		return (ft_print_s(va_arg(list, char *), fd));
	else if (c == 'p')
		return (ft_print_p(va_arg(list, void *), fd));
	else if (c == 'd')
		return (ft_print_d(va_arg(list, int), fd));
	else if (c == 'i')
		return (ft_print_i(va_arg(list, int), fd));
	else if (c == 'u')
		return (ft_print_u(va_arg(list, unsigned int), fd));
	else if (c == 'x')
		return (ft_print_x(va_arg(list, unsigned int), fd));
	else if (c == 'X')
		return (ft_print_x_up(va_arg(list, unsigned int), fd));
	return (0);
}

static int	ft_handle_format(const char *str, int *i, va_list args)
{
	int	count;

	count = 0;
	if (str[*i + 1] == '%')
		count = ft_print_c('%', FD);
	else
		count = ft_print_args_fd(str[*i + 1], args, FD);
	*i += 2;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		ret;

	if (!str || !str_is_valid(str))
		return (-1);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ret = ft_print_c(str[i++], FD);
		else
			ret = ft_handle_format(str, &i, args);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		count += ret;
	}
	va_end(args);
	return (count);
}
