#include "libft.h"
int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t i;

    i = 0;
    while(str1[i] && str2[i])
    {
        if(str1[i] != str2[i])
            return ((unsigned char) str1[i] - (unsigned char)str2[i]);
        i++;
    }
    return (0);
}
#include <stdio.h>
int main()
{
    printf("%d\n", ft_strncmp("casa", "cada", 3));
    return (0);
}
