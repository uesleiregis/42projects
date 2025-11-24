/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soma_variatica.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:14:52 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/16 16:18:27 by uregis-d         ###   ########.fr       */
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

int	main(void)
{
	printf("A soma é %d\n", soma_variatica(3, 10, 15, 22));
	return (0);
}
