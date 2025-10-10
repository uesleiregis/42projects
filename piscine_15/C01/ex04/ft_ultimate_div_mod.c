/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 01:36:26 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/01 01:41:57 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdio.h>

void ft_ultimate_div_mod(int *a, int*b)
{
    int div, r;
    div = *a/(*b);
    r = *a%(*b);

*a = div;
*b = r;

}

int main()
{
    int a = 13;
    int b = 5;

    ft_ultimate_div_mod(&a, &b);

    printf("res divisao: %d\n", a);
    printf("res resto: %d\n", b);

    return 0;
}