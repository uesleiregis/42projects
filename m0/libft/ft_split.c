/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:55:18 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/06 13:22:30 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c);
static int	my_count_words(const char *str, char c);
static char	*str_chr_dup(const char *s, char set);
static char	**test_null_and_free(char **res, int i);

/*
#include <stdio.h>
#include <unistd.h>

// Função para liberar o array retornado pelo ft_split
void free_split(char **split_arr)
{
    int i = 0;
    if (!split_arr)
        return;
    while (split_arr[i])
    {
        free(split_arr[i]);
        i++;
    }
    free(split_arr);
}
// Função para imprimir o resultado do split para facilitar visualização
void print_split(char **split_arr)
{
    int i = 0;
    if (!split_arr)
    {
        printf("NULL\n");
        return;
    }
    while (split_arr[i])
    {
        printf("'%s'\n", split_arr[i]);
        i++;
    }
}
int main(void)
{
    char **result;
    // Testes típicos
    printf("Test: \"abc-def-ghi\" com '-'\n");
    result = ft_split("abc-def-ghi", '-');
    print_split(result);
    free_split(result);
    printf("\nTest: string vazia \"\" com '-'\n");
    result = ft_split("", '-');
    print_split(result);
    free_split(result);
    printf("\nTest: apenas delimitadores \"---\" com '-'\n");
    result = ft_split("---", '-');
    print_split(result);
    free_split(result);
    printf("\nTest: delimitador único \"-\" com '-'\n");
    result = ft_split("-", '-');
    print_split(result);
    free_split(result);
    printf("\nTest: string sem delimitador \"abc\" com '-'\n");
    result = ft_split("abc", '-');
    print_split(result);
    free_split(result);
    printf("\nTest: strr c/ del. consecutivos \"abc--def\" com '-'\n");
    result = ft_split("abc--def", '-');
    print_split(result);
    free_split(result);
    printf("\nTest: entrada NULL\n");
    result = ft_split(NULL, '-');
    print_split(result);
    free_split(result);
    return 0;
}
*/
char	**ft_split(char const *s, char c)
{
	char		**res;
	const char	*p;
	int			i;
	int			count_w;

	if (!s)
		return (NULL);
	count_w = my_count_words(s, c);
	res = malloc(sizeof(char *) * (count_w + 1));
	if (!res)
		return (NULL);
	i = 0;
	p = s;
	while (i < count_w)
	{
		while (*p == c && *p)
			p++;
		res[i] = str_chr_dup(p, c);
		if (!res[i++])
			return (test_null_and_free(res, i - 1));
		p += ft_strlen(res[i - 1]);
	}
	res[i] = NULL;
	return (res);
}

static char	**test_null_and_free(char **res, int i)
{
	int	j;

	if (!res)
		return (NULL);
	if (!res[i])
	{
		j = i - 1;
		while (j >= 0)
			free(res[j--]);
		free(res);
		return (NULL);
	}
	return (res);
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

static char	*str_chr_dup(const char *s, char set)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != set)
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
