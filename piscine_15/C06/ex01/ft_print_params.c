/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:18:45 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/11 19:47:11 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int my_lenght(char *str);

int main(int argc, char *argv[])
{
    int count;

    count = 1;
    while(count < argc)
    {
        write(1, argv[count], my_lenght(argv[count]));
        write(1,"\n",1);
        count ++;
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