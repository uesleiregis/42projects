#include <stdarg.h>
int protudo_numeros(int max, ...)
{
    int     i;
    int     p;
    va_list args;
    va_start(args, max);
    i = 0;
    p = 1;
    while (i < max)
    {
        p *= va_arg(args, int);
        i++;
    }
    return (p);
}

#include <stdio.h>
int main(void)
{
    printf("%d", produto_numeros(4, 2,3,4, 2));
    va_end(args);
    return (0);
}