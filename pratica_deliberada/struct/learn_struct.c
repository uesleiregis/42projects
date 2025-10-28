// Learning Struct Examples

#include <stdio.h>
#include <string.h>
int main(void)
{

	// Ex1:
	struct Pessoa
	{
		char	nome[50];
		int	idade;
		float	altura;
	};

	struct Pessoa p1 = {"Maria", 26, 1.60};

	printf("%s", p1.nome);

	strcpy(p1.nome, "José");

	printf("%s", p1.nome);


	// Ex2:
	struct Ponto
	{
		int	x;
		int	y;
	};
	return (0);
}
