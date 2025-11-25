/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soma_variatica2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:15:20 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/24 19:25:01 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	soma_variatica(int count, ...)
{
	int		i;
	int		sum;
	va_list	args;

	sum = 0;
	i = 0;
	va_start(args, count);
	while (i++ < count)
		sum += va_arg(args, int);
	va_end(args);
	return (sum);
}


int	main(void)
{
	printf("%d\n", soma_variatica(3, 3, 4, 4));
	return (0);
}