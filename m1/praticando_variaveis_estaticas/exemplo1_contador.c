/* ************************************************************************** */
/*                                                                            */
/*   Exemplo 1: Contador com variável estática                                */
/*                                                                            */
/*   Uma variável estática MANTÉM seu valor entre chamadas de função.         */
/*   Diferente de variáveis locais normais, ela não é "zerada" a cada chamada */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	contador(void)
{
	static int	vezes = 0;  // Inicializada apenas UMA vez!

	vezes++;
	printf("Esta função foi chamada %d vez(es)\n", vezes);
}

int	main(void)
{
	printf("=== Exemplo de Contador ===\n\n");
	
	contador();  // vezes = 1
	contador();  // vezes = 2
	contador();  // vezes = 3
	contador();  // vezes = 4
	contador();  // vezes = 5
	
	printf("\nObserve: o valor de 'vezes' persistiu entre as chamadas!\n");
	return (0);
}

/*
** SAÍDA ESPERADA:
** =================================
** Esta função foi chamada 1 vez(es)
** Esta função foi chamada 2 vez(es)
** Esta função foi chamada 3 vez(es)
** Esta função foi chamada 4 vez(es)
** Esta função foi chamada 5 vez(es)
**
** Se 'vezes' fosse uma variável local normal (sem static),
** sempre imprimiria "1 vez(es)" porque seria reinicializada a cada chamada.
*/
