#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;
    
    printf("=== Teste com ponteiros NULL ===\n");
    ret1 = printf(" %p %p ", (void *)0, (void *)0);
    printf("\nRetorno printf: %d\n", ret1);
    
    ret2 = ft_printf(" %p %p ", (void *)0, (void *)0);
    printf("\nRetorno ft_printf: %d\n", ret2);
    
    return 0;
}
