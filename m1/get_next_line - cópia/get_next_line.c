
#include "get_next_line.h"

//cc get_next_line.c -Wall -Wextra -Werror -D BUFFER_SIZE=42


// fd = open("text.txt", O_RDONLY);


char *get_next_line(int fd)
{
	static char	*resto;			//para salvar o que sobrou da última leitura
	char		*buffer;		// área temporária de leitura
	char		*linha;			// o que será retornado
	ssize_t		bytes;			// nº de bytes lidos em cada read()
	int			i;
	char		*temp;

	// 1 - validação
	if(fd < 0 || BUFFER_SIZE <= 0) // >> quando falha a abertura do arquivo... 
		return (NULL);//... open() retorna um file descriptor negativo (-1)

	// 2 - Alocar memória para o buffer temporário.

	buffer = malloc(BUFFER_SIZE + 1);
	if(!buffer)
		return (NULL);
	
	// bytes = read(fd, buffer, BUFFER_SIZE);
	
	// loop de leitura
	while((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0'; // transforma em string válida
		temp = ft_strjoin(resto, buffer); // Concatena com o que já tinha antes
		free(resto);
		resto = temp;

		if (ft_strchr(resto, '\n')) // Encontrou uma linha completa?
			break;					// Sai do loop
	}

	// Depois do loop, verifica:
	if (bytes < 0) // Erro na leitura
		{
			free(buffer);
			return (NULL);
		}
	if (bytes == 0 && !resto) // EOF não tem mais conteúdo
	{
		free(buffer);
		return (NULL);
	}
	if (bytes == 0 && resto[0] == '\0') // resto existe mas está vazio
	{
		free(buffer);
		free(resto);
		resto = NULL;
		return (NULL);
	}

	// 4 Encontrando onde termina a primeira linha
	i = 0;
	while (resto[i] && resto[i] != '\n')
		i++;

	// 5 Se encontrar o \n adicionar ele na linha.
	if (resto[i] == '\n')
		i++;

	// 6 Extrair a linha do início até i
	linha = ft_strndup(resto, i);
	
	// 7 Atualizar o resto (o que sobrou após a linha)

	temp = ft_strdup(resto + i); // Copiando o resto após a linha
	free(resto); // Libera o resto antigo
	resto = temp; // resto agora aponta para o que sobrou
					// basta apontar (:-))
	free(buffer);
	return (linha);
}
