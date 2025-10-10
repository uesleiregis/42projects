/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:25:31 by uregis-d          #+#    #+#             */
/*   Updated: 2025/08/31 18:47:01 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Exercício 

#include <unistd.h>
#include <stdio.h>

void ft_ft_(int *nbr);
int main(){

    int x = 2;

   ft_ft_(&x);



    printf("%d \n", x);

    return 0;
}


void ft_ft_(int *nbr){
    *nbr = 42;
}

