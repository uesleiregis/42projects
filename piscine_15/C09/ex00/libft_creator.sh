#!/bin/sh

# Remove arquivos objeto antigos
rm -f *.o
# Compila arquivos .c em .o
cc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

# Cria a biblioteca estática libft.a
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

# Indexa a biblioteca
ranlib libft.a