/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:07:17 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/11 23:15:48 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int my_cmp(char *s1, char *s2);

int main(int ac, char **av)
{
    char a[] = "aaaa";
    char b[] = "caab";
    int x; 
    int y;

    x = my_cmp(a, a); // 0    
    y = my_cmp(a, b); // neg

    printf("%d\n", x); // 0
    printf("%d\n", y); // neg


    
    return (0);
}


// ordena vetor 
// compara a primeira posicao do vetor com o anterior e se for diferente inverte.


// return 0 if is equal, return negative if *s1 cames before in ascii;
int my_cmp(char *s1, char *s2)
{
    while(*s1 || *s2)
    {
        if(*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (0);
}

char **ft_sort(char **src)
{
    char *temp;
    int i = 0;
    int flag = 0;
    if(src[i] != NULL)
        i++;
    else
        return (NULL);
    while(src[i] != NULL )
    {
        if(my_cmp(src[i-1],src[i]) > 0)
        {
            temp = src[i-1];
            src[i-1] = src[i];
            src[i] = temp;
            flag = 1;
        }
        i++;
    }

}

swap