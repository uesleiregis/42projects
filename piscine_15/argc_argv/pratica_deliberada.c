
// Mostrar argc

#include <stdio.h>

int main(int argc, char *argv[])
{
	// Quantos argumentos no terminal?
	printf("%d argumentos.\n\n", argc);

	// Quais argumentos foram passados no terminal?
	//printf("Os argumentos sao: %d", argv);
	char **p = argv;
	int i= 1;
	while(*p)
	{
		printf("%dº argumento: %s. \n",i,*p);	
		p++;
		i++;
	}
	printf("\n");

	// Outra forma de listar os argumentos.
	i=1;
	while(i<=argc)
	{
		printf("%dº argumento eh: %s. \n", i, argv[i-1]);
		i++;
	}

	return (0);
}
