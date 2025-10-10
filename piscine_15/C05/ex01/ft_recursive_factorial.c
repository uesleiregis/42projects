/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:57:39 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/12 00:10:46 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int ft_recursive_factorial(int nb)
{
    if(nb < 0)
        return (0);
    if(nb == 1)
        return (1);
    else
        return (nb * ft_recursive_factorial(nb -1));
}

int main()
{
    printf("%d\n", ft_recursive_factorial(6));
    printf("%d\n", ft_recursive_factorial(-1));
    return 0;
}