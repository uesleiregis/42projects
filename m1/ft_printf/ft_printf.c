/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 01:15:57 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/25 18:50:55 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// accumulattor(char descriptor, char *position, char *str)
// {
// 	char	**resoults;

// }

int	count_valid_descriptors(char *str, char *descriptors )
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

// int	ft_printf(const char *str, ...)
// {
// 	int		count_var;
// 	char	*s;
// 	va_list	args;
// 	int		i;
	
// 	if(!str)
// 		return (-1);
// 	s = str;
// 	i = 0;
// 	count_vars(s, "csdiiupxX");
	
// 	s = str;

// 	while (i < count_str()) //TODO
// 	{

// 	}
// 	return (count_str()); // retorna o tamanho da string de saída.
// }

#include <stdio.h>
int main(void)
{
	printf("%d", count_valid_descriptors("c%soisa mais%clinda %dmais linda", "csd"));
	return (0);
}
