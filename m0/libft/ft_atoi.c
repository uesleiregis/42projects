/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:11:21 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/20 16:16:03 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	char	*p;
	int		signal;
	int		res;

	res = 0;
	signal = 1;
	p = (char *)nptr;
	while (*p)
	{
		if ((*p >= '\t' && *p <= '\r') || (*p == ' '))
			p++;
		else
			break ;
	}
	if (*p == '-')
		signal *= (-1);
	if (*p == '+' || *p == '-')
		p++;
	while (*p >= '0' && *p <= '9')
	{
		res = res * 10 + (*p - '0');
		p++;
	}
	return (res * signal);
}
/*
#include <stdio.h>
int main()
{
    printf("%d",ft_atoi("   -00235abc"));
    return (0);
}
*/
