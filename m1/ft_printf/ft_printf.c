/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 01:15:57 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/28 00:59:42 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_valid_descriptors(char *str, char *descriptors )
{
	int	count;

	count = 0;
	if (!str || !descriptors)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == '\0')
				break ;
			if (*(str + 1) == '%')
			{
				str += 2;
				continue ;
			}
			if (ft_strchr(descriptors, *(str + 1)))
				count++;
			str += 2;
			continue ;
		}
		str++;
	}
	return (count);
}

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
	if(c == 'c')
		return (ft_print_c((char)va_arg(list, int), fd));
	else if(c == 's')
		return (ft_print_s(va_arg(list, char *),fd));
	else if(c == 'p')
		return (ft_print_p(va_arg(list, void *), fd));
	else if(c == 'd')
		return (ft_print_d(va_arg(list, int), fd));
	else if(c == 'i')
		return (ft_print_i(va_arg(list, int), fd));
	else if(c == 'u')
		return (ft_print_u(va_arg(list, unsigned int), fd));
	else if(c == 'x')
		return (ft_print_x(va_arg(list, unsigned int), fd));
	else if(c == 'X')
		return (ft_print_x_up(va_arg(list, unsigned int), fd));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	//int		count_var;
	va_list	args;
	int		i;
	int		count_chars;

	va_start(args, str);
	count_chars = 0;
	i = 0;
	if (!str || !str_is_valid(str))
		return (-1);
	i = 0;
	//count_var = count_valid_descriptors((char *)str, "cspdiuxX");
	while (str[i])
	{
		if(str[i] && str[i] != '%')
		{
			ft_putchar_fd(str[i], FD);
			count_chars++;
		}
		else
		{
			if (str[i + 1] == '\0')
				break ;
			if (str[i + 1] == '%')
			{
				i += 2;
				continue ;
			}
			if (ft_strchr("cspdiuxX", str [i + 1]))
				count_chars += ft_print_args_fd(str[++i], args, FD);
			i += 2;
			continue ;
		}
		i++;
	}
	va_end(args);
	return (count_chars); // retorna o tamanho da string de saída.
}

/* #include <stdio.h>
int main(void)
{
	ft_printf("Teste");
	printf("%d", count_valid_descriptors("c%soisa mais%clinda %dmais linda", "csd"));
	return (0);
} */
