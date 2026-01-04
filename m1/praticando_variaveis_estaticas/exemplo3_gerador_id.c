/* ************************************************************************** */
/*                                                                            */
/*   Exemplo 3: Gerador de ID único (uso prático)                             */
/*                                                                            */
/*   Um exemplo real: gerar IDs únicos para cada usuário criado               */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	gerar_id(void)
{
	static int	proximo_id = 1000;  // Começa em 1000

	return (proximo_id++);  // Retorna o valor atual e depois incrementa
}

void	criar_usuario(char *nome)
{
	int	id;

	id = gerar_id();
	printf("Usuário criado: %s (ID: %d)\n", nome, id);
}

int	main(void)
{
	printf("=== Sistema de Cadastro com ID Automático ===\n\n");
	
	criar_usuario("Alice");
	criar_usuario("Bob");
	criar_usuario("Carlos");
	criar_usuario("Diana");
	criar_usuario("Eduardo");
	
	printf("\n");
	printf("Cada usuário recebeu um ID único!\n");
	printf("A variável estática 'proximo_id' lembra o último valor usado.\n");
	return (0);
}

/*
** SAÍDA ESPERADA:
** =======================================
** Usuário criado: Alice (ID: 1000)
** Usuário criado: Bob (ID: 1001)
** Usuário criado: Carlos (ID: 1002)
** Usuário criado: Diana (ID: 1003)
** Usuário criado: Eduardo (ID: 1004)
**
** RESUMO - Variáveis Estáticas:
** =============================
** 1. São inicializadas apenas UMA vez (na primeira execução)
** 2. MANTÊM seu valor entre chamadas da função
** 3. Têm ESCOPO LOCAL (só acessíveis dentro da função)
** 4. Têm TEMPO DE VIDA GLOBAL (existem durante todo o programa)
** 5. Se não inicializadas, começam com 0 (diferente de locais normais)
*/
