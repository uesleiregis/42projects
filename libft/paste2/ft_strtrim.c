#include "libft.h"

static int ft_strlen(char *str)
{
    int count = 0;
    
    while(*str != '\0')
	{
        str ++;
        count ++;
	}
	return (count);
}

static int in_set(char c, const char *set)
{
    while (*set)
    {
        if (*set == c)
            return (1);
        set++;
    }
    return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *s;
    int     i;
    int     start;
    int     end;
    
    start = 0;
    if (!s1 || !set)
        return (NULL);
    while (s1[start] && in_set(s1[start], set))
        start++;
    end = ft_strlen((char *) s1);
    while (end > start && in_set(s1[end - 1], set))
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

#include <stdio.h>

int main()
{ // tentar passar na Francinete na 42. Ainda há algumas melhorias a fazer.

    char    *temp;

    printf("%s\n", (temp = ft_strtrim("......Olá.....", " .")));
    free(temp);
    return (0);
}