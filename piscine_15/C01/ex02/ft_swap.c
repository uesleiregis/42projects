/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:27:35 by uregis-d          #+#    #+#             */
/*   Updated: 2025/08/31 19:39:06 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void ft_swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{

    int a;
    int b;

    a = 1;
    b = 2;
    

    ft_swap(&a, &b);

    printf("a: %d, b: %d\n", a, b);

    return 0;
}