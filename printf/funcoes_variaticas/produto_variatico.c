/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produto_variatico.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:29:46 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/16 16:32:32 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	produto_variatico(int count, ...)
{
	va_list	args;
	int		produto;
	int		i;

	produto = 1;
	i = 0;
	va_start(args, count);
	while (i++ < count)
		produto *= va_arg(args, int);
	va_end(args);
	return (produto);
}

int	main(void)
{
	printf("%d\n", produto_variatico(4, 2, 2, 2, 3));
	return (0);
}
