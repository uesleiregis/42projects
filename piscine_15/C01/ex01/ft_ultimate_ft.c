/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:51:34 by uregis-d          #+#    #+#             */
/*   Updated: 2025/08/31 19:27:13 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void    ft_ultimate_ft(int *********nbr);

int main(){

    int x;
    int *p;
    int **p1;
    int ***p2;
    int ****p3;
    int *****p4;
    int ******p5;
    int *******p6;
    int ********p7;
    int *********p8;

p = &x;
p1 = &p;
p2 = &p1;
p3 = &p2;
p4 = &p3;
p5 = &p4;
p6 = &p5;
p7 = &p6;
p8 = &p7;

x = 2;

ft_ultimate_ft(p8);

printf("x = %d\n", x);


    return 0;
}

void    ft_ultimate_ft(int *********nbr){
    *********nbr = 42;
}

