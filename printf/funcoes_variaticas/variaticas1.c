/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variaticas1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:43:53 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/15 22:06:49 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	soma_numeros(int quant, ...)
{
	va_list		args;
	int			total;
	int			i;
	int			valor;

	i = 0;
	total = 0;
	va_start(args, quant);
	while (i < quant)
	{
		valor = va_arg(args, int);
		total += valor;
		i++;
	}
	va_end(args);
	return (total);
}

int	main(void)
{
	printf("%d\n", soma_numeros(3, 10, 5, 10));
	return (0);
}
