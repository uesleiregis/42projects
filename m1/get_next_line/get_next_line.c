#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include <string.h>

#define BUFFER_SIZE 42

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int ft_strlen(char const *str);
static char	*ft_strndup(const char *s, const unsigned int n)


//cc get_next_line.c -Wall -Wextra -Werror -D BUFFER_SIZE=42


// fd = open("text.txt", O_RDONLY);


char *get_next_line(int fd)
{
	static char	*resto;			//para salvar o que sobrou da última leitura
	char		*buffer;		// área temporária de leitura
	char		*linha;			// o que será retornado
	ssize_t		bytes;			// nº de bytes lidos em cada read()
	int			i;

	i = 0;
	// 1 - validação
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// 2 - Alocar memória para o buffer temporário.

	buffer = malloc(BUFFER_SIZE + 1);
	if(!buffer)
		return (NULL);
	
	bytes = read(fd, buffer, BUFFER_SIZE + 1);

	while(buffer[i] && buffer[i] != '\n')
		i++;
	
	linha = ft_strndup(buffer[0], i);
	
	
	return (linha);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_src;

	size_src = 0;
	while (src[size_src])
		size_src++;
	if (size == 0)
		return (size_src);
	i = 0;
	while (src[i] && (i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size_src);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc((ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1));
	if (!str)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
int ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int static	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Retorna uma nova string com apenas os n primeiros caracteres
// copiados + \0.
static char	*ft_strndup(const char *s, const unsigned int n)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (n + 1));
	if (p == NULL)
		return (NULL);
	while (s[i] && i < n)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}