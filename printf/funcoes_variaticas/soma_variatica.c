/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soma_variatica.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:14:52 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/24 19:45:18 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	soma_variatica(int count, ...)
{
	va_list	args;
	int		soma;
	int		i;

	i = 0;
	soma = 0;
	va_start(args, count);
	while (i++ < count)
		soma += va_arg(args, int);
	va_end(args);
	return (soma);
}

int	soma_variatica2(int count, ...)
{
	va_list	args;
	int		sum;
	int		i;

	i = 0;
	sum = 0;
	va_start(args, count);
	while (i++ < count)
		sum += va_arg(args, int);
	va_end(args);

	return (sum);
}


int	main(void)
{
	printf("A soma é %d\n", soma_variatica2(3, 11, 15, 22));
	return (0);
}
