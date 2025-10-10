#include<stdio.h>

int main(int argc, char *argv[])
 {
	int i=0;
	printf("Quantidade de argumentos: %d\n", argc);
	while(i<argc)
	{
		printf("%dº argumento eh: %s \n",i+1 ,argv[i]);
		i++;
	}
	return 0;
}
