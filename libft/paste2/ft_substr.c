#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	char	*p;

	if(!s)
		return (NULL);

	p = (char *)malloc(sizeof(char)*(len + 1));
	if(!p)
		return (NULL);
	str = (char *)s;
	str += (char *)(s + start);
	i = 0;
	while(str[i] && i < len)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int main()
{

	return (0);
}
