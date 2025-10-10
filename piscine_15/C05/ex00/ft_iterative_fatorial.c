/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_fatorial.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:20:39 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/11 23:50:25 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int ft_iterative_fatorial(int nb)
{
    int res;

    if(nb <= 0)
        return (0);
    res = 1;
    while(nb > 0)
    {
        res *= nb;
        nb--;
    }
    return (res);
}

int main()
{
    printf("%d", ft_iterative_fatorial(3));
    return (0);
}