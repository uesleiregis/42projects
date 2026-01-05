#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int num = 42;

    printf("\n===== TESTE COMPLETO ft_printf =====\n\n");

    // %c - Prints a single character
    printf("--- %%c (char) ---\n");
    printf("printf:    [%c]\n", 'A');
    ft_printf("ft_printf: [%c]\n", 'A');

    // %s - Prints a string
    printf("\n--- %%s (string) ---\n");
    printf("printf:    [%s]\n", "Hello World");
    ft_printf("ft_printf: [%s]\n", "Hello World");
    printf("printf:    [%s]\n", (char *)NULL);
    ft_printf("ft_printf: [%s]\n", (char *)NULL);

    // %p - Prints pointer in hexadecimal
    printf("\n--- %%p (pointer) ---\n");
    printf("printf:    [%p]\n", &num);
    ft_printf("ft_printf: [%p]\n", &num);
    printf("printf:    [%p]\n", (void *)NULL);
    ft_printf("ft_printf: [%p]\n", (void *)NULL);

    // %d - Prints decimal (base 10)
    printf("\n--- %%d (decimal) ---\n");
    printf("printf:    [%d]\n", 42);
    ft_printf("ft_printf: [%d]\n", 42);
    printf("printf:    [%d]\n", -42);
    ft_printf("ft_printf: [%d]\n", -42);
    printf("printf:    [%d]\n", 0);
    ft_printf("ft_printf: [%d]\n", 0);

    // %i - Prints integer in base 10
    printf("\n--- %%i (integer) ---\n");
    printf("printf:    [%i]\n", 123);
    ft_printf("ft_printf: [%i]\n", 123);
    printf("printf:    [%i]\n", -123);
    ft_printf("ft_printf: [%i]\n", -123);

    // %u - Prints unsigned decimal
    printf("\n--- %%u (unsigned) ---\n");
    printf("printf:    [%u]\n", 42);
    ft_printf("ft_printf: [%u]\n", 42);
    printf("printf:    [%u]\n", 4294967295U);
    ft_printf("ft_printf: [%u]\n", 4294967295U);

    // %x - Prints hexadecimal lowercase
    printf("\n--- %%x (hex lowercase) ---\n");
    printf("printf:    [%x]\n", 255);
    ft_printf("ft_printf: [%x]\n", 255);
    printf("printf:    [%x]\n", 0);
    ft_printf("ft_printf: [%x]\n", 0);

    // %X - Prints hexadecimal uppercase
    printf("\n--- %%X (hex uppercase) ---\n");
    printf("printf:    [%X]\n", 255);
    ft_printf("ft_printf: [%X]\n", 255);
    printf("printf:    [%X]\n", 42424);
    ft_printf("ft_printf: [%X]\n", 42424);

    // %% - Prints percent sign
    printf("\n--- %%%% (percent) ---\n");
    printf("printf:    [%%]\n");
    ft_printf("ft_printf: [%%]\n");

    printf("\n===== FIM DOS TESTES =====\n");

    return (0);
}
