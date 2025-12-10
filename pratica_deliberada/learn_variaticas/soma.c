# include <stdarg.h>
int soma(int n, ...)
{
	va_list	args;
	int		i;
	int		sum;

	sum = 0;
	i = 0;
	va_start(args, n);
	while(i < n)
	{
		sum += va_arg(args, int);
		i++;
	}
	return (sum);
}
# include <stdio.h>
int main(void)
{
	printf("%d", soma(3, 2 , 5, 6));
	return (0);
}