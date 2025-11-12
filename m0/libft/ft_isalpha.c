
int ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_isalpha(66));
	return (0);
}
*/
