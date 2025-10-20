#include "libft.h"
char	*strrchr(const char *str, int c)
{
	char	*p;
	char	*res;

	res = NULL;
	p = (char *)str;
	while(*p)
	{
		if(*p == (char)c)
		res = p;	
		p++;
	}
	if( (char)c == '\0')
		return (p);
	return (res);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%s",strrchr("mamae eu quero", 'm'));
// 	return (0);
// }