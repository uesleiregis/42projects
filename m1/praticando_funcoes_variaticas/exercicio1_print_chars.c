/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercicio1_print_chars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 00:00:00 by uregis-d          #+#    #+#             */
/*   Updated: 2025/12/23 00:00:00 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** EXERCÍCIO 1: print_chars
** -------------------------
** Crie uma função que recebe uma quantidade e múltiplos caracteres,
** e imprime cada caractere seguido de um espaço.
** A função deve RETORNAR o número total de caracteres impressos
** (incluindo os espaços).
**
** IMPORTANTE para ft_printf: Em funções variáticas, char é promovido
** para int! Use va_arg(args, int) mesmo para caracteres.
**
** Protótipo:
**   int print_chars(int count, ...);
**
** Exemplo de uso:
**   int printed = print_chars(4, 'H', 'O', 'L', 'A');
**   // Saída esperada: "H O L A "
**   // Retorno: 8 (4 chars + 4 espaços)
**
** Conceitos revisados:
**   - va_list, va_start, va_arg, va_end
**   - Promoção de tipos (char -> int)
**   - Contagem de caracteres impressos (essencial para ft_printf!)
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	print_chars(int count, ...)
{
	// TODO: Implemente aqui usando va_list
	// Lembre-se: use va_arg(args, int) para pegar char!
	// Retorne o total de caracteres impressos

    va_start(count, args);


	(void)count;
	return (0);
}

int	main(void)
{
	int	total;

	total = print_chars(4, 'H', 'O', 'L', 'A');
	printf("\nTotal impresso: %d (esperado: 8)\n", total);

	total = print_chars(3, '4', '2', '!');
	printf("\nTotal impresso: %d (esperado: 6)\n", total);

	return (0);
}
