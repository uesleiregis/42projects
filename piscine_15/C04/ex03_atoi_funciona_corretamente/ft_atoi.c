/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:49:58 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/11 15:19:48 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int    ft_atoi (char *str)
{
    int result = 0;
    int signal = 1;
    while((*str >= '\t' && *str <= '\r') || *str == ' ')
        str++;
    while(*str)
    {
        if(*str == '-')
        {
            signal *= -1;
            str++;
        }
        else if(*str == '+')
            str++;
        else // como pode ser um numero sai sem incrementar o ponteiro
            break;
    }
    // calcula os numeros e já para quando encontra
    // outro caractere na sequencia dos numero
    while(*str >= '0' && *str <= '9' && *str ){
        result = result * 10 + (*str - '0');
        str ++;
    }
    return (result * signal);
}

int main(int ac, char *av[])
{
    //  printf("%d\n",ft_atoi("     +++--++-+1230f2")); 
    printf("%d\n",ft_atoi(av[1])); 
    return (0);
}
