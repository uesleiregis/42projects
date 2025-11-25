/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produto_numeros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:35:10 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/24 19:48:31 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int produto_numeros(int count, ...)
{
    va_list args;
    int     i;
    int     produto;

    i = 0;
    produto = 1;
    va_start(args, count);
    while (i++ < count)
        produto *= va_arg(args, int);
    va_end(args);
    return (produto);
}

int main(void)
{
    printf("%d\n", produto_numeros(3, 2, 2, 5));
    return (0);
}