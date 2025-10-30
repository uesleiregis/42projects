// Learning Struct Examples

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int main(void)
{
	// Criando 3 nós;

	t_list	*no1;
	t_list	*no2;
	t_list	*no3;
	
	no1 = malloc(sizeof (t_list));
	no2 = malloc(sizeof (t_list));
	no3 = malloc(sizeof (t_list));

	// Dados para armazenar
	int a = 10, b = 20, c = 30;

	// Atribuir os conteúdos
	no1 -> content = &a;
	no1 -> content = &b;
	no3 -> content = &c;

	// Ligar os nós;

	no1 -> next = no2;
	no2 -> next = no3;
	no3 -> next = NULL;

	// Percorrer e imprimir a lista
	t_list *current = no1;
	while(!current)
	{
		printf("%d",*(int *)(current -> content));
		current = current -> next;
	}


	// Liberar memória
	free(no1);
	free(no2);
	free(no3);
 
	return (0);
}