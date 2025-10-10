/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:15:53 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/05 13:25:32 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n){
    int temp = 0;
    int i=1;
    while(*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && i < n){
        s1++;
        s2++;
        i++;
    }
    temp = *s1 - *s2;
    return (temp);
}

int main(){
    char nome1[] = "aaa";
    char nome2[] = "aab";
    char nome3[] = "aab";

    int a= ft_strncmp(nome1, nome2,2); // igual
    int b= ft_strncmp(nome2, nome1,2); // positivo
    int c= ft_strncmp(nome2, nome3,2); // igual

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);

    return 0;
}
