#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 42

//cc get_next_line.c -Wall -Wextra -Werror -D BUFFER_SIZE=42

int ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

// fd = open("text.txt", O_RDONLY);


char *get_next_line(int fd)
{
	static char	*resto;			//para salvar o que sobrou da última leitura
	char		*buffer;		// área temporária de leitura
	char		*linha;			// o que será retornado
	ssize_t		bytes;			// nº de bytes lidos em cada read()

	// 1 - validação
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// 2 - Alocar memória para o buffer temporário.

	buffer = malloc(BUFFER_SIZE + 1);





	return ();
}
