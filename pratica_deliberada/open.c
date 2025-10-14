
#include <fcntl.h> // para open()
#include <unistd.h> // para close() e write()

#include <stdio.h> // para printf

int main()
{
	int fd;

	fd = open("text.txt", O_RDONLY); // abre só para leitura
	
	if (fd == -1)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}
	printf("Arquivo aberto com sucesso! Descritor: %d\n", fd);
	close(fd); 

	return (0);
}
