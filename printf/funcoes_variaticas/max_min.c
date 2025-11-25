/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:27:14 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/24 23:33:28 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	max_min(int *max, int *min, int count, ...)
{
	int		i;
	va_list	args;
	int		big;
	int		littte;
	int		value;

	i = 0;
	big = -1000;
	littte = 1000;
	va_start(args, count);
	while (i++ < count)
	{
		value = va_arg(args, int);
		if (value > big)
			big = value;
		else if (value < littte)
			littte = value;
	}
	*max = big;
	*min = littte;
}

int	main(void)
{
	int	maior;
	int	menor;

	max_min(&maior, &menor, 5, 4, 5, 2, 8, 5);
	printf("Maior: %d - Menor: %d\n", maior, menor);
	return (0);
}