/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:45:52 by uregis-d          #+#    #+#             */
/*   Updated: 2025/10/20 14:46:47 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_is_word(char *long_str, char *short_str, size_t max_len)
{
	size_t	i;

	i = 0;
	while (short_str[i] && i < max_len)
	{
		if (short_str[i] == long_str[i])
			i++;
		else
			return (0);
	}
	return (short_str[i] == '\0');
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*b;
	char	*l;

	i = 0;
	b = (char *)big;
	l = (char *)little;
	if (little[i] == '\0')
		return (b);
	while (b[i] && i < len)
	{
		if (b[i] == l[0])
			if (my_is_word(&b[i], l, len - i))
				return (&b[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
    char *long_w  = "essa familia e muito unida";
    char *word = "muito";

    printf("%s", ft_strnstr(long_w, word, 20));
    return (0);
}
*/
