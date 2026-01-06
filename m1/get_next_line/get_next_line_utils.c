/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ueslei <ueslei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 00:00:00 by uregis-d          #+#    #+#             */
/*   Updated: 2026/01/06 23:56:03 by ueslei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Counts how many chars in the string.
*/
int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
** Makes a copy of string s in new memory.
*/
char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (p == NULL)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*
** Looks for char c in str. Returns pointer to it or NULL.
*/
char	*ft_strchr(const char *str, int c)
{
	char	*p;

	if (!str)
		return (NULL);
	p = (char *)str;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if ((char)c == '\0')
		return (p);
	return (NULL);
}

/*
** Like strdup but only copies n chars max.
*/
char	*ft_strndup(const char *s, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (n + 1));
	if (p == NULL)
		return (NULL);
	while (s[i] && i < n)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*
** Joins s1 and s2 together. Handles s1 being NULL.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
