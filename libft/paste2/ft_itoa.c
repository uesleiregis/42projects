#include "libft.h"
char	*ft_itoa(int n)
{
	char	*res;
	int	size;
	int	signal;
	int	n2;
	int	i;
	int	end;

	size = 0;
	i = 0;
	signal = 0;
	n2 = n;
	if (n < 0)
	{
		signal = 1;
		n *= (-1);
	}
	while (n/10 >  0)
	{
		n /= 10;
		size++;
	}
	res = malloc((size + signal + 1)*sizeof(char));
	if(!res)
		return(NULL);
	end = size + signal + 1;
	while (i <= end)
 	{
		res[end--] = (n2 % 10) + '0';
		n2 /= 10;
	}
	
		
	return (res);
}
#include <stdio.h>
int main()
{
	printf("%s\n", ft_itoa(124));
	return (0);
}
