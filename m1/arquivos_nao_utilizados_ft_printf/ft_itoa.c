/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:08:03 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:05:59 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_digits(long n)
{
	int	size;

	size = 1;
	while (n / 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	int		signal;
	long	n2;

	signal = (n < 0);
	n2 = n;
	if (signal)
		n2 = -n2;
	size = count_digits(n2);
	res = malloc((size + signal + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[size + signal] = '\0';
	if (signal)
		res[0] = '-';
	while (size--)
	{
		res[size + signal] = (n2 % 10) + '0';
		n2 /= 10;
	}
	return (res);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%s\n", ft_itoa(-124));
	return (0);
}
*/
