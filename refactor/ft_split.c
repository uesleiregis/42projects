/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:55:18 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/23 18:05:23 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strtrim_char(char const *s1, char const set)
{
	char	*s;
	int		i;
	int		start;
	int		end;

	start = 0;
	if (!s1)
		return (NULL);
	while (s1[start] && s1[start] == set)
		start++;
	end = ft_strlen((char *) s1);
	while (end > start && s1[end - 1] == set)
		end--;
	s = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (start < end)
		s[i++] = s1[start++];
	s[i] = '\0';
	return (s);
}

int	my_count_words(char *str, char c)
{
	int		count_w;
	int		flag;

	flag = 0;
	count_w = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count_w++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count_w);
}


char **ft_split(char const *s, char c)
{
	char	**res;
	char	*s_trim;
	int		i;
	int     start;

	i = 0;
    start = 0;
    s_trim = ft_strtrim_char(s, c);
    if (!s_trim)
        return (NULL);
    res = malloc((my_count_words(s_trim, c) + 1) * sizeof(char *));
    if (!res)
    {
		my_free(1);
        free(s_trim);
        return (NULL);
    }
    while (i < my_count_words(s_trim, c))
    {
        temp = first_word_c(start, s_trim, c);
        if (!temp)
        {
            while (i > 0)
            free(res[--i]);
            free(res);
            free(s_trim);
            return (NULL);
        }
        res[i] = temp;
        start += ft_strlen(temp);
        while (s_trim[start] && s_trim[start] == c)
            start++;
        i++;
    }
    res[i] = NULL;
    free(s_trim);
    return (res);
}
#include <stdio.h>
int main()
{
    char **temp = ft_split("Mamae-eu quero-me casar", '-');
    int i = 0;
    while(temp[i])
    {
        printf("%s\n",temp[i]);
        i++;
    }
    return (0);
}

