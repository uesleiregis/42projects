/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercicio3_mini_printf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 00:00:00 by uregis-d          #+#    #+#             */
/*   Updated: 2025/12/23 00:00:00 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** EXERCÍCIO 3: mini_printf (PREPARAÇÃO DIRETA PARA ft_printf!)
** -------------------------------------------------------------
** Crie um mini printf que suporta apenas 3 especificadores:
**   %c - imprime um caractere
**   %s - imprime uma string
**   %% - imprime o caractere '%'
**
** A função deve RETORNAR o número total de caracteres impressos.
**
** Protótipo:
**   int mini_printf(const char *format, ...);
**
** Exemplo de uso:
**   int n = mini_printf("Ola %s! Nota: %c%%\n", "42", 'A');
**   // Saída: "Ola 42! Nota: A%\n"
**   // Retorno: 18
**
** DICAS:
**   1. Percorra a string format caractere por caractere
**   2. Se encontrar '%', verifique o próximo char para saber o tipo
**   3. Use va_arg com o tipo correto:
**      - %c: va_arg(args, int)  <-- char é promovido para int!
**      - %s: va_arg(args, char *)
**   4. Conte TODOS os caracteres impressos
**
** Conceitos revisados:
**   - Tudo que você praticou até agora!
**   - Parsing de format string (core do ft_printf)
**   - Tipos diferentes no mesmo va_list
**   - Contagem de output (retorno do ft_printf)
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

// Função auxiliar para imprimir string e retornar tamanho
int	print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	mini_printf(const char *format, ...)
{
	// TODO: Implemente aqui
	// 1. Declare va_list e inicialize com va_start
	// 2. Percorra format com um while
	// 3. Se char atual == '%':
	//    - Verifique o próximo: 'c', 's' ou '%'
	//    - Use va_arg para pegar o argumento (se necessário)
	//    - Imprima e conte os caracteres
	// 4. Senão: imprima o char normal e conte
	// 5. va_end e retorne o total
	(void)format;
	return (0);
}

int	main(void)
{
	int	ret;
	int	expected;

	printf("=== TESTE 1 ===\n");
	printf("Esperado: Ola 42!\n");
	printf("Seu mini: ");
	ret = mini_printf("Ola %s!", "42");
	printf("\nRetorno: %d (esperado: 7)\n\n", ret);

	printf("=== TESTE 2 ===\n");
	printf("Esperado: Char: A\n");
	printf("Seu mini: ");
	ret = mini_printf("Char: %c", 'A');
	printf("\nRetorno: %d (esperado: 8)\n\n", ret);

	printf("=== TESTE 3 ===\n");
	printf("Esperado: 100%% completo\n");
	printf("Seu mini: ");
	ret = mini_printf("100%% completo");
	printf("\nRetorno: %d (esperado: 13)\n\n", ret);

	printf("=== TESTE 4 (COMPLETO) ===\n");
	expected = printf("Real:     Ola %s! Nota %c = 100%%\n", "mundo", 'A');
	printf("Seu mini: ");
	ret = mini_printf("Ola %s! Nota %c = 100%%\n", "mundo", 'A');
	printf("Retorno: %d (esperado: %d)\n", ret, expected);

	return (0);
}
