/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maior_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:07:36 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/24 19:46:52 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	maior_num(int quant, ...)
{
	va_list	args;
	int		maior;
	int		i;
	int		valor;

	i = 0;
	maior = -1000;
	va_start(args, quant);
	while (i++ < quant)
	{
		valor = va_arg(args, int);
		if (valor > maior)
			maior = valor;
	}
	if (maior == -1000)
		return (0);
	va_end(args);
	return (maior);
}

int	main(void)
{
	printf("%d\n", maior_num(4, 1, 20, 7, 9));
	return (0);
}
