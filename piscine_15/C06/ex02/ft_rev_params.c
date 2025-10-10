/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:53:07 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/11 20:05:04 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int my_lenght(char *str);

#include<unistd.h>

int main(int ac, char *av[])
{
    int i;

    i = ac-1;
    while( i > 0)
    {
        write(1,av[i], my_lenght(av[i]));
        write(1,"\n",1);
        i--;
    }
    return (0);
}

int my_lenght(char *str)
{
    int count = 0;
    while(*str)
    {
        str++;
        count ++;
    }
    return (count);
}