/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:04:35 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/16 18:10:20 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

static int	ft_strlen(char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc((ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1));
	if (!str)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

char *concat_strings(int count, ...)
{
    va_list args;
    int     i;
    int     *size;
    char    *res;
    int     soma;

    soma = 0;
    i = 0;
    va_start(args, count);
    size = malloc(sizeof(int) * count);
    // va_copy(args_copy, args);
    va_arg(args, char *);
    while (i < count)
        size[i] = strlen(va_arg(args, char *));
    va_end(args);
    i = 0;
    while (i < count)
        soma += size[i];
    va_start(args, count);
    res = malloc(sizeof(char)* (soma + 1));
    if (!res)
        return (NULL);
	i = 1;
    while (i <= count)
	{
        res = ft_strjoin(res+size[i-1], va_arg(args, char *));
		i++;
	}
    va_end(args);
    return (res);
}

int	main(void)
{
	printf("%s\n", concat_strings(3, "casa", "maca", "banana"));
	return (0);
}