/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 01:26:44 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/05 13:14:53 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compara s1 e s2 caractere a caractere
// > , < ou =0, s1 e maior, s1 é menor ou são iguais
// para quando encontra algum caractere diferente ou \0
// retorna a - b, sendo a um caractere de s1.
#include<stdio.h>

int ft_strcmp(char *s1, char *s2){
    int temp = 0;
    while(*s1 == *s2 && *s1 != '\0' && *s2 != '\0'){
        s1++;
        s2++;
    }
    temp = *s1 - *s2;
    return (temp);
}
/*
int main(){
    char nome1[] = "a";
    char nome2[] = "b";
    char nome3[] = "b";

    int a= ft_strcmp(nome1, nome2); // positivo
    int b= ft_strcmp(nome2, nome1); // negativo
    int c= ft_strcmp(nome2, nome3); // igual

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);

    return 0;
}
*/
