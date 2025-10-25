/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:55:18 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/25 23:04:09 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen(const char *str);
static int	my_count_words(const char *str, char c);
char	*str_chr_dup(const char *s, char set);
static void	my_next_str_start(const char *str, unsigned int *start, char c);
char **ft_split(char const *s, char c);

#include <stdio.h>
#include <unistd.h>
int main()
{
    char **temp = ft_split("Mamae-eu quero-me casar", '-');
    int i = 0;
    while(temp[i])
    {
        printf("%s\n",temp[i]);
        i++;
    }

	// Free the memory
	i = 0;
	while(temp[i])
    {
        free(temp[i]);
        i++;
    }

    return (0);
}

char **ft_split(char const *s, char c)
{
	int 	n_words;
	char	**res;
	int		i;
	int		start;

	i = 0;
	start = 0;
	n_words = my_count_words(s, c);
	res = malloc(sizeof(char *) * (n_words + 1));
	if(!res)
		return (NULL);
	while(i < n_words)
	{
		my_next_str_start(s, &start, c);
		res[i] = str_chr_dup(&s[start], c);
	}
}


static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	my_count_words(const char *str, char c)
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

static void	my_next_str_start(const char *str, unsigned int *start, char c)
{
	int		i;
	
	i = 0;
	if (!str)
		return ;
	if (str[i] && str[i] != c)
	{
		*start = i;
		return ;
	}
	while(str[i] == c)
		i++;
	*start = 0;
	return ;
}

char	*str_chr_dup(const char *s, char set)
{
	char	*p;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if(!s)
		return (NULL);
	while(s[i] && s[i] != set)
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		p[j] = s[j];
		j++;
	}
	p[i] = '\0';
	return (p);
}
