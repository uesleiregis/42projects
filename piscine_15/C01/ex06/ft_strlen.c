
#include<stdio.h>

int ft_strlen(char *str)
{

    int count = 0;

    while( *str != '\0'){
        str ++;
        count ++;
    }
    return (count);
}

int main()
{
    char nome[]= "Maria";
    char *p = nome;

printf("%d", ft_strlen(p));

    return (0);
}