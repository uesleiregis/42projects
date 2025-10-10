/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:09:09 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/11 19:13:54 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
// #include<stdio.h>
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

int main(int ac, char **av)
{
    //printf("%s\n",av[0]);
    write(1, *av, my_lenght(*av));
    write(1,"\n",1);
    return (0);
}
