/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   media_reais.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:43:03 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/16 17:04:14 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

double   calc_media(int count, ...)
{
    va_list args;
    int     i;
    double   media;
    
    media = 0;
    i = 0;
    if(count == 0)
        return (0);
    va_start(args, count);
    while(i++ < count)
        media += va_arg(args, double);
    media /= count;
    va_end(args);
    return (media);
}

int main(void)
{
    printf("%f\n", calc_media(3.0, 3.0, 5.0, 7.0));
    return (0);
}