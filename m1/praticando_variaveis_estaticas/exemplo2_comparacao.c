/* ************************************************************************** */
/*                                                                            */
/*   Exemplo 2: Comparação entre variável local e estática                    */
/*                                                                            */
/*   Este exemplo mostra lado a lado a diferença de comportamento             */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	funcao_com_local(void)
{
	int	local = 0;  // Criada e destruída a cada chamada

	local++;
	printf("Variável LOCAL:   %d\n", local);
}

void	funcao_com_estatica(void)
{
	static int	estatica = 0;  // Criada uma vez, persiste sempre

	estatica++;
	printf("Variável ESTÁTICA: %d\n", estatica);
}

int	main(void)
{
	int	i;

	printf("=== Comparação: Local vs Estática ===\n\n");
	
	i = 0;
	while (i < 5)
	{
		printf("--- Chamada %d ---\n", i + 1);
		funcao_com_local();
		funcao_com_estatica();
		printf("\n");
		i++;
	}
	return (0);
}

/*
** SAÍDA ESPERADA:
** =======================================
** --- Chamada 1 ---
** Variável LOCAL:   1
** Variável ESTÁTICA: 1
**
** --- Chamada 2 ---
** Variável LOCAL:   1    <-- Sempre 1! Reinicializada.
** Variável ESTÁTICA: 2    <-- Incrementa! Mantém o valor.
**
** --- Chamada 3 ---
** Variável LOCAL:   1
** Variável ESTÁTICA: 3
**
** E assim por diante...
*/
