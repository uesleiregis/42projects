#include "libft.h"

static int ft_strlen(char *str)
{
	int i;

    i = 0;
    while(*str)
	{
		str ++;
 		i ++;
	}
	return (i);
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

static char    *ft_strtrim(char const *s1, char const *set)
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

char    **ft_split(char const *s, char c)
{
    char    **res;
    char    *temp;
    char    ch[2];

    int     i = 0;
    ch[0] = c;
    ch[1] = '\0';
    temp = malloc((1 + ft_strlen(s)));
    if(!temp)
        return (NULL);
    // res =(char **)malloc(sizeof(temp) + 1);
    // if(!res)
    //     return (NULL);


    //tratar s com ft_strtrim
    temp = ft_strtrim(s, ch); // o temp anterior deve ser apagado com free()


    //


}