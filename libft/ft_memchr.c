#include "libft.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
	char *str;
	size_t i;

	i = 0;
	str = (unsigned char *)s;
	while(i < n)
	{
		if(str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

#include <stdio.h>
int main()
{
	// nao estou certo se a main está correta.
	const char *str = "Olá Mundo";
	char caractere_procurado = 'M';

	char *res = ft_memchr(str, caractere_procurado, 5);

	if(res)
		printf("%c\n", *res);
	else
		printf("Caractere não encontrado\n");

	return (0);
}
