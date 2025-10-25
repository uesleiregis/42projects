/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:48:11 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/23 17:17:05 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	temp[100];
	int		count;

	count = 0;
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	while (n != 0)
	{
		temp[count++] = ('0' + (n % 10));
		n /= 10;
	}
	while (count > 0)
		write (fd, &temp[--count], 1);
}
// int main(void)
// {
//     ft_putnbr_fd(137, 1);
//     return (0);
// }
