/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercicio2_conta_sinais.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 00:00:00 by uregis-d          #+#    #+#             */
/*   Updated: 2025/12/23 00:00:00 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** EXERCÍCIO 2: conta_sinais
** --------------------------
** Crie uma função que recebe uma quantidade e múltiplos inteiros,
** e retorna quantos são POSITIVOS, NEGATIVOS e ZEROS através de
** ponteiros passados como parâmetros.
**
** Protótipo:
**   void conta_sinais(int *pos, int *neg, int *zeros, int count, ...);
**
** Exemplo de uso:
**   int positivos, negativos, zeros;
**   conta_sinais(&positivos, &negativos, &zeros, 5, -3, 0, 7, -1, 10);
**   // positivos = 2, negativos = 2, zeros = 1
**
** Conceitos revisados:
**   - va_list com parâmetros fixos antes de "..."
**   - Uso de ponteiros para retornar múltiplos valores
**   - Lógica de comparação dentro do loop variático
**   - Similar ao que você fez em maior_num.c
*/

#include <stdarg.h>
#include <stdio.h>

void	conta_sinais(int *pos, int *neg, int *zeros, int count, ...)
{
	// TODO: Implemente aqui
	// Inicialize os contadores via ponteiros
	// Use va_list para percorrer os números
	// Incremente o contador correto baseado no sinal
	(void)pos;
	(void)neg;
	(void)zeros;
	(void)count;
}

int	main(void)
{
	int	positivos;
	int	negativos;
	int	zeros;

	conta_sinais(&positivos, &negativos, &zeros, 5, -3, 0, 7, -1, 10);
	printf("Positivos: %d (esperado: 2)\n", positivos);
	printf("Negativos: %d (esperado: 2)\n", negativos);
	printf("Zeros: %d (esperado: 1)\n", zeros);

	printf("\n--- Teste 2 ---\n");
	conta_sinais(&positivos, &negativos, &zeros, 4, 0, 0, 0, 42);
	printf("Positivos: %d (esperado: 1)\n", positivos);
	printf("Negativos: %d (esperado: 0)\n", negativos);
	printf("Zeros: %d (esperado: 3)\n", zeros);

	return (0);
}
