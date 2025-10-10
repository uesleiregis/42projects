/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:56:59 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/18 21:39:30 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i;

    if(min >= max)
    {
        *range = NULL;
        return (0);
    }
    *range = (int *)malloc((max-min)*sizeof(int));
    if(*range == NULL)
        return (-1);

    i = 0;
    while( i + min < max)
    {
        (*range)[i] = min + i;
        i++; 
    }
    return (max - min);
}