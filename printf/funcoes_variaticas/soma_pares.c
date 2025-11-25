/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soma_pares.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:25:43 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/24 19:44:52 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	soma_pares(int count, ...)
{
	int		sum;
	int		i;
	va_list	args;
	int		value;

	i = 0;
	sum = 0;
	va_start(args, count);
	while (i++ < count)
	{
		value = va_arg(args, typeof(value));
		if (value % 2 == 0)
			sum += value;
	}
	va_end(args);
	return (sum);
}

int	main(void)
{
	printf("%d\n", soma_pares(3, 6, 1, 8));
	return (0);
}