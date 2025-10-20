#include "libft.a"

char	*ft_strchr(const char *str, int c)
{
	char	*p;

	p =(char *)str;
	while(*p)
	{
		if(*p ==(char)c)
			return (p);
		p++;
	}
	if((char)c == '\0' )
		return (p);
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char *world = "que coisa mais linda mais cheia de graça";

	printf("%s\n",ft_strchr(world, 'c'));
	return (0);
}
*/
